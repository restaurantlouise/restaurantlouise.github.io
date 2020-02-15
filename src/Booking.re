
let timesTitle = "Horaires";
let timesOpenDays = "Ouvert du mardi au samedi";
let timesDay = "Midi: 12h00 - 13h30";
let timesNight = "Soir: 19h30 - 21h00";
let timesClosedDays = {js|Fermé le dimanche et le lundi|js};

let addressTitle = "Adresse";
let addressPostal = {js|4 rue Léo le Bourgo|js};
let addressCity = "56100 Lorient";

let phoneTitle = {js|Réservations|js};
let phoneNumber = {js|Par téléphone, au 02 97 84 72 12|js};

[@react.component]
let make = () => {
    <div className="booking">
      <div className="times-address">
        <BookingItem
          title=timesTitle
          lines=[timesOpenDays, timesDay, timesNight, timesClosedDays]
          styleClassName="times"
        />
        <BookingItem
          title=addressTitle
          lines=[addressPostal, addressCity]
          styleClassName="address"
        />
      </div>
      <div className="phone-map">
        <BookingItem
            title=phoneTitle
            lines=[phoneNumber]
            styleClassName="phone"
        />
      </div>
    </div>
};
