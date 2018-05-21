type menu = {
  title: string,
  price: int,
  condition: option(string),
  elements: list(string),
  image: option(string)
};

let marche = {
  title: {js|Marché|js},
  price: 25,
  condition: Some({js|(Midi uniquement, hors week-end et jours fériés)|js}),
  elements: [{js|Entrée • Plat • Dessert|js}],
  image: Some("louise_plat_2_600.jpg")
};

let issole = {
  title: {js|Issole|js},
  price: 55,
  condition: None,
  elements: [
    {js|L’araignée de mer, crémeuse et iodée|js},
    {js|Magret de canard, carottes nouvelles et jus court comme une vinaigrette|js},
    {js|Les premières fraises et rhubarbes, crème glacée au poivre de Tasmanie|js}
  ],
  image: Some("louise_dessert_2_600.jpg")
};

let tadorne = {
  title: {js|Tadorne|js},
  price: 85,
  condition: None,
  elements: [
    {js|L’araignée de mer, crémeuse et iodée|js},
    {js|Merlan de ligne, champagne et asperges blanches|js},
    {js|Magret de canard, carottes nouvelles et jus court comme une vinaigrette|js},
    {js|Les premières fraises et rhubarbes, crème glacée au poivre de Tasmanie|js}
  ],
  image: Some("louise_entree_2_600.jpg")
};

let menus : list(menu) = [
  marche,
  issole,
  tadorne
]
