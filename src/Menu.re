type state = {
  menus: list(Menus.menu),
  loading: bool,
};

type action =
  | Loaded(list(Menus.menu))
  | Loading;

let initialState = {menus: [], loading: false};

let reducer = (state, action) =>
  switch (action) {
  | Loading => {...state, loading: true}
  | Loaded(menus) => {menus, loading: false}
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let grabMenus = callback => AirTableCall.fetchData(callback) |> ignore;
  React.useEffect0(() => {
    let updateMenus = menus => dispatch(Loaded(menus));
    grabMenus(updateMenus);
    None;
  });
  let menusToRender =
    state.loading
      ? <div> {React.string("Chargement des menus")} </div>
      : React.array(
          Array.of_list(
            List.map(
              (menu: Menus.menu) => <MenuItem menu key={menu.title} />,
              state.menus,
            ),
          ),
        );
  <div className="menus"> menusToRender </div>;
};