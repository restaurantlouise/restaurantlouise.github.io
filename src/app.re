[%bs.raw {|require('./app.css')|}];

type route =
  | Home
  | Chef
  | Menu;

type state = {route};

type action =
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => Home
  | ["chef"] => Chef
  | ["menu"] => Menu
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
      | Chef => <ChefPage />
      | Menu => <MenuPage />
      };

    <div className="App">
      <NavigationMenu />
      {pageDisplayed}
      <Footer />
    </div>
  }
};
