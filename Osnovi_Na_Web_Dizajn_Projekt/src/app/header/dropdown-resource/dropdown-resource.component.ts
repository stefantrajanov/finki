import { Component, HostListener } from '@angular/core';
import * as AOS from 'aos';
import { HeaderService } from 'src/app/services/header.service';

@Component({
  selector: 'app-dropdown-resource',
  templateUrl: './dropdown-resource.component.html',
  styleUrls: ['./dropdown-resource.component.scss']
})
export class DropdownResourceComponent {
  isMobile: boolean = false

  ngOnInit(){
    AOS.init();

    this.checkScreenSize();

  }

  constructor(public headerService: HeaderService) { }

  @HostListener('window:resize', ['$event'])
  onResize(event) {
    this.checkScreenSize();
  }

  checkScreenSize(){
    this.isMobile = window.innerWidth < 768;
  }

  onBack(){
    this.headerService.closeProductsDropdown();
    this.headerService.closeResourcesDropdown();
  }
}
