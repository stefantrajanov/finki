import { Component, HostListener, Input, OnChanges, SimpleChange, SimpleChanges } from '@angular/core';

@Component({
  selector: 'app-scroll-indicator',
  templateUrl: './scroll-indicator.component.html',
  styleUrls: ['./scroll-indicator.component.scss']
})
export class ScrollIndicatorComponent{
  @Input() number: number = 1;
  @Input() threshold: number = 0;
  @Input() stop: number = 0;
  isFixed = false;

  @HostListener('window:scroll', [])
  onScroll(): void {
    const scrollPosition = window.scrollY || window.pageYOffset;

    this.isFixed = scrollPosition >= this.threshold && scrollPosition <= this.stop;
  }
}