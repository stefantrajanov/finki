import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { DropdownComponent } from './header/dropdown/dropdown.component';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { HomeComponent } from './home/home.component';
import { RouterModule, Routes } from '@angular/router';
import { ScrollIndicatorComponent } from './home/scroll-indicator/scroll-indicator.component';
import { TemplateCatalogComponent } from './home/template-catalog/template-catalog.component';
import { FaqComponent } from './home/faq/faq.component';
import { FooterComponent } from './footer/footer.component';
import { TemplatesComponent } from './templates/templates.component';
import { WebsiteCardHolderComponent } from './templates/website-card-holder/website-card-holder.component';
import { PreviewComponent } from './templates/website-card-holder/preview/preview.component';
import { WishListService } from './services/wish-list.service';
import { HttpClientModule } from '@angular/common/http';
import { LoginComponent } from './auth/login/login.component';
import { RegisterComponent } from './auth/register/register.component';
import { AuthHeaderComponent } from './auth/auth-header/auth-header.component';
import { FormsModule } from '@angular/forms';
import { environment } from '../environments/environment'
import { AngularFireModule } from '@angular/fire/compat';
import { AuthenticationService } from './services/authentication.service';
import { AuthGuard } from './services/auth.guard';
import { PopupComponent } from './popup/popup.component';
import { DropdownResourceComponent } from './header/dropdown-resource/dropdown-resource.component';
import { TermsOfServiceComponent } from './terms-of-service/terms-of-service.component';
import { PrivacyPolicyComponent } from './privacy-policy/privacy-policy.component';
import { WebsiteOverviewComponent } from './website-overview/website-overview.component';
import { TemplateSliderComponent } from './shared/template-slider/template-slider.component';
import { ContactComponent } from './contact/contact.component';
import { PreviewGuard } from './services/preview.guard';
import { NavErrorDirective } from './directives/nav-error.directive';
import { NotFoundComponent } from './not-found/not-found.component';
import { HostingGuideComponent } from './hosting-guide/hosting-guide.component';
import { ResetPasswordComponent } from './auth/reset-password/reset-password.component';

const appRoutes: Routes = [
  { path: '', component: HomeComponent },
  { path: 'templates', component: TemplatesComponent },
  { path: 'preview', component: PreviewComponent, canActivate: [PreviewGuard]},
  { path: 'auth/login', component: LoginComponent, canActivate: [AuthGuard]},
  { path: 'auth/register', component: RegisterComponent, canActivate: [AuthGuard] },
  { path: 'legal/terms-of-service', component: TermsOfServiceComponent },
  { path: 'legal/privacy-policy', component: PrivacyPolicyComponent },
  { path: 'website-overview', component: WebsiteOverviewComponent },
  { path: 'contact', component: ContactComponent },
  { path: 'domains', component: HostingGuideComponent },
  { path: 'auth/reset-password', component: ResetPasswordComponent },
  { path: '**', component: NotFoundComponent },
]

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    DropdownComponent,
    HomeComponent,
    ScrollIndicatorComponent,
    TemplateCatalogComponent,
    FaqComponent,
    FooterComponent,
    TemplatesComponent,
    WebsiteCardHolderComponent,
    PreviewComponent,
    LoginComponent,
    RegisterComponent,
    AuthHeaderComponent,
    PopupComponent,
    DropdownResourceComponent,
    TermsOfServiceComponent,
    PrivacyPolicyComponent,
    WebsiteOverviewComponent,
    TemplateSliderComponent,
    ContactComponent,
    NavErrorDirective,
    NotFoundComponent,
    HostingGuideComponent,
    ResetPasswordComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    BrowserAnimationsModule,
    HttpClientModule,
    FormsModule,
    AngularFireModule.initializeApp(environment),
    RouterModule.forRoot(appRoutes),
  ],
  exports: [RouterModule],
  providers: [WishListService, AuthenticationService],
  bootstrap: [AppComponent]
})
export class AppModule { }
