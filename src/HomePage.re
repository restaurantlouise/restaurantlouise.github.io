[@bs.val] external requireAssetURI : string => string = "require";

let louiseIcon = requireAssetURI("./rsc/logo_louise.png");

let component = ReasonReact.statelessComponent("HomePage");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="home-container">
      <div className="home-page">
        <img alt="louise-icon" className="louise-icon" src=louiseIcon />
      </div>
      <div className="overlay" />
    </div>
  }
};
