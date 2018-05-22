[@bs.val] external requireAssetURI : string => string = "require";

let component = ReasonReact.statelessComponent("VoucherItem");

let make = (~voucher: Vouchers.voucher, _children) =>
  {
    ...component,
    render: (_self) => {
      <div className={"voucher " ++ String.lowercase(voucher.title)}>
        <h3 className="title">{ReasonReact.stringToElement(
          voucher.title ++ {js| • |js} ++ string_of_int(voucher.price) ++ {js|€|js}
        )}</h3>
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((item) => <div key=item className="voucher-element">
              {ReasonReact.stringToElement(item)}
            </div>, voucher.elements)
          ))
        )
      </div>
    }
  };
