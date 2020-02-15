[@bs.val] external requireAssetURI: string => string = "require";

let louiseIcon = requireAssetURI("./rsc/logo_louise.png");

[@react.component]
let make = () => {
  <div className="home-container">
    <div className="home-page">
      <img alt="louise-icon" className="louise-icon" src=louiseIcon />
    </div>
    <div className="overlay" />
  </div>;
};