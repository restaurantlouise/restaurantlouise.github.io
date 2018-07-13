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
        className={"menu-btn" ++ (menuColor == "white" ? " on-home" : "")}
        onClick={(_) => self.send(Toggle)}
      />
      {self.state.showMenu ?
        <div className="navigation-menu-mobile-container">
          <div
            className="navigation-menu-mobile"
          >
            (
              ReasonReact.arrayToElement(Array.of_list(
                List.map((link: NavigationMenuLinks.link) => {
                  <div
                    className={"mobile-link" ++ (menuColor == "white" ? " on-home" : "")}
                    onClick={(_) => self.send(Toggle)}
                    key={link.title}
                  >
                    <Link
                      href={link.href}
                      color=menuColor
                      target={link.target}
                    >
                      {ReasonReact.stringToElement(link.title)}
                    </Link>
                  </div>
                }, NavigationMenuLinks.links)
              ))
            )
          </div>
          <div className="overlay" onClick={(_) => self.send(Toggle)} />
        </div>
      : ReasonReact.nullElement}
    </div>
  }
};
