type menu = {
  title: string,
  price: int,
  condition: option(string),
  elements: list(string)
};

let marche = {
  title: {js|Marché|js},
  price: 25,
  condition: Some({js|(Midi uniquement, hors week-end et jours fériés)|js}),
  elements: [{js|Entrée • Plat • Dessert|js}]
};

let issole = {
  title: {js|Issole|js},
  price: 55,
  condition: None,
  elements: [
    "Langoustines juste saisies, asperges et amandes",
    {js|Filet de veau rôti, petits pois, morilles, jus court ...|js},
    {js|Entremet chocolat-café, crème glacée au Baileys|js}
  ]
};

let tadorne = {
  title: {js|Tadorne|js},
  price: 85,
  condition: None,
  elements: [
    "Langoustines juste saisies, asperges et amandes",
    {js|Blanc de turbot, écrasé de pomme de terre iodée, émulsion yuzu|js},
    {js|Filet de veau rôti, petits pois, morilles, jus court ...|js},
    {js|Entremet chocolat-café, crème glacée au Baileys|js}
  ]
};
