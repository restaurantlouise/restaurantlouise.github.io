[@react.component]
let make = (~pictures) => {
  <div className="gallery-row">
    {React.array(
       Array.of_list(
         List.map(
           image =>
             <img
               alt="gallery_pic"
               className="gallery_pic"
               key=image
               src=image
             />,
           pictures,
         ),
       ),
     )}
  </div>;
};