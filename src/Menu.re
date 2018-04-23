open Menus;

let component = ReasonReact.statelessComponent("Menu");

let make = (_children) =>
{
  ...component,
  render: (_self) => {
    <div className="menu">
      <div className="marche">
        <h3 className="title">{ReasonReact.stringToElement(marche.title)}</h3>
        (
          switch marche.condition {
            | None => ReasonReact.nullElement
            | Some(condition) => <div className="condition">{ReasonReact.stringToElement(condition)}</div>
          }
        )
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((item) => <div>{ReasonReact.stringToElement(item)}</div>, marche.elements)
          ))
        )
      </div>
    </div>
  }
};
