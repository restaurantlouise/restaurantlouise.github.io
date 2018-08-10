type fetchedPlatFields = {
  plat: string,
  menu: list(string)
};

type fetchedPlat = {
  id: string,
  fields: fetchedPlatFields,
  createdTime: string
};

type airtablePlatResponse = {
  records: array(fetchedPlat)
};

module DecodePlats = {
  let fetchedPlatFields = json : fetchedPlatFields =>
    Json.Decode.{
      plat: json |> field("plat", string),
      menu: json |> field("menu", list(string))
    };
  let fetchedPlat = json : fetchedPlat =>
    Json.Decode.{
      id: json |> field("id", string),
      fields: json |> field("fields", fetchedPlatFields),
      createdTime: json |> field("createdTime", string)
    };
  let airtablePlatResponse = json : airtablePlatResponse => Json.Decode.{
    records: json |> field("records", array(fetchedPlat))
  };
  let getResponsePlats = (airtablePlatResponse) => airtablePlatResponse.records;
};
