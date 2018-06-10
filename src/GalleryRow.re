let component = ReasonReact.statelessComponent("GalleryRow");

let make = (~pictures, _children) =>
  {
    ...component,
    render: (_self) => {
      <div className="gallery-row">
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((image) => <img
              alt="gallery_pic"
              className="gallery_pic"
              key=image
              src=image
            />, pictures)
          ))
        )
      </div>
    }
  };
