import { CanActivate, ActivatedRouteSnapshot,RouterStateSnapshot,Router,UrlTree} from '@angular/router';
  import { Injectable } from '@angular/core';
  import { Observable } from 'rxjs';
  import { map, tap, take } from 'rxjs/operators';  
import { AuthenticationService } from './authentication.service';

@Injectable({ providedIn: 'root' })
export class AuthGuard implements CanActivate {
  constructor(private authService: AuthenticationService, private router: Router) {}

  canActivate(  route: ActivatedRouteSnapshot,  router: RouterStateSnapshot): | boolean | UrlTree | Promise<boolean | UrlTree> | Observable<boolean | UrlTree> {
      if (this.authService.userIsLoggedIn) {
          return this.router.createUrlTree(['/']);
      }else{
          return true;
      }
  }
}
  