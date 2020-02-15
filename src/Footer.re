[@react.component]
let make = () => {
  <div className="footer">
    <span> {React.string("Restaurant Louise.")} </span>
    <span className="address">
      {React.string({js|4 rue Léo le Bourgo, 56100 Lorient|js})}
    </span>
    <span> {React.string("02 97 84 72 12")} </span>
    <Social />
  </div>;
};