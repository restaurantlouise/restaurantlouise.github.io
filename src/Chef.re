[@bs.val] external requireAssetURI: string => string = "require";

let lechef = requireAssetURI("./rsc/le_chef.jpg");

[@react.component]
let make = () => {
    <div className="chef-container">
      <div className="pic">
        <img alt="photo du chef" className="chef-pic" src=lechef />
      </div>
      <div className="description">
        <h3 className="title"> {React.string("Le chef")} </h3>
        <div className="item"> {React.string(ChefTexts.intro)} </div>
        <div className="item"> {React.string(ChefTexts.academics)} </div>
        <div className="item"> {React.string(ChefTexts.whatIsLouise)} </div>
      </div>
    </div>;
};