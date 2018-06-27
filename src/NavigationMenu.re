let component = ReasonReact.statelessComponent("NavigationMenu");

let make = (~menuColor, _children) => {
  ...component,
  render: (_self) => {
    <div className="navigation-menu">
      <div className="desktop-container">
        <span className="nav-link">
          <Link href="home" color=menuColor>{ReasonReact.stringToElement("Accueil")}</Link>
        </span>
        <span className="nav-link">
          <Link href="menus" color=menuColor>{ReasonReact.stringToElement("Les Menus")}</Link>
        </span>
        <span className="nav-link">
          <Link href="chef" color=menuColor>{ReasonReact.stringToElement("Le Chef")}</Link>
        </span>
        <span className="nav-link">
          <Link href="galerie" color=menuColor>{ReasonReact.stringToElement("Galerie")}</Link>
        </span>
        <span className="nav-link">
          <Link href="bon-cadeau" color=menuColor>{ReasonReact.stringToElement("Bon Cadeau")}</Link>
        </span>
        <span className="nav-link">
          <Link href="reservations" color=menuColor>{ReasonReact.stringToElement({js|Réservations|js})}</Link>
        </span>
      </div>
      <div className="mobile-container">
        <NavigationMenuMobile menuColor=menuColor/>
      </div>
    </div>
  }
};
