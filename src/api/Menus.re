type menu = {
  title: string,
  price: int,
  condition: option(string),
  elements: list(string),
};

type fetchedMenuFields = {
  menu: string,
  prix: int,
  condition: option(string),
  plats: list(string),
};

type fetchedMenu = {
  id: string,
  fields: fetchedMenuFields,
  createdTime: string
};

type airtableMenuResponse = {
  records: array(fetchedMenu)
};

module DecodeMenus = {
  let fetchedMenuFields = json : fetchedMenuFields =>
    Json.Decode.{
      menu: json |> field("menu", string),
      prix: json |> field("prix", int),
      condition: json |> optional(field("condition", string)),
      plats: json |> field("plats", list(string))
    };
  let fetchedMenu = json : fetchedMenu =>
    Json.Decode.{
      id: json |> field("id", string),
      fields: json |> field("fields", fetchedMenuFields),
      createdTime: json |> field("createdTime", string)
    };
  let airtableMenuResponse = json : airtableMenuResponse => Json.Decode.{
    records: json |> field("records", array(fetchedMenu))
  };
  let getResponseMenus = (airtableMenuResponse: airtableMenuResponse) => airtableMenuResponse.records;
};

let fetchedMenuToMenu = (fetchedMenu: fetchedMenu) => {
  title: fetchedMenu.fields.menu,
  price: fetchedMenu.fields.prix,
  condition: fetchedMenu.fields.condition,
  elements: fetchedMenu.fields.plats,
};
