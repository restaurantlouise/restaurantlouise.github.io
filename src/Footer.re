let component = ReasonReact.statelessComponent("Footer");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="footer">
      <span>{ReasonReact.stringToElement("Restaurant Louise.")}</span>
      <span>{ReasonReact.stringToElement("4 rue Léo le Bourgo, 56100 Lorient")}</span>
      <span>{ReasonReact.stringToElement("02 97 84 72 12")}</span>
      <Social />
    </div>
  }
};
