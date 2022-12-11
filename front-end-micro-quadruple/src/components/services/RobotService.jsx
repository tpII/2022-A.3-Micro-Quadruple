import axios from "axios";

export class RobotService {

    getGenericArgs() {
        return axios.get("http://192.168.4.1/genericArgs").then((response) => {
            return response;
          }, (response) => {
            return response.status
          }), setTimeout(2000);   
    }

    setServo(idServo, angle) {
      return axios.get("http://192.168.4.1/setServo?idServo=" + idServo + "&angle=" + angle).then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }

    getReferencePosition() {
      return axios.get("http://192.168.4.1/referencePosition").then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }

    getReferencePosition() {
      return axios.get("http://192.168.4.1/getAngles").then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }

    getAngles(x, y, z, leg) {
      return axios.get("http://192.168.4.1/getAngles?x=" + x + "&y=" + y + "&z=" + z + "&leg=" + leg).then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }

    dogPosition() {
      return axios.get("http://192.168.4.1/dogPosition").then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }

    move() {
      console.log("Entre!")
      return axios.get("http://192.168.4.1/move").then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }
    leanFront(){
      console.log("Lean Front!")
      return axios.get("http://192.168.4.1/leanFront").then((response) => {
        return response;
      }, (response) => {
        return response.status
      }), setTimeout(2000);   
    }

}