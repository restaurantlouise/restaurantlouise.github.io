let internalRouting = (href, event) =>
  /* the default action will reload the page, which will cause us to lose state */
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReactRouter.push(href);
  };

let handleClick = (href, event) =>
  if (String.sub(href, 0, 4) != "http") {
    internalRouting(href, event);
  };

[@react.component]
let make = (~color, ~target=?, ~href, ~className="", ~children,()) => {
// make `target` optional to handle `NavigationMenuMobile` target param. The default value for target is `_self` per Web api so that is what we get if no target is passed. 

  <a style=(
  ReactDOMRe.Style.make(~color, ())) href ?target className onClick={event => handleClick(href, event)}>
    children
  </a>;
};