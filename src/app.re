[%bs.raw {|require('./app.css')|}];

type route =
  | Home
  | Menu
  | Chef
  | Gallery
  | Booking
  | Voucher;

type state = {route};

type action =
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => Home
  | ["menus"] => Menu
  | ["chef"] => Chef
  | ["galerie"] => Gallery
  | ["bon-cadeau"] => Voucher
  | ["reservations"] => Booking
  | ["louise-website", "menus"] => Menu
  | ["louise-website", "chef"] => Chef
  | ["louise-website", "galerie"] => Gallery
  | ["louise-website", "bon-cadeau"] => Voucher
  | ["louise-website", "reservations"] => Booking
  | _ => Home
  };

let reducer = (action, _state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: Home},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url |> mapUrlToRoute))),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: (self) => {
    let pageDisplayed =
      switch (self.state.route) {
      | Home => <HomePage />
      | Menu => <Menu />
      | Chef => <Chef />
      | Gallery => <Gallery />
      | Voucher => <Voucher />
      | Booking => <Booking />
      };
    let menuColor = if (self.state.route === Home) {
      "white"
    } else {
      "#02022b"
    };

    <div className="App">
      <NavigationMenu menuColor=menuColor/>
      {pageDisplayed}
      <Footer />
    </div>
  }
};
