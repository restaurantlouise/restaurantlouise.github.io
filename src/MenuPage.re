let component = ReasonReact.statelessComponent("MenuPage");

let make = (_children) =>
  {
    ...component,
    render: (_self) => {
      <div className="menu-page">
        <h2>{ReasonReact.stringToElement("Le Menu")}</h2>
      </div>
    }
  };
