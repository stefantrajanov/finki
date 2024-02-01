import { Component } from '@angular/core';
import { DomainCheckerService } from '../services/domain-checker.service';

@Component({
  selector: 'app-hosting-guide',
  templateUrl: './hosting-guide.component.html',
  styleUrls: ['./hosting-guide.component.scss']
})
export class HostingGuideComponent {

  domain: string = '';
  similarDomains: {domain: string, registerURL: string}[] = [];
  showDropdown: boolean = false; 
  isAvailable: boolean = false;
  isUnavailable: boolean = false;

  constructor(private domainChecker: DomainCheckerService) { }


  onCheckDomain() {
    let serverResponse: any = [];
    this.domainChecker.checkDomain(this.domain).subscribe((response) => {
      if (response.status[0].status === 'undelegated inactive'){
        this.isAvailable = true;
        this.isUnavailable = false;
      }else{
        this.isAvailable = false;
        this.isUnavailable = true;
      };

      this.domainChecker.getSimilarDomains(this.domain).subscribe((response) => {
        serverResponse = response.results;
       
        this.similarDomains = serverResponse.map(item => ({
          domain: item.domain,
          registerURL : item.registerURL,
        }));
      });
      this.showDropdown = true; // Show the dropdown
    })
  }
}
