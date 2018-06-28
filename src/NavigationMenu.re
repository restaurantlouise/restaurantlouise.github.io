let component = ReasonReact.statelessComponent("NavigationMenu");

let make = (~menuColor, _children) => {
  ...component,
  render: (_self) => {
    <div className="navigation-menu">
      <div className="desktop-container">
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((link: NavigationMenuLinks.link) => {
              <span className="nav-link" key={link.title}>
                <Link href={link.href} color=menuColor target={link.target}>
                  {ReasonReact.stringToElement(link.title)}
                </Link>
              </span>
            }, NavigationMenuLinks.links)
          ))
        )
      </div>
      <div className="mobile-container">
        <NavigationMenuMobile menuColor=menuColor/>
      </div>
    </div>
  }
};
