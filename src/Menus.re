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
  condition: Some({js|Laissez-vous tenter par le homard de nos côtes servi en cocotte (supplément 30 € par personne)|js}),
  elements: [
    {js|Bar de ligne en carpaccio, nectarine et dulse|js},
    {js|Médaillon de lotte au satay, noire de crimée rôtie et nage d’épices|js},
    {js|Fruits rouges et sangria au parfum de reine des prés|js}
  ],
};

let tadorne = {
  title: {js|Tadorne|js},
  price: 85,
  condition: Some({js|Laissez-vous tenter par le homard de nos côtes servi en cocotte (supplément 30 € par personne)|js}),
  elements: [
    {js|Bar de ligne en carpaccio, nectarine et dulse|js},
    {js|Médaillon de lotte au satay, noire de crimée rôtie et nage d’épices|js},
    {js|Morceau choisi dans le bœuf, panis snacké, jus travaillé comme une daube|js},
    {js|Fruits rouges et sangria au parfum de reine des prés|js}
  ],
};

let homard = {
  title: {js|Homard|js},
  price: 90,
  condition: Some({js|Réservation 48 heures à l’avance au 0297847212|js}),
  elements: [
    {js|Menu en cinq étapes autour de notre homard breton|js},
    {js|Accord mets vins possible pour 115 €|js}
  ],
};

let menus : list(menu) = [
  marche,
  issole,
  tadorne,
  homard
]
