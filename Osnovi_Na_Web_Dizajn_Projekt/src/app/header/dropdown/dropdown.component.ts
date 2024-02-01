import { Component, OnInit, HostListener } from '@angular/core';
import { Router } from '@angular/router';
import * as AOS from 'aos';
import { HeaderService } from 'src/app/services/header.service';

@Component({
  selector: 'app-dropdown',
  templateUrl: './dropdown.component.html',
  styleUrls: ['./dropdown.component.scss']
})
export class DropdownComponent implements OnInit{
  isMobile : boolean = false;


  @HostListener('window:resize', ['$event'])
  onResize(event) {
    this.checkScreenSize();
  }

  checkScreenSize(){
    this.isMobile = window.innerWidth < 768;
  }

  constructor(private router: Router, public headerService: HeaderService) { }

  ngOnInit(){
    AOS.init();

    this.checkScreenSize();
  }

  navigateToTemplates(category: string) {
    // Navigate to the /templates route and pass the category as a query parameter
    this.router.navigate(['/templates'], { queryParams: { load: category } });
  }

  onBack(){
    this.headerService.closeProductsDropdown();
    this.headerService.closeResourcesDropdown();
  }
}
