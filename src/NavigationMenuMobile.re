type action =
  | Toggle;

type state = {
  showMenu: bool
};

let component = ReasonReact.reducerComponent("NavigationMenuMobile");

let make = (~menuColor, _children) => {
  ...component,
  initialState: () => {showMenu: false},
  reducer: (action, state) =>
    switch (action) {
    | Toggle => ReasonReact.Update({showMenu: !state.showMenu})
    },
  render: (self) => {
    <div>
      <div
        className="menu-btn"
        onClick={(_) => self.send(Toggle)}
      />
      <div className="navigation-menu-mobile-container"
        style=(ReactDOMRe.Style.make(~display={self.state.showMenu ? "contents" : "none"}, ()))
      >
        <div
          className="navigation-menu-mobile"
        >
          <div className="mobile-link">
            <Link href="home" color=menuColor>{ReasonReact.stringToElement("Accueil")}</Link>
          </div>
          <div className="mobile-link">
            <Link href="menus" color=menuColor>{ReasonReact.stringToElement("Les Menus")}</Link>
          </div>
          <div className="mobile-link">
            <Link href="chef" color=menuColor>{ReasonReact.stringToElement("Le Chef")}</Link>
          </div>
          <div className="mobile-link">
            <Link href="galerie" color=menuColor>{ReasonReact.stringToElement("Galerie")}</Link>
          </div>
          <div className="mobile-link">
            <Link href="bon-cadeau" color=menuColor>{ReasonReact.stringToElement("Bon Cadeau")}</Link>
          </div>
          <div className="mobile-link">
            <Link href="reservations" color=menuColor>{ReasonReact.stringToElement({js|Réservations|js})}</Link>
          </div>
        </div>
        <div className="overlay" onClick={(_) => self.send(Toggle)} />
      </div>
    </div>
  }
};
