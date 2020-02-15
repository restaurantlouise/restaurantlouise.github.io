%raw
{|require('./app.css')|};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let menuColor = "white";
  let pageDisplayed =
    switch (url.path |> Route.fromUrl) {
    | Home => <HomePage />
    | Menu => <Menu />
    | Chef => <Chef />
    | Gallery => <Gallery />
    | Voucher => <Voucher />
    | Booking => <Booking />
    };
  <div className="App">
    <NavigationMenu menuColor />
    pageDisplayed
    <Footer />
  </div>;
};