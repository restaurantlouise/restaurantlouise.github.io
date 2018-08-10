let airtableBaseURL = "https://api.airtable.com/v0/appJVebkrigj0ObBx";
let craftResourceURL = resource => {j|$airtableBaseURL/$resource|j};

let fetchDataFrom = (resourceURI) => {
  Fetch.fetchWithInit(
    craftResourceURL(resourceURI),
    Fetch.RequestInit.make(
      ~method_=Get,
      ~headers=Fetch.HeadersInit.make({"Authorization": "Bearer keyPJS3tjrWWDyvn5"}),
      ()
    )
  )
};

let menusPromise = Js.Promise.(
  fetchDataFrom("menu")
  |> then_(Fetch.Response.json)
  |> then_((json) =>
    Menus.(json
      |> DecodeMenus.airtableMenuResponse
      |> DecodeMenus.getResponseMenus
      |> Array.map(fetchedMenuToMenu)
      |> menus => resolve(menus)
    )
  )
);

let platsToHash = (platsArray: array(Plats.fetchedPlat)) => {
  Array.fold_left(
    (platsHash: Hashtbl.t(string, string), plat: Plats.fetchedPlat) => {
      Hashtbl.add(platsHash, plat.id, plat.fields.plat);
      platsHash
    },
    Hashtbl.create(5),
    platsArray
  )};

let platsPromise = Js.Promise.(
  fetchDataFrom("plat")
  |> then_(Fetch.Response.json)
  |> then_((json) =>
    Plats.(json
    |> DecodePlats.airtablePlatResponse
    |> DecodePlats.getResponsePlats
    |> platsToHash
    |> plats => resolve(plats)
    )
  )
);

let fetchData = (callback) =>
  Js.Promise.(
    all2((menusPromise, platsPromise))
    |> then_(
        ((menus, plats)) => {
          let menusToDisplay = Array.fold_left(
            (menusToPopulate: list(Menus.menu), menu: Menus.menu) => {
              menusToPopulate @ [{
                title: menu.title,
                price: menu.price,
                condition: menu.condition,
                elements: List.map((platId) => Hashtbl.find(plats, platId), menu.elements)
              }]
            },
            [],
            menus
          );
          let orderedMenusToDisplay = List.sort(
            (menu1: Menus.menu, menu2: Menus.menu) => {menu1.price - menu2.price},
            menusToDisplay
          );
          callback(orderedMenusToDisplay);
          resolve()
        }
      )
    |> ignore
  );
