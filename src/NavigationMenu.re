let component = ReasonReact.statelessComponent("NavigationMenu");

let make = (~menuColor, _children) => {
  ...component,
  render: (_self) => {
    <div className="navigation-menu">
      <span className="nav-link home">
        <Link href="home" color=menuColor>{ReasonReact.stringToElement("Accueil")}</Link>
      </span>
      /* <span className="nav-link chef">
        <Link href="chef">{ReasonReact.stringToElement("Le Chef")}</Link>
      </span> */
      <span className="nav-link menu">
        <Link href="menus" color=menuColor>{ReasonReact.stringToElement("Les Menus")}</Link>
      </span>
      <span className="nav-link menu">
        <Link href="galerie" color=menuColor>{ReasonReact.stringToElement("Galerie")}</Link>
      </span>
      <span className="nav-link menu">
        <Link href="bon-cadeau" color=menuColor>{ReasonReact.stringToElement("Bon Cadeau")}</Link>
      </span>
      <span className="nav-link booking">
        <Link href="reservations" color=menuColor>{ReasonReact.stringToElement({js|Réservations|js})}</Link>
      </span>
    </div>
  }
};
