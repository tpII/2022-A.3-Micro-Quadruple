import { RobotService } from "../services/RobotService";
import { useRef } from "react";
import "./works.scss"
import { Toast } from 'primereact/toast';

export default function Works() {
    const robotService = new RobotService();
    const toast = useRef(null);

    const renderToast = (statusCode) => {
        console.log(statusCode)
        const condition = statusCode && statusCode === 200;
        const message = statusCode && statusCode === 200 ? "El robot esta realizando el movimiento deseado" : "Hubo un problema a la hora de realizar el movimiento deseado"
        if (condition) {
            toast.current.show({ severity: 'success', summary: message, life: 2000 });
        } else {
            toast.current.show({ severity: 'error', summary: message, life: 2000 });
        }
    }
    const onClick = async () => {
        let response = await robotService.getGenericArgs();
        const statusCode = response ? response.status : null;
        renderToast(statusCode);
    }


    return <div className="works" id="works">
            {/* ADD FUNCTIONALITY TO BUTTOMS */}
            <div className="left">
                <div className="wrapper">
                <Toast ref={toast} />
                    <button onClick={onClick}  className="myButton"> Caminar</button>
                    <h2>. Add Functionality</h2>
                    <h2>.</h2>
                    <button onClick={onClick}  className="myButton">> Agachar</button>
                    {/* <h3>| 2022 - UNLP | </h3> */}
                </div>


            </div>
            <div className="right">
                <div className="wrapper">
                    <Toast ref={toast} />
                    <button onClick={onClick}  className="myButton"> Levantar</button>
                    <h2>.</h2>
                    <h2>.</h2>
                    <button onClick={onClick} class="myButton"> Inclinar</button>
                    {/* <h3>| 2022 - UNLP | </h3> */}
                </div>
            </div>
    </div>
    
}
