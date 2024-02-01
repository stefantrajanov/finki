import { Component } from '@angular/core';

@Component({
  selector: 'app-faq',
  templateUrl: './faq.component.html',
  styleUrls: ['./faq.component.scss']
})
export class FaqComponent {
  faqData = [
    { question: 'How to create a website',
     answer: `
     1. Choose a template and download it. <br/>
     2. Get a custom domain name on popular websites like <a href="https://www.godaddy.com/" target="_blank">GoDaddy</a>. <br/>
     3. Customize the site to fit your brand with hundreds of fonts, colors, and stock photos.<br/>
     4. Don’t have a logo? There are plenty of tools online to make a logo, one of them being <a href="https://www.canva.com/" target="_blank">Canva!</a> .<br/>
     5. Publish your site and promote it using social media and email marketing tools.<br/>
     `,
     expanded: true },
    { question: 'Why should I have a website?',
     answer: `Embarking on the journey of establishing an online presence for your business or personal project begins with creating a website. Whether your goal is to sell products online or showcase your portfolio, Squarespace offers a range of exceptional website templates tailored to various purposes. These templates can be effortlessly personalized to align with your brand. Additionally, our comprehensive platform simplifies the process of incorporating features such as blogs, online stores, and appointment scheduling into your website. Furthermore, you can utilize marketing tools to effectively connect with your target audience. 
   
    `, expanded: false },
    { question: 'How do I start building my website?', answer: `
    When it comes to embarking on website construction, you're presented with a plethora of paths. Dive into the intricacies of programming, where you'll craft your digital masterpiece from scratch. Alternatively, tap into the power of AI-assisted tools, simplifying and enhancing your design process. You can also seamlessly infuse your chosen template into user-friendly online editors, catering to various skill levels. The ever-expanding toolbox offers a universe of possibilities to pave your unique online presence.`, expanded: false },
    { question: 'Can someone build my website for me?', answer: `
    There are many professionals in the market who can build your website for you. You can find them on <a href="https://www.fiverr.com/" target="_blank">Fiverr</a> or <a href="https://www.upwork.com/" target="_blank">Upwork</a>. If you are wondering about the price of this service, well it depends on the complexity of the website. You can get a simple website for as low as $100. But if you want a complex website with a lot of features, it can cost you thousands of dollars. But it is hard to figure out what you really want, were SkillPix comes in, we have a range of templates that you can choose from and customize it to your liking.
    `, expanded: false },
  ];
  toggleAnswer(item: any): void {
    item.expanded = !item.expanded;
  }
}
