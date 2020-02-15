type action =
  | Toggle;

type state = {showMenu: bool};

let reducer = (state, action) =>
  switch (action) {
  | Toggle => {showMenu: !state.showMenu}
  };
let initialState = {showMenu: false};

[@react.component]
let make = (~menuColor) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  <div>
    <div className="menu-btn" onClick={_ => dispatch(Toggle)} />
    {state.showMenu
       ? <div className="navigation-menu-mobile-container">
           <div className="navigation-menu-mobile">
             {React.array(
                Array.of_list(
                  List.map(
                    (link: NavigationMenuLinks.link) => {
                      <div
                        className="mobile-link"
                        onClick={_ => dispatch(Toggle)}
                        key={link.title}>
                        <Link
                          href={link.href}
                          color=menuColor
                          target={link.target}
                          >
                          {React.string(link.title)}
                        </Link>
                      </div>
                    },
                    NavigationMenuLinks.links,
                  ),
                ),
              )}
           </div>
           <div className="overlay" onClick={_ => dispatch(Toggle)} />
         </div>
       : React.null}
  </div>;
};