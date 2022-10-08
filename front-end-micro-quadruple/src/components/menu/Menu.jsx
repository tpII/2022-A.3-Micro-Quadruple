import "./menu.scss"

export default function Menu({menuOpen, setMenuOpen}) {
  return <div className={"menu " + (menuOpen && "active")}>
      <ul>
        <li onClick={() => setMenuOpen(false)}> <a href="#intro">Home</a> </li>
        <li onClick={() => setMenuOpen(false)}> <a href="#works">Menu</a> </li>
        {/* <li onClick={() => setMenuOpen(false)}> <a href="#blockchain">Web3</a> </li>
        <li onClick={() => setMenuOpen(false)}> <a href="#portfolio">MCU</a> </li>
        <li onClick={() => setMenuOpen(false)}> <a href="#contact">Contact</a> </li> */}
      </ul>

  </div>;
}
