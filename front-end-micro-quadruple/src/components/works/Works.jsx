import "./works.scss"

export default function Works() {


    return <div className="works" id="works">

        {/* ADD FUNCTIONALITY TO BUTTOMS */}
        <div className="left">
            <div className="wrapper">
                <a href="#works" class="myButton"> Caminar</a>
                <h2>. Add Functionality</h2>
                <h2>.</h2>
                <a href="#works" class="myButton"> Agachar</a>
                {/* <h3>| 2022 - UNLP | </h3> */}
            </div>


        </div>
        <div className="right">
            <div className="wrapper">
                <a href="#works" class="myButton"> Levantar</a>
                <h2>.</h2>
                <h2>.</h2>
                <a href="#works" class="myButton"> Inclinar</a>
                {/* <h3>| 2022 - UNLP | </h3> */}
            </div>
        </div>
    </div>;
}
