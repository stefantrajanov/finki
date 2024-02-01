import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

interface serverResponse {
  domain: string,
  zone: string,
  status: string,
  summary: string,
}

interface serverResponseArray {
  status: serverResponse[],
}

interface similarDomain{
  domain: string,
  host: string,
  subdomain: string,
  zone: string,
  path: string,
  registerURL: string,
}

interface similarDomainArray{
  results: similarDomain[],
}

@Injectable({
  providedIn: 'root'
})

export class DomainCheckerService {

  constructor(private httpClient: HttpClient) { }


  checkDomain(domain: string) {
    return this.httpClient.get<serverResponseArray>(`https://domainr.p.rapidapi.com/v2/status?mashape-key=b60f503a58mshc0d4193208cf660p13e849jsn37a08c9401a9&domain=${domain}`);
  }

  getSimilarDomains(domain: string) {
    return this.httpClient.get<similarDomainArray>(`https://domainr.p.rapidapi.com/v2/search?mashape-key=b60f503a58mshc0d4193208cf660p13e849jsn37a08c9401a9&query=${domain}`);
  }
  
}
