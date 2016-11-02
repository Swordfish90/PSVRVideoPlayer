#include "qmlpsvr.h"
#include <QDebug>


QMLPSVR::QMLPSVR(QObject *parent) : QObject(parent)
{
}

void QMLPSVR::terminate() {
    qDebug() << "PSVR is terminated.";
}

void QMLPSVR::initialize() {
    qDebug() << "PSVR is initialized.";

    int result;
    if ((result = psvr_open(&ctx)) < 0) {
        qCritical() << "Cannot open PSVR.";
        return;
    }

    enableVRMode();

    initialized = true;
    emit initializedChanged();
}

void QMLPSVR::enableVRMode() {
    uint32_t payload[2];
    payload[0] = 0xFFFFFF00;
    payload[1] = 0x00000000;
    printf("Enable VR Mode\n");
    psvr_send_command_sync(ctx, 0x11, (uint8_t *) &payload, 8);
}

void QMLPSVR::updateSensorsData() {
    psvr_read_sensor_sync(ctx, (uint8_t *) &frame, sizeof (struct psvr_sensor_frame));
    sensorsManager.updateWithRawData(
        frame.data[0].gyro.yaw,
        frame.data[0].gyro.pitch,
        frame.data[0].gyro.roll,
        frame.data[0].accel.x,
        frame.data[0].accel.y,
        frame.data[0].accel.z
    );
    sensorsManager.updateWithRawData(
        frame.data[1].gyro.yaw,
        frame.data[1].gyro.pitch,
        frame.data[1].gyro.roll,
        frame.data[1].accel.x,
        frame.data[1].accel.y,
        frame.data[1].accel.z
    );
}

QVector4D QMLPSVR::retrieveOrientation() {
    return sensorsManager.retrieveOrientation();
}

void QMLPSVR::resetSensors() {
    sensorsManager.reset();
}
