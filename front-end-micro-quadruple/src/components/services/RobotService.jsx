import axios from "axios";

//const backendUrl = "192.168.1.200";
const backendUrl = "google.com";

export class RobotService {

    getGenericArgs() {
        return axios.get(backendUrl).then((response) => {
            return response;
          }, (response) => {
            return response.status
          });   
    }

}