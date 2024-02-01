import { Component } from '@angular/core';
import { NgForm } from '@angular/forms';
import { AuthenticationService } from 'src/app/services/authentication.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent {
  email: string = '';
  password: string = '';

  error: string = '';


  constructor(private authService: AuthenticationService) { }
  
  onSubmit(form: NgForm){
    

    this.authService.logIn(this.email, this.password).subscribe(
      response => {
        console.log(response);
      },
      errorMessage => {
        console.log(errorMessage);
        this.error = errorMessage;
    });


    form.reset();
  }
}
