import { CanActivate, Router, UrlTree } from '@angular/router';
import { Injectable } from '@angular/core';
import { AuthenticationService } from './authentication.service';

@Injectable({ providedIn: 'root' })
export class PreviewGuard implements CanActivate {
  constructor(private authService: AuthenticationService, private router: Router) {}

  canActivate(): boolean | UrlTree {
    if (this.authService.userIsLoggedIn) {
      // User is logged in, allow access to the preview route
      return true;
    } else {
      // User is not logged in, prevent access to the preview route
      return this.router.createUrlTree(['/auth/login']); // Redirect to the login page or another route
    }
  }
}