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
      {self.state.showMenu ?
        <div className="navigation-menu-mobile-container">
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
            <div className="mobile-link">
              <Link
                href="https://www.hdmedia.fr/visite-virtuelle/hd/cbpXkpuRr-restaurant-louise.html"
                color=menuColor
                target="_blank"
              >
                {ReasonReact.stringToElement({js|Visite Virtuelle|js})}
              </Link>
            </div>
          </div>
          <div className="overlay" onClick={(_) => self.send(Toggle)} />
        </div>
      : ReasonReact.nullElement}
    </div>
  }
};
