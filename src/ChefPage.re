let component = ReasonReact.statelessComponent("ChefPage");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="ChefPage">
      <h2>{ReasonReact.stringToElement("Le Chef")}</h2>
    </div>
  }
};
