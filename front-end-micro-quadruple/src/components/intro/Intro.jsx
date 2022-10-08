import "./intro.scss"
import { init } from 'ityped'
import { useEffect, useRef } from "react";

export default function Intro() {

  // const textRef = useRef();

  // useEffect(()=>{
  //   init(textRef.current, { 
  //     showCursor: true,
  //     typeSpeed: 100,
  //     backDelay:1500,
  //     backSpeed:60,
  //     cursorChar: " |",
  //     strings: [' Computer Engineer Student',' Jr. Full-Stack Java Developer',' Jr. Front-End React Developer' ,' Microcontrollers Programmer',' Blockchain Enthusiast' ] })
  // },[])
  
  return <div className="intro" id="intro">
    <div className="center"> 
      <div className="wrapper">
        <h2>Adra | Alfonsin | Reinoso</h2>
        <h1>Grupo A.3</h1>
        
        <a href="#works">
          <img src="assets/arrow.png" alt="" />
      </a>
        
      </div>


    </div>
    
  </div>;
}
