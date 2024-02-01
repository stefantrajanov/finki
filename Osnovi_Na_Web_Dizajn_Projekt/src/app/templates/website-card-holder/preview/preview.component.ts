import { Component, Input, OnInit } from '@angular/core';
import { DomSanitizer, SafeResourceUrl } from '@angular/platform-browser';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-preview',
  templateUrl: './preview.component.html',
  styleUrls: ['./preview.component.scss']
})
export class PreviewComponent implements OnInit{
  @Input() templateUrl: string = '';
  filePathUrl: SafeResourceUrl = '';
  currentView: 'mobile' | 'tablet' | 'desktop' = 'desktop';
  isMobileView: boolean = false;

  constructor(private sanitizer: DomSanitizer, private route: ActivatedRoute) {  }

  ngOnInit(): void {
    this.route.queryParams.subscribe(params => {
      this.templateUrl = params['templateUrl'];
    });

    this.filePathUrl = this.sanitizer.bypassSecurityTrustResourceUrl(this.templateUrl);
  }

  changeView(view: 'mobile' | 'tablet' | 'desktop'): void {
    this.currentView = view;
    if (view == 'mobile'){
      this.isMobileView = true;
    }else{
      this.isMobileView = false;
    }
    // Update the filePathUrl based on the selected view
    // You can modify the filePathUrl based on the view here
  }
}
