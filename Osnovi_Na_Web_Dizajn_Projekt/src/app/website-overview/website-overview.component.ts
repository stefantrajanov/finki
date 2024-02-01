import { Component, OnInit } from '@angular/core';
import * as AOS from 'aos';

@Component({
  selector: 'app-website-overview',
  templateUrl: './website-overview.component.html',
  styleUrls: ['./website-overview.component.scss']
})
export class WebsiteOverviewComponent implements OnInit {

  ngOnInit(): void {
    AOS.init();
  }
}
