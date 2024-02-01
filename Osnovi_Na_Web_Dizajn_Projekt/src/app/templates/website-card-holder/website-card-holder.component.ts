import { Component, Input, Output, EventEmitter } from '@angular/core';
import { Router } from '@angular/router';
import { AuthenticationService } from 'src/app/services/authentication.service';
import { WishListService } from 'src/app/services/wish-list.service';

@Component({
  selector: 'app-website-card-holder',
  templateUrl: './website-card-holder.component.html',
  styleUrls: ['./website-card-holder.component.scss']
})
export class WebsiteCardHolderComponent {
  isHovered: boolean = false;
  @Input() filePath: string = '';
  @Input() name: string = '';
  @Input() downloadLink: string = '';
  @Input() imagePath: string = '';
  @Input() isLiked: boolean = false;

  
  wishItem: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string, type: string; isLiked: boolean } = 
  {
    name: '',
    filePath: '',
    donwloadPath: '',
    imagePath: '',
    category: '',
    type: '',
    isLiked: false
  };



  constructor(private router: Router, private wishListService: WishListService, public authService: AuthenticationService) {}

  onCardMouseEnter() {
    this.isHovered = true;
  }

  onCardMouseLeave() {
    this.isHovered = false;
  }

  loadPreview(): void {
    // Navigate to the preview route with the file path as a parameter
    this.router.navigate(['/preview'], { queryParams: { templateUrl: this.filePath } });
  }


  toggleLike(): void {
    this.wishItem = {
      name: this.name,
      filePath: this.filePath,
      donwloadPath: this.downloadLink,
      imagePath: this.imagePath,
      category: 'Wish List',
      type: 'Wish List',
      isLiked: !this.isLiked
    }

    this.isLiked = !this.isLiked;

    if (this.isLiked) {
      this.wishListService.addToWishList(this.wishItem);
    }else{
      this.wishListService.removeFromWishList(this.filePath);
    }
  }
}
