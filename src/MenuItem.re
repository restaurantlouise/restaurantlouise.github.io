[@bs.val] external requireAssetURI: string => string = "require";


[@react.component]
let make = (~menu: Menus.menu) => {
    <div className={"menu " ++ String.lowercase_ascii(menu.title)}>
      <h3 className="title">
        {React.string(
           menu.title
           ++ {js| • |js}
           ++ string_of_int(menu.price)
           ++ {js|€|js},
         )}
      </h3>
      {switch (menu.condition) {
       | None => React.null
       | Some(condition) =>
         <div className="condition"> {React.string(condition)} </div>
       }}
      {React.array(
         Array.of_list(
           List.map(
             item =>
               <div key=item className="menu-element">
                 {React.string(item)}
               </div>,
             menu.elements,
           ),
         ),
       )}
    </div>;
};