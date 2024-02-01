import { trigger, state, style, transition, animate } from '@angular/animations';
import { Component, ElementRef, HostListener, OnInit, Renderer2, OnDestroy} from '@angular/core';
import { ActivatedRoute, NavigationEnd, Router } from '@angular/router';
import { filter } from 'rxjs/operators';
import { AuthenticationService } from '../services/authentication.service';
import { Subscription } from 'rxjs';
import { HeaderService } from '../services/header.service';


@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.scss'],
  animations: [
    trigger('fadeInOut', [
      state('void', style({ opacity: 0 })), // Initial state when element is not present
      state('*', style({ opacity: 1 })),    // Final state when element is present
      transition(':enter, :leave', [
        animate('0.3s ease-in-out') // Animation duration and easing
      ])
    ])
  ],
})
export class HeaderComponent implements OnInit{
  isScrolled = false;
  hamburgerToggled = false;

  isTemplatesRoute: boolean = true;
  isAuthenticated: boolean = false;

  isMobile: boolean = false;
  private userSub: Subscription;

  constructor(private router: Router, public headerService: HeaderService, private authService: AuthenticationService){}

  @HostListener('window:resize', ['$event'])
  onResize(event) {
    this.checkScreenSize();
  }

  ngOnInit(): void {
    this.isAuthenticated = this.authService.userIsLoggedIn;
    this.checkScreenSize();

    

    this.router.events
      .pipe(filter((event): event is NavigationEnd => event instanceof NavigationEnd))
      .subscribe((event: NavigationEnd) => {
        this.isTemplatesRoute = event.url.includes('templates') || event.url.includes('/preview');
        this.headerService.closeProductsDropdown();
        this.headerService.closeResourcesDropdown();
      });
  }

  @HostListener('window:scroll', ['$event'])
  onScroll(event: Event) {
    const scrollTop = window.scrollY || window.pageYOffset;
  
    const threshold = 100;
  
    if (scrollTop > threshold) {
      this.isScrolled = true;
    } else {
      this.isScrolled = false;
    }

    if (this.isTemplatesRoute && !this.isMobile){
      this.headerService.closeProductsDropdown();
      this.headerService.closeResourcesDropdown();
    }
  }

  onLogout(){
    this.authService.logOut();
    this.isAuthenticated = this.authService.userIsLoggedIn;
  }

  onToggle(){
    if (this.headerService.resourcesToggle){
      this.headerService.resourcesToggle = false;
    }
    
    this.headerService.productsToggle = !this.headerService.productsToggle;
    this.hamburgerToggled = false;
  }

  onResourceToggle(){
    if (this.headerService.productsToggle){
      this.headerService.productsToggle = false;
    }

    this.headerService.resourcesToggle = !this.headerService.resourcesToggle;
    this.hamburgerToggled = false;
  }

  onHamburgerClick(){
    this.hamburgerToggled = !this.hamburgerToggled;
  }

  checkScreenSize(){
    this.isMobile = window.innerWidth <= 768;
  }
}
