let component = ReasonReact.statelessComponent("Booking");

let timesTitle = "Horaires";
let timesOpenDays = "Ouvert du mardi au samedi";
let timesDay = "Midi: 12h00 - 13h30";
let timesNight = "Soir: 19h00 - 21h30";
let timesClosedDays = {js|Fermé le dimanche et le lundi|js};

let addressTitle = "Adresse";
let addressPostal = {js|4 rue Léo le Bourgo|js};
let addressCity = "56100 Lorient";

let phoneTitle = {js|Réservations|js};
let phoneNumber = {js|Par téléphone, au 02 97 84 72 12|js};
let phoneTimes = {js|Nous sommes disponibles de 10h à 12h et de 18h à 20h|js};

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="booking">
      <div className="times-address">
        <div className="times">
          <h2 className="title">{ReasonReact.stringToElement(timesTitle)}</h2>
          <span className="open-days">{ReasonReact.stringToElement(timesOpenDays)}</span>
          <span className="day">{ReasonReact.stringToElement(timesDay)}</span>
          <span className="night">{ReasonReact.stringToElement(timesNight)}</span>
          <span className="closed-days">{ReasonReact.stringToElement(timesClosedDays)}</span>
        </div>
        <div className="address">
          <h2 className="title">{ReasonReact.stringToElement(addressTitle)}</h2>
          <span className="postal">{ReasonReact.stringToElement(addressPostal)}</span>
          <span className="city">{ReasonReact.stringToElement(addressCity)}</span>
        </div>
      </div>
      <div className="phone-map">
        <div className="phone">
          <h2 className="title">{ReasonReact.stringToElement(phoneTitle)}</h2>
          <span className="number">{ReasonReact.stringToElement(phoneNumber)}</span>
          <span className="phone-times">{ReasonReact.stringToElement(phoneTimes)}</span>
        </div>
      </div>
    </div>
  }
};
