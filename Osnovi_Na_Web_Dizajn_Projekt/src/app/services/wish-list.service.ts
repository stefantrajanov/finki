import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class WishListService {

  private wishList: { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string, type: string; isLiked: boolean }[] = [];

  addToWishList(template: any): void {
    const index = this.wishList.findIndex(item => item.filePath === template.filePath);
    if (index === -1) {
      this.wishList.push(template);
    }
  }

  removeFromWishList(filePath: string): void {
    const index = this.wishList.findIndex(item => item.filePath === filePath);
    if (index !== -1) {
      this.wishList.splice(index, 1);
    }
  }

  getWishList(): { name: string; filePath: string; donwloadPath: string; imagePath: string; category: string, type: string; isLiked: boolean }[] {
    return this.wishList;
  }
}
