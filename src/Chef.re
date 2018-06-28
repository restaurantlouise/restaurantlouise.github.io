[@bs.val] external requireAssetURI : string => string = "require";

let lechef = requireAssetURI("./rsc/le_chef.jpg");

let component = ReasonReact.statelessComponent("Chef");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="chef-container">
      <div className="pic">
        <img
          alt="photo du chef"
          className="chef-pic"
          src=lechef
        />
      </div>
      <div className="description">
        <h3 className="title">{ReasonReact.stringToElement("Le chef")}</h3>
        <div className="item">{ReasonReact.stringToElement(ChefTexts.intro)}</div>
        <div className="item">{ReasonReact.stringToElement(ChefTexts.academics)}</div>
        <div className="item">{ReasonReact.stringToElement(ChefTexts.whatIsLouise)}</div>
      </div>
    </div>
  }
};
