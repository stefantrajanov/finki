import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import { catchError, tap } from 'rxjs/operators';
import { Subject, throwError } from 'rxjs';
import { User } from '../auth/user.model';
import { Router } from '@angular/router';
import firebase from 'firebase/compat/app';

interface AuthResponseData {
  idToken: string,
  email: string,
  refreshToken: string,
  expiresIn: string,
  localId: string,
  registered?: boolean,
}

@Injectable({
  providedIn: 'root'
})
export class AuthenticationService {

  user = new Subject<User>();
  userIsLoggedIn: boolean = false;
  private tokenExpirationTimer: any;

  constructor(private http: HttpClient, private auth: AngularFireAuth, private router: Router) { }

  signUp(email: string, password: string){

    let userData = {
      email: email,
      password: password,
      returnSecureToken: true,
    }

    return this.http.post<AuthResponseData>('https://identitytoolkit.googleapis.com/v1/accounts:signUp?key=AIzaSyAUcQgdr3jgkaf-oZgpMVtCzzRpwlvLZ7Q',
    userData)
    .pipe(catchError(errorResponse => {
      let errorMessage = 'An unknown error occurred!';

      if (!errorResponse.error ||  !errorResponse.error.error) {
        return throwError(errorMessage);
      }
      switch (errorResponse.error.error.message) {
        case 'EMAIL_EXISTS':
          errorMessage = 'This email exists already!';
          break;
      }

      return throwError(errorMessage);
    }), tap(responseData => {
      this.handleAuthentication(responseData.email, responseData.localId, responseData.idToken, +responseData.expiresIn);
    }));
  }

  private handleAuthentication(email: string, userId: string, token: string, expiresIn: number){
    const expirationDate = new Date(new Date().getTime() + expiresIn * 1000);

    const user = new User(email, userId, token, expirationDate);

    this.user.next(user);
    this.autoLogout(expiresIn * 1000);

    this.userIsLoggedIn = true;

    localStorage.setItem('userData', JSON.stringify(user));

    this.sendEmailVerification(token).subscribe(response => {
      console.log(response);
    });

    this.router.navigate(['/templates']);
  }

  private sendEmailVerification(idToken: string) {
    let data = {
      requestType: 'VERIFY_EMAIL',
      idToken: idToken
    }

    return this.http.post('https://identitytoolkit.googleapis.com/v1/accounts:sendOobCode?key=AIzaSyAUcQgdr3jgkaf-oZgpMVtCzzRpwlvLZ7Q', data);
  }

  logIn(email: string, password: string){

    let userData = {
      email: email,
      password: password,
      returnSecureToken: true,
    }

    return this.http.post<AuthResponseData>('https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=AIzaSyAUcQgdr3jgkaf-oZgpMVtCzzRpwlvLZ7Q', userData)
    .pipe(catchError(errorResponse => {
      let errorMessage = 'An unknown error occurred!';

      if (!errorResponse.error ||  !errorResponse.error.error) {
        return throwError(errorMessage);
      }
      switch (errorResponse.error.error.message) {
        case 'EMAIL_NOT_FOUND':
          errorMessage = 'This email does not exist, please register!';
          break;
        case 'INVALID_PASSWORD':
          errorMessage = 'This password/email you specified does not match our credentials.';
          break;
        case 'USER_DISABLED':
          errorMessage = 'This user has been disabled.';
          break;
      }

      return throwError(errorMessage);
    }), tap(responseData => {
      this.handleAuthentication(responseData.email, responseData.localId, responseData.idToken, +responseData.expiresIn);
    }));
  }

  autoLogin(){
    const userData: {
      email: string,
      id: string,
      _token: string,
      _tokenExpirationDate: string,
    } = JSON.parse(localStorage.getItem('userData'));

    if (!userData) {
      return;
    }

    const loadedUser = new User(userData.email, userData.id, userData._token, new Date(userData._tokenExpirationDate));

    if (loadedUser.token){
      this.user.next(loadedUser);
      this.userIsLoggedIn = true;

      this.autoLogout(new Date(userData._tokenExpirationDate).getTime() - new Date().getTime());
    }

  }

  logOut(){
    this.user.next(null);
    this.userIsLoggedIn = false;
    localStorage.removeItem('userData');

    if (this.tokenExpirationTimer) {
      clearTimeout(this.tokenExpirationTimer);
    }

    this.tokenExpirationTimer = null;

    this.router.navigate(['auth/login']);
  }

  autoLogout(expirationDuration: number){
    this.tokenExpirationTimer = setTimeout(() => {
      this.logOut();
    }, expirationDuration);
  }

  resetPassword(email: string){
    let data = {
      requestType: 'PASSWORD_RESET',
      email: email,
    }

    return this.http.post('https://identitytoolkit.googleapis.com/v1/accounts:sendOobCode?key=AIzaSyAUcQgdr3jgkaf-oZgpMVtCzzRpwlvLZ7Q', data);
  }
}
