
let component = ReasonReact.statelessComponent("Link");

let internalRouting = (href, event) =>
  /* the default action will reload the page, which will cause us to lose state */
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
      ReactEventRe.Mouse.preventDefault(event);
      ReasonReact.Router.push(href)
    };

let handleClick = (href, event) =>
  if(String.sub(href, 0, 4) != "http") {
    internalRouting(href, event)
  };

let make = (~color, ~href, ~target="_self", children) => {
  ...component,
  render: (_self) => ReasonReact.createDomElement(
    "a",
    ~props={
      "href": href,
      "target": target,
      "onClick": handleClick(href),
      "style": {color: color}
    },
    children
  )
};
