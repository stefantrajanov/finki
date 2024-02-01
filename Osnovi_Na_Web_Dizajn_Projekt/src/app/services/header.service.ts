import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class HeaderService {
  productsToggle = false;
  resourcesToggle = false;


  closeProductsDropdown(){
    this.productsToggle = false;
  }

  openProductsDropdown(){
    this.productsToggle = true;
  }

  closeResourcesDropdown(){
    this.resourcesToggle = false;
  }

  openResourcesDropdown(){
    this.resourcesToggle = true;
  }

  constructor() { }
}
