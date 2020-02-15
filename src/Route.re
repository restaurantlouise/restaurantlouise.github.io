[@bs.val] external location: string = "window.location.origin";

type t =
  | Home
  | Menu
  | Chef
  | Gallery
  | Booking
  | Voucher;
let fromUrl =
  fun
  | [] => Home
  | ["menus"] => Menu
  | ["chef"] => Chef
  | ["galerie"] => Gallery
  | ["bon-cadeau"] => Voucher
  | ["reservations"] => Booking
  | ["louise-website", "menus"] => Menu
  | ["louise-website", "chef"] => Chef
  | ["louise-website", "galerie"] => Gallery
  | ["louise-website", "bon-cadeau"] => Voucher
  | ["louise-website", "reservations"] => Booking
  | _ => Home;

let toUrl =
  fun
  | Home => "/"
  | Menu => "/menus"
  | Chef => "/chef"
  | Gallery => "/galerie"
  | Voucher => "/bon-cadeau"
  | Booking => "/reservations";

let toAbsoluteUrl = url => location ++ url;

let push = route => route |> toUrl |> ReasonReactRouter.push;
