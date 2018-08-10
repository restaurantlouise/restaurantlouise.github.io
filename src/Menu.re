type state = {
  menus: list(Menus.menu),
  loading: bool
};

type action =
  | Loaded(list(Menus.menu))
  | Loading;

let component = ReasonReact.reducerComponent("Menu");

let make = (_children) =>
{
  let grabMenus = (callback) => AirTableCall.fetchData(callback)
    |> ignore;
 {
    ...component,
    initialState : () => {menus: [], loading: false},
    reducer: (action, state) =>
      switch (action) {
      | Loading => ReasonReact.Update({...state, loading: true})
      | Loaded(menus) =>
        ReasonReact.Update({
          menus: menus,
          loading: false,
        });
      },
    didMount: self => {
      let updateMenus = self.reduce(menus => Loaded(menus));
      grabMenus(updateMenus);
      ReasonReact.NoUpdate;
    },
    render: (self) => {
      let menusToRender = (
        switch self.state.loading {
        | true => <div>(ReasonReact.stringToElement("Chargement des menus"))</div>
        | false => (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((menu: Menus.menu) => <MenuItem menu=menu key={menu.title} />, self.state.menus)
          ))
        )
        }
      );
      <div className="menus">
        (menusToRender)
      </div>
    }
  };
};
