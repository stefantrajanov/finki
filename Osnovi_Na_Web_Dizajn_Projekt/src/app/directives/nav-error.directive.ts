import { Directive,  HostListener } from '@angular/core';

@Directive({
  selector: 'a[href="#"]'
})
export class NavErrorDirective {

  @HostListener('click', ['$event'])
  onClick(event: Event): void {
    event.preventDefault();
  }

}
