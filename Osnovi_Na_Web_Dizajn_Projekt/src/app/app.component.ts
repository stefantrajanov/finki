import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, NavigationEnd, Router } from '@angular/router';
import { filter } from 'rxjs/operators';
import { AuthenticationService } from './services/authentication.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  title = 'skillpix';
  hideHeaderAndFooter: boolean = false;

  constructor(private router: Router, private activatedRoute: ActivatedRoute, private authService: AuthenticationService) {
    this.router.events
      .pipe(filter((event): event is NavigationEnd => event instanceof NavigationEnd))
      .subscribe((event: NavigationEnd) => {
        // Check if the current route is 'preview'
        this.hideHeaderAndFooter = event.url.includes('preview') || event.url.includes('auth');
      });
  }

  ngOnInit(): void {
    this.authService.autoLogin();
  }
}
