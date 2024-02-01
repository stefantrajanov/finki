import { Component, OnInit } from '@angular/core';
import { trigger, transition, animate, style } from '@angular/animations';
import * as AOS from 'aos';

interface ImageMap {
  [key: string]: string;
}

@Component({
  selector: 'app-template-catalog',
  templateUrl: './template-catalog.component.html',
  styleUrls: ['./template-catalog.component.scss'],
  animations: [
    trigger('fadeIn', [
      transition(':enter', [
        style({ transform: 'translateY(20px)', opacity: 0 }),
        animate('0.5s ease-in-out', style({ transform: 'translateY(0)', opacity: 1 }))
      ]),
    ]),
  ],
})
export class TemplateCatalogComponent implements OnInit{
  options = ['Portfolio', 'Blog', 'Restaurant', 'Services', 'Personal'];
  selectedOption: string = this.options[0]; // Default selected option
  showImage = false;
  activeImageIndex = 0;
  fadeInState: boolean = false;
  isMobile: boolean = false;

  private imageIndex = 0;
  private interval: any; // To store the interval ID

  constructor () { }

  images: ImageMap = {
    Portfolio: '../../assets/images/portfolio.png',
    Blog: '../../assets/images/good-food.png',
    Restaurant: '../../assets/images/restoran.png',
    Services: '../../assets/images/service.png',
    'Personal': '../../assets/images/One-Page-Portfolio.png'
  };

  ngOnInit(): void {
    // Start the image shuffling
    this.startImageShuffling();
    AOS.init();
    // check if mobile
    this.isMobile = window.innerWidth <= 768;
  }

  startImageShuffling(): void {
    this.interval = setInterval(() => {
      // this.fadeInState = true;
      this.imageIndex = (this.imageIndex + 1) % this.options.length;
      this.selectedOption = this.options[this.imageIndex];
      this.loadImage(this.selectedOption, this.imageIndex);
    }, 3000);
     // Adjust the interval time in milliseconds
  }

  private stopImageShuffling(): void {
    clearInterval(this.interval);
  }


  get selectedImage(): string {
    return this.images[this.selectedOption];
  }

  selectOption(option: string): void {
    this.selectedOption = option;
  }

  loadImage(option: string, index: number, flag: boolean = false): void {
    if (flag) {
      this.stopImageShuffling(); // Stop shuffling when hovering over a list item
    }
    this.selectedOption = option;
    this.showImage = true;
    this.activeImageIndex = index;
    // this.fadeInState = true; // Activate the fadeIn animation
  }
}
