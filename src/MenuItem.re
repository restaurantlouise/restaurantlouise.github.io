[@bs.val] external requireAssetURI : string => string = "require";

let component = ReasonReact.statelessComponent("MenuItem");

let make = (~menu: Menus.menu, _children) =>
  {
    ...component,
    render: (_self) => {
      <div className={"menu " ++ String.lowercase(menu.title)}>
        <h3 className="title">{ReasonReact.stringToElement(
          menu.title ++ {js| • |js} ++ string_of_int(menu.price) ++ {js|€|js}
        )}</h3>
        (
          switch menu.condition {
            | None => ReasonReact.nullElement
            | Some(condition) => <div className="condition">{ReasonReact.stringToElement(condition)}</div>
          }
        )
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((item) => <div key=item className="menu-element">
              {ReasonReact.stringToElement(item)}
            </div>, menu.elements)
          ))
        )
      </div>
    }
  };
