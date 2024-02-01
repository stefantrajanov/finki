import { Component, OnInit } from '@angular/core';
import * as AOS from "aos";
@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.scss']
})
export class HomeComponent implements OnInit {
  isMobile: boolean = false;

  ngOnInit(): void {
    AOS.init();

    // check if mobile
    this.isMobile = window.innerWidth <= 768;
  }
}
