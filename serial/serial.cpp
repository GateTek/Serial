#include "serial.h"

Serial::Serial(QString port) {
    serialPort.setPortName(port);
    serialPort.setBaudRate(QSerialPort::Baud115200);
    serialPort.setDataBits(QSerialPort::Data8);
    serialPort.setParity(QSerialPort::NoParity);
    serialPort.setStopBits(QSerialPort::OneStop);
    serialPort.setFlowControl(QSerialPort::NoFlowControl);
    if (!serialPort.open(QIODevice::ReadWrite)) {
       //fare qualcosa perché errori
    }
}

float Serial::getPitch() {
    return getData("pitch");
}

float Serial::getRoll() {
    return getData("roll");
}

float Serial::getYaw() {
    return getData("yaw");
}

float Serial::getData(QString id) {
    QString data;
    do {
        serialPort.write((id+"\n").toLocal8Bit());
        serialPort.waitForReadyRead();
        data = serialPort.readLine();
    } while(data.length() < 6 || data.length()>8);
    return data.toFloat();
}
