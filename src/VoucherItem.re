[@bs.val] external requireAssetURI: string => string = "require";

[@react.component]
let make = (~voucher:Vouchers.voucher) => {

// };
// [@react.component]
// let make = (~voucher: Vouchers.voucher) => {
  <div className={"voucher " ++ String.lowercase_ascii(voucher.title)}>
    <h3 className="title">
      {React.string(
         voucher.title
         ++ {js| • |js}
         ++ string_of_int(voucher.price)
         ++ {js|€|js},
       )}
    </h3>
    {React.array(
       Array.of_list(
         List.map(
           item =>
             <div key=item className="voucher-element">
               {React.string(item)}
             </div>,
           voucher.elements,
         ),
       ),
     )}
  </div>;
};