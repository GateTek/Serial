#ifndef SERIAL_H
#define SERIAL_H

#include <QtSerialPort/QSerialPort>

class Serial {
public:
    Serial(QString port);

    float getYaw();
    float getPitch();
    float getRoll();
private:
    QSerialPort serialPort;

    float getData(QString id);
};

#endif // SERIAL_H
