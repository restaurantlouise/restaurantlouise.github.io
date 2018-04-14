[@bs.val] external requireAssetURI : string => string = "require";

let fbIcon = requireAssetURI("./rsc/fb_icon.png");
let instaIcon = requireAssetURI("./rsc/insta_icon.png");

let component = ReasonReact.statelessComponent("Social");

let make = (_children) => {
  ...component,
  render: (_self) => {
    <a href=("https://www.facebook.com/JulienCorderochRestaurantLouise/") className="fb-link">
      <div>
        <img alt="fb" className="fb-icon" src=fbIcon />
      </div>
    </a>
  }
};
