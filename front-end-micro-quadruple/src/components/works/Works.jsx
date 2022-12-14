import { RobotService } from "../services/RobotService";
import { useRef } from "react";
import "./works.scss"
import { Toast } from 'primereact/toast';
import 'primereact/resources/themes/saga-green/theme.css';
import 'primereact/resources/primereact.min.css';
import 'primeicons/primeicons.css';

export default function Works() {
    const robotService = new RobotService();
    const toast = useRef(null);

    const renderToast = (statusCode) => {
        const condition = statusCode && statusCode === 200;
        const message = statusCode && statusCode === 200 ? "El robot esta realizando el movimiento deseado" : "Hubo un problema a la hora de realizar el movimiento deseado"
        if (condition) {
            toast.current.show({ severity: 'success', summary: message, life: 2000 });
        } else {
            toast.current.show({ severity: 'error', summary: message, life: 2000 });
        }
    }

    const sendStatusCodeToToast = (response) => {
        const statusCode = response ? response : null;
        renderToast(statusCode);
    }
    
    const onClickWalk = () => {
        robotService.move().then(response => sendStatusCodeToToast(response));
    }
    
    const onClickDogPosition = () => {
        robotService.dogPosition().then(response => sendStatusCodeToToast(response));
    }
    
    const onClickUp = () => {
        robotService.getReferencePosition().then(response => sendStatusCodeToToast(response));
    }
    
    const onClickLean = () => {
        robotService.leanFront().then(response => sendStatusCodeToToast(response));
    }

    return <div className="works" id="works">
            <Toast ref={toast} position={"top-center"}/>
            {/* ADD FUNCTIONALITY TO BUTTOMS */}
            <div className="left">
                <div className="wrapper">
                    <button onClick={onClickWalk}  className="myButton"> Caminar</button>
                    <br />
                    <br />
                    <button onClick={onClickDogPosition}  className="myButton"> Agachar</button>
                    {/* <h3>| 2022 - UNLP | </h3> */}
                </div>


            </div>
            <div className="right">
                <div className="wrapper">
                    <button onClick={onClickUp}  className="myButton"> Levantar</button>
                    <br />
                    <br />
                    <button onClick={onClickLean} class="myButton"> Inclinar</button>
                    {/* <h3>| 2022 - UNLP | </h3> */}
                </div>
            </div>
    </div>
    
}
