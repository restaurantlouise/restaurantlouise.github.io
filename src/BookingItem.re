[@react.component]
let make = (~title, ~lines, ~styleClassName) => {
  <div className=styleClassName>
    <h2 className="title"> {React.string(title)} </h2>
    {React.array(
       Array.of_list(
         List.map(
           item => <span key=item> {React.string(item)} </span>,
           lines,
         ),
       ),
     )}
  </div>;
};