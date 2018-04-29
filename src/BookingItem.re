let component = ReasonReact.statelessComponent("BookingItem");

let make = (~title, ~lines, ~styleClassName, _children) =>
  {
    ...component,
    render: (_self) => {
      <div className=styleClassName>
        <h2 className="title">{ReasonReact.stringToElement(title)}</h2>
        (
          ReasonReact.arrayToElement(Array.of_list(
              List.map((item) => <span key=item>{ReasonReact.stringToElement(item)}</span>, lines)
          ))
        )
      </div>
    }
  };
