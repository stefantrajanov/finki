import { Component } from '@angular/core';
import { NgForm } from '@angular/forms';
import { AuthenticationService } from 'src/app/services/authentication.service';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})
export class RegisterComponent {
  email: string = '';
  password: string = '';
  confirmPassword: string = '';

  error: string = 'After signup, please check your email for a verification link.';

  constructor(public authenticationService: AuthenticationService) { }

  onSubmit(form: NgForm){
    if (!form.valid) {
      return;
    }

    if (this.password !== this.confirmPassword) {
      this.error = 'Passwords do not match.';
      return;
    }

    this.error  = 'After signup, please check your email for a verification link.';

    this.authenticationService.signUp(this.email, this.password).subscribe(response => {
      console.log(response);
      this.error = '';
    }, errorMessage => {
      console.log(errorMessage);
      this.error = errorMessage;
    });

    form.reset();
  }
}
