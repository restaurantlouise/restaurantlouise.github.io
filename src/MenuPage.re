let component = ReasonReact.statelessComponent("MenuPage");

let make = (_children) =>
  {
    ...component,
    render: (_self) => {
      <div className="MenuPage">
        <h2>{ReasonReact.stringToElement("Le Menu")}</h2>
      </div>
    }
  };
