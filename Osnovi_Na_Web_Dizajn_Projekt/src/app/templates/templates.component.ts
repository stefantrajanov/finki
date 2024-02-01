import { Component, OnInit} from '@angular/core';
import { WishListService } from '../services/wish-list.service';
import * as AOS from 'aos';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-templates',
  templateUrl: './templates.component.html',
  styleUrls: ['./templates.component.scss']
})
export class TemplatesComponent implements OnInit{
  currentTemplateCount: number = 93;
  filteredTemplates: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string, type: string; isLiked: boolean }[] = [];

  constructor(private wishListService: WishListService, private route: ActivatedRoute) { }

  types: { name: string; value: boolean }[] = [
    { name: "Blog", value: false },
    { name: "Service", value: false },
    { name: "One Page", value: false },
    { name: "Promotion", value: false },
  ]

  categories: { name: string; }[] = [
    { name: 'All Templates'},
    { name: 'Proffesional Services'},
    { name: 'Photography'},
    { name: 'Business'},
    { name: 'Portfolio'},
    { name: 'Beauty & Health' },
    { name: 'Art & Design'},
    { name: 'Restaurant & Cafe'},
    { name: 'Travel & Tourism'},
    { name: 'Music & Entertainment'},
    { name: 'Landing Pages'},
    { name: 'Event'},
    { name: 'Home'},
    { name: 'Fitness'},
    { name: 'Education'},
    { name: 'Animals & Nature'},
  ]

  allTemplates: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string, type: string; isLiked: boolean }[] = [
    { name: "Web Agency", filePath: "assets/templates/Business/esigned-template/index.html", donwloadPath: "assets/templates/Business/esigned-template/esigned-template-download.zip", imagePath: "assets/template-images/web-agency.png", category: 'Business', type: "Promotion", isLiked: false},

    // business
    { name: "Atlas", filePath: "assets/templates/Business/atlas-template/index.html", donwloadPath: "assets/templates/Business/atlas-template/atlas-template-download.zip", imagePath: "assets/template-images/atlas-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Chocolux", filePath: "assets/templates/Business/chocolux-template/index.html", donwloadPath: "assets/templates/Business/chocolux-template/chocolux-template-download.zip", imagePath: "assets/template-images/chocolux-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Dicetv", filePath: "assets/templates/Business/dicetv-template/index.html", donwloadPath: "assets/templates/Business/dicetv-template/dicetv-template-download.zip", imagePath: "assets/template-images/dicetv-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Digimedia", filePath: "assets/templates/Business/digimedia-template/index.html", donwloadPath: "assets/templates/Business/digimedia-template/digimedia-template-download.zip", imagePath: "assets/template-images/digimedia-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    

    { name: "Digital", filePath: "assets/templates/Business/digital-template/index.html", donwloadPath: "assets/templates/Business/digital-template/digital-template-download.zip", imagePath: "assets/template-images/digital-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},
    
    { name: "Fables", filePath: "assets/templates/Business/fables-template/index.html", donwloadPath: "assets/templates/Business/fables-template/fables-template-download.zip", imagePath: "assets/template-images/fables-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Fonicy", filePath: "assets/templates/Business/fonicy-template/index.html", donwloadPath: "assets/templates/Business/fonicy-template/fonicy-template-download.zip", imagePath: "assets/template-images/fonicy-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Goind", filePath: "assets/templates/Business/goind-template/index.html", donwloadPath: "assets/templates/Business/goind-template/goind-template-download.zip", imagePath: "assets/template-images/goind-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Gravitas", filePath: "assets/templates/Business/gravitas-template/index.html", donwloadPath: "assets/templates/Business/gravitas-template/gravitas-template-download.zip", imagePath: "assets/template-images/gravitas-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Hightech", filePath: "assets/templates/Business/hightech-template/index.html", donwloadPath: "assets/templates/Business/hightech-template/hightech-template-download.zip", imagePath: "assets/template-images/hightech-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},
    
    { name: "Honey", filePath: "assets/templates/Business/honey-template/index.html", donwloadPath: "assets/templates/Business/honey-template/honey-template-download.zip", imagePath: "assets/template-images/honey-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "JobPortal", filePath: "assets/templates/Business/jobportal-template/index.html", donwloadPath: "assets/templates/Business/jobportal-template/jobportal-template-download.zip", imagePath: "assets/template-images/jobportal-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Rent4u", filePath: "assets/templates/Business/rent4u-template/index.html", donwloadPath: "assets/templates/Business/rent4u-template/rent4u-template-download.zip", imagePath: "assets/template-images/rent4u-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Shapel", filePath: "assets/templates/Business/shapel-template/index.html", donwloadPath: "assets/templates/Business/shapel-template/shapel-template-download.zip", imagePath: "assets/template-images/shapel-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    { name: "Vertex", filePath: "assets/templates/Business/vertex-template/index.html", donwloadPath: "assets/templates/Business/vertex-template/vertex-template-download.zip", imagePath: "assets/template-images/vertex-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    // portfolio
    { name: "Benresume", filePath: "assets/templates/Portfolio/benresume-template/index.html", donwloadPath: "assets/templates/Portfolio/benresume-template/benresume-template-download.zip", imagePath: "assets/template-images/benresume-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Bloscot", filePath: "assets/templates/Portfolio/bloscot-template/index.html", donwloadPath: "assets/templates/Portfolio/bloscot-template/bloscot-template-download.zip", imagePath: "assets/template-images/bloscot-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Complex", filePath: "assets/templates/Portfolio/complex-template/index.html", donwloadPath: "assets/templates/Portfolio/complex-template/complex-template-download.zip", imagePath: "assets/template-images/complex-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Diffuso", filePath: "assets/templates/Portfolio/diffuso-template/index.html", donwloadPath: "assets/templates/Portfolio/diffuso-template/diffuso-template-download.zip", imagePath: "assets/template-images/diffuso-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Energy", filePath: "assets/templates/Portfolio/energy-template/index.html", donwloadPath: "assets/templates/Portfolio/energy-template/energy-template-download.zip", imagePath: "assets/template-images/energy-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Fregg", filePath: "assets/templates/Portfolio/fregg-template/index.html", donwloadPath: "assets/templates/Portfolio/fregg-template/fregg-template-download.zip", imagePath: "assets/template-images/fregg-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},
    
    { name: "Global", filePath: "assets/templates/Portfolio/global-template/index.html", donwloadPath: "assets/templates/Portfolio/global-template/global-template-download.zip", imagePath: "assets/template-images/global-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Joeblog", filePath: "assets/templates/Portfolio/joeblog-template/index.html", donwloadPath: "assets/templates/Portfolio/joeblog-template/joeblog-template-download.zip", imagePath: "assets/template-images/joeblog-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Johndoe", filePath: "assets/templates/Portfolio/johndoe-template/index.html", donwloadPath: "assets/templates/Portfolio/johndoe-template/johndoe-template-download.zip", imagePath: "assets/template-images/johndoe-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Mariaferro", filePath: "assets/templates/Portfolio/mariaferro-template/index.html", donwloadPath: "assets/templates/Portfolio/mariaferro-template/mariaferro-template-download.zip", imagePath: "assets/template-images/mariaferro-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Meyawo", filePath: "assets/templates/Portfolio/meyawo-template/index.html", donwloadPath: "assets/templates/Portfolio/meyawo-template/meyawo-template-download.zip", imagePath: "assets/template-images/meyawo-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Nanofolio", filePath: "assets/templates/Portfolio/nanofolio-template/index.html", donwloadPath: "assets/templates/Portfolio/nanofolio-template/nanofolio-template-download.zip", imagePath: "assets/template-images/nanofolio-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Steller", filePath: "assets/templates/Portfolio/steller-template/index.html", donwloadPath: "assets/templates/Portfolio/steller-template/steller-template-download.zip", imagePath: "assets/template-images/steller-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Triplep", filePath: "assets/templates/Portfolio/triplep-template/index.html", donwloadPath: "assets/templates/Portfolio/triplep-template/triplep-template-download.zip", imagePath: "assets/template-images/triplep-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Univers", filePath: "assets/templates/Portfolio/univers-template/index.html", donwloadPath: "assets/templates/Portfolio/univers-template/univers-template-download.zip", imagePath: "assets/template-images/univers-template-thumbnail.png", category: 'Portfolio', type: "Blog", isLiked: false},

    { name: "Digitalex", filePath: "assets/templates/Business/digitalex-template/index.html", donwloadPath: "assets/templates/Business/digitalex-template/digitalex-template-download.zip", imagePath: "assets/template-images/digitalex-template-thumbnail.png", category: 'Business', type: "Promotion", isLiked: false},

    //proffesional service

    { name: "4uhost", filePath: "assets/templates/Professional-Service/4uhost-template/index.html", donwloadPath: "assets/templates/Professional-Service/4uhost-template/4uhost-template-download.zip", imagePath: "assets/template-images/4uhost-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Atema", filePath: "assets/templates/Professional-Service/atema-template/index.html", donwloadPath: "assets/templates/Professional-Service/atema-template/atema-template-download.zip", imagePath: "assets/template-images/atema-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Carserv", filePath: "assets/templates/Professional-Service/carserv-template/index.html", donwloadPath: "assets/templates/Professional-Service/carserv-template/carserv-template-download.zip", imagePath: "assets/template-images/carserv-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Electrochip", filePath: "assets/templates/Professional-Service/electrochip-template/index.html", donwloadPath: "assets/templates/Professional-Service/electrochip-template/electrochip-template-download.zip", imagePath: "assets/template-images/electrochip-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Emailler", filePath: "assets/templates/Professional-Service/emailler-template/index.html", donwloadPath: "assets/templates/Professional-Service/emailler-template/emailler-template-download.zip", imagePath: "assets/template-images/emailler-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Foste", filePath: "assets/templates/Professional-Service/foste-template/index.html", donwloadPath: "assets/templates/Professional-Service/foste-template/foste-template-download.zip", imagePath: "assets/template-images/foste-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Greenhost", filePath: "assets/templates/Professional-Service/greenhost-template/index.html", donwloadPath: "assets/templates/Professional-Service/greenhost-template/greenhost-template-download.zip", imagePath: "assets/template-images/greenhost-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Hostit", filePath: "assets/templates/Professional-Service/hostit-template/index.html", donwloadPath: "assets/templates/Professional-Service/hostit-template/hostit-template-download.zip", imagePath: "assets/template-images/hostit-template-thumbnail.png", category: 'Proffesional Service', type: "Services", isLiked: false},

    { name: "Plumberz", filePath: "assets/templates/Professional-Service/plumberz-template/index.html", donwloadPath: "assets/templates/Professional-Service/plumberz-template/plumberz-template-download.zip", imagePath: "assets/template-images/plumberz-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Seomaster", filePath: "assets/templates/Professional-Service/seomaster-template/index.html", donwloadPath: "assets/templates/Professional-Service/seomaster-template/seomaster-template-download.zip", imagePath: "assets/template-images/seomaster-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},
    
    { name: "Seotech", filePath: "assets/templates/Professional-Service/seotech-template/index.html", donwloadPath: "assets/templates/Professional-Service/seotech-template/seotech-template-download.zip", imagePath: "assets/template-images/seotech-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Startup", filePath: "assets/templates/Professional-Service/startup-template/index.html", donwloadPath: "assets/templates/Professional-Service/startup-template/startup-template-download.zip", imagePath: "assets/template-images/startup-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    { name: "Troweld", filePath: "assets/templates/Professional-Service/troweld-template/index.html", donwloadPath: "assets/templates/Professional-Service/troweld-template/troweld-template-download.zip", imagePath: "assets/template-images/troweld-template-thumbnail.png", category: 'Proffesional Services', type: "Service", isLiked: false},

    // restaurant cafe
    { name: "Restoran", filePath: "assets/templates/Restaurant-Cafe/restoran-template/index.html", donwloadPath: "assets/templates/Restaurant-Cafe/restoran-template/restoran-template-download.zip", imagePath: "assets/template-images/restoran-template-thumbnail.png", category: 'Restaurant & Cafe', type: "Promotion", isLiked: false},

    { name: "Cafulex", filePath: "assets/templates/Restaurant-Cafe/cafulex-template/index.html", donwloadPath: "assets/templates/Restaurant-Cafe/cafulex-template/cafulex-template-download.zip", imagePath: "assets/template-images/cafulex-template-thumbnail.png", category: 'Restaurant & Cafe', type: "Promotion", isLiked: false},

    { name: "Cakeshop", filePath: "assets/templates/Restaurant-Cafe/cakeshop-template/index.html", donwloadPath: "assets/templates/Restaurant-Cafe/cakeshop-template/cakeshop-template-download.zip", imagePath: "assets/template-images/cakeshop-template-thumbnail.png", category: 'Restaurant & Cafe', type: "Promotion", isLiked: false},

    { name: "Cofe", filePath: "assets/templates/Restaurant-Cafe/cofe-template/index.html", donwloadPath: "assets/templates/Restaurant-Cafe/cofe-template/cofe-template-download.zip", imagePath: "assets/template-images/cofe-template-thumbnail.png", category: 'Restaurant & Cafe', type: "Promotion", isLiked: false},

    { name: "goid", filePath: "assets/templates/Restaurant-Cafe/goid-template/index.html", donwloadPath: "assets/templates/Restaurant-Cafe/goid-template/goid-template-download.zip", imagePath: "assets/template-images/goid-template-thumbnail.png", category: 'Restaurant & Cafe', type: "Promotion", isLiked: false},

    // travel tourism
    { name: "Freetravel", filePath: "assets/templates/Travel-Tourism/freetravel-template/index.html", donwloadPath: "assets/templates/Travel-Tourism/freetravel-template/freetravel-template-download.zip", imagePath: "assets/template-images/freetravel-template-thumbnail.png", category: 'Travel & Tourism', type: "Service", isLiked: false},

    { name: "Hotelier", filePath: "assets/templates/Travel-Tourism/hotelier-template/index.html", donwloadPath: "assets/templates/Travel-Tourism/hotelier-template/hotelier-template-download.zip", imagePath: "assets/template-images/hotelier-template-thumbnail.png", category: 'Travel & Tourism', type: "Service", isLiked: false},

    { name: "Traveler", filePath: "assets/templates/Travel-Tourism/traveler-template/index.html", donwloadPath: "assets/templates/Travel-Tourism/traveler-template/traveler-template-download.zip", imagePath: "assets/template-images/traveler-template-thumbnail.png", category: 'Travel & Tourism', type: "Service", isLiked: false},

    // animals nature

    { name: "Drool", filePath: "assets/templates/Animals-Nature/drool-template/index.html", donwloadPath: "assets/templates/Animals-Nature/drool-template/drool-template-download.zip", imagePath: "assets/template-images/drool-template-thumbnail.png", category: 'Animals & Nature', type: "Blog", isLiked: false},

    { name: "Petcare", filePath: "assets/templates/Animals-Nature/petcare-template/index.html", donwloadPath: "assets/templates/Animals-Nature/petcare-template/petcare-template-download.zip", imagePath: "assets/template-images/petcare-template-thumbnail.png", category: 'Animals & Nature', type: "Blog", isLiked: false},
    
    { name: "Petology", filePath: "assets/templates/Animals-Nature/petology-template/index.html", donwloadPath: "assets/templates/Animals-Nature/petology-template/petology-template-download.zip", imagePath: "assets/template-images/petology-template-thumbnail.png", category: 'Animals & Nature', type: "Blog", isLiked: false},

    { name: "Worldfree", filePath: "assets/templates/Animals-Nature/worldfree-template/index.html", donwloadPath: "assets/templates/Animals-Nature/worldfree-template/worldfree-template-download.zip", imagePath: "assets/template-images/worldfree-template-thumbnail.svg", category: 'Animals & Nature', type: "Blog", isLiked: false},

    // art design
    { name: "Brainwave", filePath: "assets/templates/Art-Design/brainwave-template/index.html", donwloadPath: "assets/templates/Art-Design/brainwave-template/brainwave-template-download.zip", imagePath: "assets/template-images/brainwave-template-thumbnail.png", category: 'Art & Design', type: "Service", isLiked: false},

    { name: "Bricker", filePath: "assets/templates/Art-Design/bricker-template/index.html", donwloadPath: "assets/templates/Art-Design/bricker-template/bricker-template-download.zip", imagePath: "assets/template-images/bricker-template-thumbnail.png", category: 'Art & Design', type: "Service", isLiked: false},
    
    { name: "Creativostido", filePath: "assets/templates/Art-Design/creativostido-template/index.html", donwloadPath: "assets/templates/Art-Design/creativostido-template/creativostido-template-download.zip", imagePath: "assets/template-images/creativostido-template-thumbnail.png", category: 'Art & Design', type: "Service", isLiked: false},

    { name: "Moto", filePath: "assets/templates/Art-Design/moto-template/index.html", donwloadPath: "assets/templates/Art-Design/moto-template/moto-template-download.zip", imagePath: "assets/template-images/moto-template-thumbnail.png", category: 'Art & Design', type: "Service", isLiked: false},

    // education

    { name: "Dropbeat", filePath: "assets/templates/Education/dropbeat-template/index.html", donwloadPath: "assets/templates/Education/dropbeat-template/dropbeat-template-download.zip", imagePath: "assets/template-images/dropbeat-template-thumbnail.png", category: 'Education', type: "Service", isLiked: false},

    { name: "Elearning", filePath: "assets/templates/Education/elearning-template/index.html", donwloadPath: "assets/templates/Education/elearning-template/elearning-template-download.zip", imagePath: "assets/template-images/elearning-template-thumbnail.png", category: 'Education', type: "Service", isLiked: false},

    { name: "Templatoedu", filePath: "assets/templates/Education/templatoedu-template/index.html", donwloadPath: "assets/templates/Education/templatoedu-template/templatoedu-template-download.zip", imagePath: "assets/template-images/templatoedu-template-thumbnail.png", category: 'Education', type: "Service", isLiked: false},

    // event
    
    { name: "Artxibition", filePath: "assets/templates/Event/artxibition-template/index.html", donwloadPath: "assets/templates/Event/artxibition-template/artxibition-template-download.zip", imagePath: "assets/template-images/artxibition-template-thumbnail.png", category: 'Event', type: "Promotion", isLiked: false},

    { name: "Crism", filePath: "assets/templates/Event/crism-template/index.html", donwloadPath: "assets/templates/Event/crism-template/crism-template-download.zip", imagePath: "assets/template-images/crism-template-thumbnail.png", category: 'Event', type: "Promotion", isLiked: false},

    { name: "Gevent", filePath: "assets/templates/Event/gevent-template/index.html", donwloadPath: "assets/templates/Event/gevent-template/gevent-template-download.zip", imagePath: "assets/template-images/gevent-template-thumbnail.png", category: 'Event', type: "Promotion", isLiked: false},

    // fitness
    { name: "Energym", filePath: "assets/templates/Fitness/energym-template/index.html", donwloadPath: "assets/templates/Fitness/energym-template/energym-template-download.zip", imagePath: "assets/template-images/energym-template-thumbnail.png", category: 'Fitness', type: "Promotion", isLiked: false},

    { name: "Fiit", filePath: "assets/templates/Fitness/fiit-template/index.html", donwloadPath: "assets/templates/Fitness/fiit-template/fiit-template-download.zip", imagePath: "assets/template-images/fiit-template-thumbnail.png", category: 'Fitness', type: "Promotion", isLiked: false},

    { name: "Gymnast", filePath: "assets/templates/Fitness/gymnast-template/index.html", donwloadPath: "assets/templates/Fitness/gymnast-template/gymnast-template-download.zip", imagePath: "assets/template-images/gymnast-template-thumbnail.png", category: 'Fitness', type: "Promotion", isLiked: false},

    { name: "Gymster", filePath: "assets/templates/Fitness/gymster-template/index.html", donwloadPath: "assets/templates/Fitness/gymster-template/gymster-template-download.zip", imagePath: "assets/template-images/gymster-template-thumbnail.png", category: 'Fitness', type: "Promotion", isLiked: false},

    { name: "Progym", filePath: "assets/templates/Fitness/progym-template/index.html", donwloadPath: "assets/templates/Fitness/progym-template/progym-template-download.zip", imagePath: "assets/template-images/progym-template-thumbnail.png", category: 'Fitness', type: "Promotion", isLiked: false},

    // health beauty
    { name: "Careo", filePath: "assets/templates/Health-Beauty/careo-template/index.html", donwloadPath: "assets/templates/Health-Beauty/careo-template/careo-template-download.zip", imagePath: "assets/template-images/careo-template-thumbnail.png", category: 'Beauty & Health', type: "Promotion", isLiked: false },

    { name: "Convid", filePath: "assets/templates/Health-Beauty/convid-template/index.html", donwloadPath: "assets/templates/Health-Beauty/convid-template/convid-template-download.zip", imagePath: "assets/template-images/convid-template-thumbnail.png", category: 'Beauty & Health', type: "Blog", isLiked: false },

    { name: "Medicare", filePath: "assets/templates/Health-Beauty/medicare-template/index.html", donwloadPath: "assets/templates/Health-Beauty/medicare-template/medicare-template-download.zip", imagePath: "assets/template-images/medicare-template-thumbnail.png", category: 'Beauty & Health', type: "Promotion", isLiked: false },

    { name: "Medinova", filePath: "assets/templates/Health-Beauty/medinova-template/index.html", donwloadPath: "assets/templates/Health-Beauty/medinova-template/medinova-template-download.zip", imagePath: "assets/template-images/medinova-template-thumbnail.png", category: 'Beauty & Health', type: "Promotion", isLiked: false },

    { name: "Mico", filePath: "assets/templates/Health-Beauty/mico-template/index.html", donwloadPath: "assets/templates/Health-Beauty/mico-template/mico-template-download.zip", imagePath: "assets/template-images/mico-template-thumbnail.png", category: 'Beauty & Health', type: "Promotion", isLiked: false },

    { name: "Milina", filePath: "assets/templates/Health-Beauty/milina-template/index.html", donwloadPath: "assets/templates/Health-Beauty/milina-template/milina-template-download.zip", imagePath: "assets/template-images/milina-template-thumbnail.png", category: 'Beauty & Health', type: "Promotion", isLiked: false },

    { name: "Spacenter", filePath: "assets/templates/Health-Beauty/spacenter-template/index.html", donwloadPath: "assets/templates/Health-Beauty/spacenter-template/spacenter-template-download.zip", imagePath: "assets/template-images/spacenter-template-thumbnail.png", category: 'Beauty & Health', type: "Promotion", isLiked: false },

    // home

    { name: "Builtbetter", filePath: "assets/templates/Home/builtbetter-template/index.html", donwloadPath: "assets/templates/Home/builtbetter-template/builtbetter-template-download.zip", imagePath: "assets/template-images/builtbetter-template-thumbnail.png", category: 'Home', type: "Service", isLiked: false },

    { name: "Digitif", filePath: "assets/templates/Home/digitif-template/index.html", donwloadPath: "assets/templates/Home/digitif-template/digitif-template-download.zip", imagePath: "assets/template-images/digitif-template-thumbnail.png", category: 'Home', type: "Service", isLiked: false },

    { name: "Limelight", filePath: "assets/templates/Home/limelight-template/index.html", donwloadPath: "assets/templates/Home/limelight-template/limelight-template-download.zip", imagePath: "assets/template-images/limelight-template-thumbnail.png", category: 'Home', type: "Service", isLiked: false },

    { name: "Painter", filePath: "assets/templates/Home/painter-template/index.html", donwloadPath: "assets/templates/Home/painter-template/painter-template-download.zip", imagePath: "assets/template-images/painter-template-thumbnail.png", category: 'Home', type: "Service", isLiked: false },

    // Landing Pages
    { name: "Canvas", filePath: "assets/templates/Landing-Pages/canvas-template/index.html", donwloadPath: "assets/templates/Landing-Pages/canvas-template/canvas-template-download.zip", imagePath: "assets/template-images/canvas-template-thumbnail.png", category: 'Landing Pages', type: "One Page", isLiked: false },
    
    { name: "Landly", filePath: "assets/templates/Landing-Pages/landly-template/index.html", donwloadPath: "assets/templates/Landing-Pages/landly-template/landly-template-download.zip", imagePath: "assets/template-images/landly-template-thumbnail.png", category: 'Landing Pages', type: "One Page", isLiked: false },

    { name: "Lava", filePath: "assets/templates/Landing-Pages/lava-template/index.html", donwloadPath: "assets/templates/Music-Entertainment/lava-template/lava-template-download.zip", imagePath: "assets/template-images/lava-template-thumbnail.png", category: 'Landing Pages', type: "One Page", isLiked: false },

    // Music & Entertainment

    { name: "Audiolanding", filePath: "assets/templates/Music-Entertainment/audiolanding-template/index.html", donwloadPath: "assets/templates/Music-Entertainment/audiolanding-template/audiolanding-template-download.zip", imagePath: "assets/template-images/audiolanding-template-thumbnail.png", category: 'Music & Entertainment', type: "Promotion", isLiked: false },
    
    { name: "Entro", filePath: "assets/templates/Music-Entertainment/entro-template/index.html", donwloadPath: "assets/templates/Music-Entertainment/entro-template/entro-template-download.zip", imagePath: "assets/template-images/entro-template-thumbnail.png", category: 'Music & Entertainment', type: "Promotion", isLiked: false },

    { name: "Microo", filePath: "assets/templates/Music-Entertainment/microo-template/index.html", donwloadPath: "assets/templates/Music-Entertainment/microo-template/microo-template-download.zip", imagePath: "assets/template-images/microo-template-thumbnail.png", category: 'Music & Entertainment', type: "Promotion", isLiked: false },

    // photography

    { name: "Apollo", filePath: "assets/templates/Photography/apollo-template/index.html", donwloadPath: "assets/templates/Photography/apollo-template/apollo-template-download.zip", imagePath: "assets/template-images/apollo-template-thumbnail.png", category: 'Photography', type: "Blog", isLiked: false },

    { name: "Jackrose", filePath: "assets/templates/Photography/jackrose-template/index.html", donwloadPath: "assets/templates/Photography/jackrose-template/jackrose-template-download.zip", imagePath: "assets/template-images/jackrose-template-thumbnail.png", category: 'Photography', type: "Blog", isLiked: false },

    { name: "Photosec", filePath: "assets/templates/Photography/photosec-template/index.html", donwloadPath: "assets/templates/Photography/photosec-template/photosec-template-download.zip", imagePath: "assets/template-images/photosec-template-thumbnail.png", category: 'Photography', type: "Blog", isLiked: false },

    { name: "Uliya", filePath: "assets/templates/Photography/uliya-template/index.html", donwloadPath: "assets/templates/Photography/uliya-template/uliya-template-download.zip", imagePath: "assets/template-images/uliya-template-thumbnail.png", category: 'Photography', type: "Blog", isLiked: false },
  ]

  groupedCategories : { name: string; }[][] = [];

  groupedTemplates : { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string; type: string; isLiked: boolean }[][] = [];

  loadedTemplates : { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string; type: string; isLiked: boolean}[][] = []; 


  isMobile: boolean = false;
  ngOnInit(){
    AOS.init();
    if (window.screen.width <= 768) {
      this.isMobile = true;
    }

    // default templates load
    for (let i = 0; i < this.categories.length; i += 5) {
      this.groupedCategories.push(this.categories.slice(i, i + 5));
    }
    
    for (let i = 0; i < this.allTemplates.length; i += 3) {

      this.groupedTemplates.push(this.allTemplates.slice(i, i + 3));
    }

    this.loadedTemplates = this.groupedTemplates;

    this.route.queryParams.subscribe(params => {
      const category = params['load'];
  
      if (category) {
        // Call your onCategoryClick function with the 'category' value
        this.onCategoryClick(category);
      }
    });

    // scroll to top
    window.scrollTo(0, 0);
  }

  onTypeClick(type: string, value: boolean, index: number) {
    this.types[index].value = value;
  
    const selectedTypes = this.types.filter(type => type.value).map(type => type.name);
    let typeFilteredTemplates = this.allTemplates.filter(template => selectedTypes.includes(template.type));

    if (typeFilteredTemplates.length == 0){
      typeFilteredTemplates = this.allTemplates;
    }

    for (let i = 0; i < typeFilteredTemplates.length; i++) {
      if (this.checkIfLiked(typeFilteredTemplates[i].name)){
        typeFilteredTemplates[i].isLiked = true;
      }else{
        typeFilteredTemplates[i].isLiked = false;
      }
    }
  
    const currentGroupedTemplates: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string; type: string; isLiked: boolean }[][] = [];
    for (let i = 0; i < typeFilteredTemplates.length; i += 3) {
      currentGroupedTemplates.push(typeFilteredTemplates.slice(i, i + 3));
    }
  
    this.loadedTemplates = currentGroupedTemplates;

    let count = 0;

    for (let template of this.loadedTemplates){
      count += template.length;
    }

    this.currentTemplateCount = count;
  }

  onCategoryClick(category: string){
    if (category == 'All Templates'){
      for (let i = 0; i <  this.allTemplates.length; i++) {
        if (this.checkIfLiked( this.allTemplates[i].name)){
          this.allTemplates[i].isLiked = true;
        }else{
          this.allTemplates[i].isLiked = false;
        }
      }

      this.groupedTemplates = [];
      for (let i = 0; i < this.allTemplates.length; i += 3) {
        this.groupedTemplates.push(this.allTemplates.slice(i, i + 3));
      }

      this.loadedTemplates = this.groupedTemplates;

      

      let count = 0;

      for (let template of this.loadedTemplates){
        count += template.length;
      }

      this.currentTemplateCount = count;
      

      return;
    }


    this.filteredTemplates = this.allTemplates.filter(template => template.category === category);

    for (let i = 0; i < this.filteredTemplates.length; i++) {
      if (this.checkIfLiked(this.filteredTemplates[i].name)){
        this.filteredTemplates[i].isLiked = true;
      }else {
        this.filteredTemplates[i].isLiked = false;
      }
    }

    let currentGroupedTemplates: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string; type: string; isLiked: boolean }[][] = [];
    for (let i = 0; i < this.filteredTemplates.length; i += 3) {
      currentGroupedTemplates.push(this.filteredTemplates.slice(i, i + 3));
    }



    this.loadedTemplates = currentGroupedTemplates;
  
    let count = 0;

    for (let template of this.loadedTemplates){
      count += template.length;
    }

    this.currentTemplateCount = count;
  }

  // wish list
  wishList: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string; type: string; isLiked: boolean }[] = [];

  displayWishList(): void{
    let groupedWishList: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string; type: string; isLiked: boolean}[][] = []    
    this.wishList = this.wishListService.getWishList();

    for (let i = 0; i < this.wishList.length; i += 3) {
      groupedWishList.push(this.wishList.slice(i, i + 3));
    }

    this.loadedTemplates = groupedWishList;

    let count = 0;

    for (let template of this.loadedTemplates){
      count += template.length;
    }

    this.currentTemplateCount = count;
  }
  
  checkIfLiked(name: string){
    return this.wishList.find(item => item.name === name);
  }
  
}
