import { Component } from '@angular/core';
import { AuthenticationService } from 'src/app/services/authentication.service';

@Component({
  selector: 'app-reset-password',
  templateUrl: './reset-password.component.html',
  styleUrls: ['./reset-password.component.scss']
})
export class ResetPasswordComponent {
  email: string = '';
  error: string = '';

  constructor(private authService: AuthenticationService) {}

  onResetPassword() {
    this.authService.resetPassword(this.email).subscribe((response) => {
      
    });

    this.error = 'A reset password link has been sent to your email, please check your inbox.';
  }
}
