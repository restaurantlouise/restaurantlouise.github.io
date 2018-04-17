let component = ReasonReact.statelessComponent("NavigationMenu");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="navigation-menu">
      <span className="nav-link home">
        <Link href="home">{ReasonReact.stringToElement("Accueil")}</Link>
      </span>
      <span className="nav-link chef">
        <Link href="chef">{ReasonReact.stringToElement("Le Chef")}</Link>
      </span>
      <span className="nav-link menu">
        <Link href="menu">{ReasonReact.stringToElement("Les Menus")}</Link>
      </span>
      <span className="nav-link contacts">
        <Link href="contacts">{ReasonReact.stringToElement("Contacts")}</Link>
      </span>
    </div>
  }
};
