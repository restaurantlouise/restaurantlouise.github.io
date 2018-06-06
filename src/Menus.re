type menu = {
  title: string,
  price: int,
  condition: option(string),
  elements: list(string),
};

let marche = {
  title: {js|Marché|js},
  price: 25,
  condition: Some({js|(Midi uniquement, hors week-end et jours fériés)|js}),
  elements: [{js|Entrée • Plat • Dessert|js}],
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
};

let menus : list(menu) = [
  marche,
  issole,
  tadorne
]
