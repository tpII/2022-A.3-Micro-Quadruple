import "./topbar.scss"
// import {Person, Mail, GitHub} from "@material-ui/icons"

export default function Topbar({menuOpen, setMenuOpen}) {
  return <div className={"topbar " + (menuOpen && "active")}>
    <div className="wrapper">

        <a href="#intro" className="logo">Home.</a>

        <div className="itemContainer">
          <h5> https://github.com/tpII/2022-A.3-Micro-Quadruple </h5>
        </div>

        <div className="hamburger" onClick={() => setMenuOpen(!menuOpen)}>
          <span className="line1"></span>
          <span className="line2"></span>
          <span className="line3"></span>
        </div>

    </div>
  </div>;
}
