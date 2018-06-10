
[@bs.val] external requireAssetURI : string => string = "require";

let component = ReasonReact.statelessComponent("Gallery");

let asparagus = requireAssetURI("./rsc/gallery/asperges.jpg");
let bbq = requireAssetURI("./rsc/gallery/bbq.jpg");
let canapes = requireAssetURI("./rsc/gallery/canapes.jpg");
let glasses = requireAssetURI("./rsc/gallery/closeup.jpg");
let jop_cooking = requireAssetURI("./rsc/gallery/cuisine.jpg");
let dessert = requireAssetURI("./rsc/gallery/dessert.jpg");
let inside_blue = requireAssetURI("./rsc/gallery/interieur_bleu.jpg");
let inside_from_kitchen = requireAssetURI("./rsc/gallery/interieur_depuis_cuisine.jpg");
let interieur_depuis_rue = requireAssetURI("./rsc/gallery/interieur_depuis_rue.jpg");
let interieur_table_closeup = requireAssetURI("./rsc/gallery/interieur_table_closeup.jpg");
let julien_bw = requireAssetURI("./rsc/gallery/julien_bw.jpg");
let jus_court = requireAssetURI("./rsc/gallery/jus_court.jpg");
let louise_exterieur = requireAssetURI("./rsc/gallery/louise_exterieur.jpg");
let rhums = requireAssetURI("./rsc/gallery/rhums.jpg");
let tablier = requireAssetURI("./rsc/gallery/tablier.jpg");
let team_bw = requireAssetURI("./rsc/gallery/team_bw.jpg");

let galleryRows = [
  [louise_exterieur, tablier, jus_court],
  [asparagus, julien_bw, interieur_depuis_rue],
  [jop_cooking, interieur_table_closeup, bbq],
  [canapes, team_bw, dessert],
  [inside_from_kitchen, rhums, inside_blue]
];

let make = (_children) => {
  ...component,
  render: (_self) => {
    <div className="gallery">
      <h2 className="title">{ReasonReact.stringToElement("Galerie")}</h2>
      <div className="gallery-container">
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((galleryRow) => <GalleryRow pictures={galleryRow} key={List.hd(galleryRow)}/>
            , galleryRows)
          ))
        )
      </div>
    </div>
  }
};
