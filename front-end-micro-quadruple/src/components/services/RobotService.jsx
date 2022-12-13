import axios from "axios";

export class RobotService {
    constructor() {
      axios.defaults.headers.get['Access-Control-Allow-Origin'] = '*';
    }

    getGenericArgs() {
        return axios.get("http://192.168.4.1/genericArgs", {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

    setServo(idServo, angle) {
      return axios.get("http://192.168.4.1/setServo?idServo=" + idServo + "&angle=" + angle, {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

    getReferencePosition() {
      return axios.get("http://192.168.4.1/referencePosition", {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

    getReferencePosition() {
      return axios.get("http://192.168.4.1/getAngles", {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

    getAngles(x, y, z, leg) {
      return axios.get("http://192.168.4.1/getAngles?x=" + x + "&y=" + y + "&z=" + z + "&leg=" + leg, {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

    dogPosition() {
      return axios.get("http://192.168.4.1/dogPosition", {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

    move() {
      return axios.get("http://192.168.4.1/move", {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }
    leanFront(){
      return axios.get("http://192.168.4.1/leanFront", {timeout: 2000}).then((response) => response.status).catch(error => { return null });
    }

}