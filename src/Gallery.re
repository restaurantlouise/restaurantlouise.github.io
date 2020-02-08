
[@bs.val] external requireAssetURI : string => string = "require";

let component = ReasonReact.statelessComponent("Gallery");

let table_bw = requireAssetURI("./rsc/gallery/table_bw.jpg");
let couple = requireAssetURI("./rsc/gallery/couple.jpg");
let mignardises = requireAssetURI("./rsc/gallery/mignardises.jpg");

let brochettes = requireAssetURI("./rsc/gallery/brochettes.jpg");
let table_plante = requireAssetURI("./rsc/gallery/table_plante.jpg");
let tablier = requireAssetURI("./rsc/gallery/tablier.jpg");

let dessert = requireAssetURI("./rsc/gallery/dessert.jpg");
let julien_bw = requireAssetURI("./rsc/gallery/julien_bw.jpg");
let table = requireAssetURI("./rsc//gallery/table.jpg");

let four = requireAssetURI("./rsc/gallery/four.jpg");
let plate_black_green = requireAssetURI("./rsc/gallery/plate_black_green.jpg");
let salle_bw = requireAssetURI("./rsc/gallery/salle_bw.jpg");

let bbq = requireAssetURI("./rsc/gallery/bbq.jpg");
let gold = requireAssetURI("./rsc/gallery/gold.jpg");
let jop_bw = requireAssetURI("./rsc/gallery/jop_bw.jpg");

let plate_stjacques = requireAssetURI("./rsc/gallery/plate_stjacques.jpg");
let stjacques = requireAssetURI("./rsc/gallery/stjacques.jpg");
let table_solo_bw = requireAssetURI("./rsc/gallery/table_solo_bw.jpg");


let galleryRows = [
  [table_plante, couple, plate_black_green],
  [brochettes, table_solo_bw, stjacques],
  [jop_bw, dessert, tablier],
  [four, table_bw, bbq],
  [julien_bw, plate_stjacques, gold],
  [table, mignardises, salle_bw]
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
      <div className="gallery-credentials">
        <Link href="http://www.marni-spring.com" color="white" target="_blank">
          {ReasonReact.stringToElement("Photographies de Marni Spring")}
        </Link>
      </div>
    </div>
  }
};
