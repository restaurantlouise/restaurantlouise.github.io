let component = ReasonReact.statelessComponent("Voucher");

let make = (_children) =>
{
  ...component,
  render: (_self) => {
    <div className="vouchers">
      <h2 className="title">{ReasonReact.stringToElement("Nos Bons Cadeaux")}</h2>
      <div className="description">
        {ReasonReact.stringToElement(
          "Contactez nous pour offrir l'un de nos coffrets, ou composer le votre."
        )}
      </div>
      (
        ReasonReact.arrayToElement(Array.of_list(
          List.map(
            (voucher: Vouchers.voucher) => <VoucherItem voucher=voucher key={voucher.title} />,
            Vouchers.vouchers
          )
        ))
      )
    </div>
  }
};
