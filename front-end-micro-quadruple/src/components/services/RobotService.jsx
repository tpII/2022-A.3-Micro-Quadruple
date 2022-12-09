import axios from "axios";

export class RobotService {

    getGenericArgs() {
        return axios.get("http://192.168.1.200/genericArgs").then((response) => {
            return response;
          }, (response) => {
            return response.status
          });   
    }

    setServo(idServo, angle) {
      return axios.get("http://192.168.1.200/setServo?idServo=" + idServo + "&angle=" + angle).then((response) => {
        return response;
      }, (response) => {
        return response.status
      });   
    }

    getReferencePosition() {
      return axios.get("http://192.168.1.200/referencePosition").then((response) => {
        return response;
      }, (response) => {
        return response.status
      });   
    }

    getReferencePosition() {
      return axios.get("http://192.168.1.200/getAngles").then((response) => {
        return response;
      }, (response) => {
        return response.status
      });   
    }

    getAngles(x, y, z, leg) {
      return axios.get("http://192.168.1.200/getAngles?x=" + x + "&y=" + y + "&z=" + z + "&leg=" + leg).then((response) => {
        return response;
      }, (response) => {
        return response.status
      });   
    }

    dogPosition() {
      return axios.get("http://192.168.1.200/dogPosition").then((response) => {
        return response;
      }, (response) => {
        return response.status
      });   
    }

    move() {
      return axios.get("http://192.168.1.200/move").then((response) => {
        return response;
      }, (response) => {
        return response.status
      });   
    }

}