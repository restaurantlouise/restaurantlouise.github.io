let component = ReasonReact.statelessComponent("Menu");

let make = (_children) =>
{
  ...component,
  render: (_self) => {
    <div className="menus">
      (
        ReasonReact.arrayToElement(Array.of_list(
          List.map((menu: Menus.menu) => <MenuItem menu=menu key={menu.title} />, Menus.menus)
        ))
      )
    </div>
  }
};
