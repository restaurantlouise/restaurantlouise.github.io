[@react.component]
let make = (~menuColor) => {
  <div className="navigation-menu">
    <div className="desktop-container">
      {React.array(
         Array.of_list(
           List.map(
             (link: NavigationMenuLinks.link) => {
               <span className="nav-link" key={link.title}>
                 <Link href={link.href} color=menuColor target={link.target}>
                   {React.string(link.title)}
                 </Link>
               </span>
             },
             NavigationMenuLinks.links,
           ),
         ),
       )}
    </div>
    <div className="mobile-container">
      <NavigationMenuMobile menuColor />
    </div>
  </div>;
};