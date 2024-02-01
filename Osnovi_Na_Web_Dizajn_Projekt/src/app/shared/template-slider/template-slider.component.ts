import { Component, OnInit } from '@angular/core';
import { trigger, transition, style, animate, useAnimation } from "@angular/animations";
import {
  fadeIn,
  fadeOut,
} from "../animations/carousel.animations";
import * as AOS from 'aos';
import { Router } from '@angular/router';

@Component({
  selector: 'app-template-slider',
  templateUrl: './template-slider.component.html',
  styleUrls: ['./template-slider.component.scss'],
  animations: [
    trigger("carouselAnimation", [
      transition("void => *", [useAnimation(fadeIn, {params: { time: '500ms' }} )]),
      transition("* => void", [useAnimation(fadeOut, {params: { time: '500ms' }})]),
    ])
  ]
})
export class TemplateSliderComponent implements OnInit{
  isMobile: boolean = false;
  slides: {src: string, filePath: string}[] = [];
  
  constructor(private router: Router) { }

  ngOnInit(): void {
    if (window.innerWidth < 768) {
      this.isMobile = true;

      this.slides = [
        { src: "assets/slider/global-template-thumbnail-mobile.png", filePath:"assets/templates/Portfolio/global-template/index.html"},
        { src: "assets/slider/brainwave-template-thumbnail-mobile.png",  filePath:"assets/templates/Art-Design/brainwave-template/index.html"},
        { src: "assets/slider/photosec-template-thumbnail-mobile.png", filePath:"assets/templates/Photography/photosec-template/index.html" },
        { src: "assets/slider/chocolux-template-thumbnail-mobile.png", filePath:"assets/templates/Business/chocolux-template/index.html" }
      ];
    }else{
      this.isMobile = false;

      this.slides = [
        { src: "assets/slider/global-template-thumbnail.png", filePath:"assets/templates/Portfolio/global-template/index.html"},
        { src: "assets/slider/brainwave-template-thumbnail.png",  filePath:"assets/templates/Art-Design/brainwave-template/index.html"},
        { src: "assets/slider/photosec-template-thumbnail.png", filePath:"assets/templates/Photography/photosec-template/index.html" },
        { src: "assets/slider/chocolux-template-thumbnail.png", filePath:"assets/templates/Business/chocolux-template/index.html" }
      ];
    }
  }

  

  currentSlide = 0;


  onPreviousClick() {
    const previous = this.currentSlide - 1;
    this.currentSlide = previous < 0 ? this.slides.length - 1 : previous;
    console.log("previous clicked, new current slide is: ", this.currentSlide);
  }

  onNextClick() {
    const next = this.currentSlide + 1;
    this.currentSlide = next === this.slides.length ? 0 : next;
    console.log("next clicked, new current slide is: ", this.currentSlide);
  }

  loadPreview(filePath: string): void {
    // Navigate to the preview route with the file path as a parameter
    this.router.navigate(['/preview'], { queryParams: { templateUrl: filePath } });
  }
}
