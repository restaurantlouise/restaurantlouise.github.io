[@react.component]
let make = () => {
  <div className="vouchers">
    <h2 className="title"> {React.string("Nos Bons Cadeaux")} </h2>
    <div className="description">
      {React.string(
         "Contactez nous pour offrir l'un de nos coffrets, ou composez le votre.",
       )}
    </div>
    <div className="list">
      <div className="first-list">
        {Array.of_list(
           List.map(
             (voucher: Vouchers.voucher) =>
               <VoucherItem voucher key={voucher.title} />,
             Vouchers.firstVouchers,
           ),
         )
         |> React.array}
      </div>
      <div className="second-list">
        {React.array(
           Array.of_list(
             List.map(
               (voucher: Vouchers.voucher) =>
                 <VoucherItem voucher key={voucher.title} />,
               Vouchers.secondVouchers,
             ),
           ),
         )}
      </div>
    </div>
  </div>;
};