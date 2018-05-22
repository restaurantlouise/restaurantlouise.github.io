type voucher = {
  title: string,
  price: int,
  elements: list(string)
};

let marche = {
  title: {js|Coffret Marché|js},
  price: 75,
  elements: [
    {js|Deux coupes de champagne|js},
    {js|Deux menus Marché|js}
  ]
};

let saveur = {
  title: {js|Coffret Saveur|js},
  price: 135,
  elements: [
    {js|Deux coupes de champagne|js},
    {js|Deux menus Issole|js}
  ]
};

let inspiration = {
  title: {js|Coffret Inspiration|js},
  price: 200,
  elements: [
    {js|Deux coupes de champagne|js},
    {js|Deux menus Issole|js},
    {js|Eau & Café|js},
    {js|Vins (valeur 50€)|js},
  ]
};

let passion = {
  title: {js|Coffret Passion|js},
  price: 270,
  elements: [
    {js|Deux coupes de champagne|js},
    {js|Deux menus Tadorne|js}
  ]
};

let degustation = {
  title: {js|Coffret Dégustation|js},
  price: 280,
  elements: [
    {js|Deux coupes de champagne|js},
    {js|Deux menus Tadorne|js},
    {js|Eau & Café|js},
    {js|Vins (valeur 60€)|js}
  ]
};

let decouverte = {
  title: {js|Coffret Découverte|js},
  price: 300,
  elements: [
    {js|Deux coupes de champagne|js},
    {js|Deux menus Tadorne|js},
    {js|Accord mets vins|js},
    {js|Eau & Café|js},
  ]
};

let vouchers : list(voucher) = [
  marche,
  saveur,
  inspiration,
  passion,
  degustation,
  decouverte
]
