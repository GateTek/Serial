#include <QCoreApplication>
#include <QTextStream>

#include "serial.h"

QT_USE_NAMESPACE

int main(int argc, char *argv[]) {
    QCoreApplication coreApplication(argc, argv);
    QTextStream standardOutput(stdout);

    Serial robot("COM20");

    while(1) {
        standardOutput << robot.getYaw() << endl;
    }

    return coreApplication.exec();
}
