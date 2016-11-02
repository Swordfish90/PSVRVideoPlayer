#ifndef QMLPSVR_H
#define QMLPSVR_H

#include <QObject>
#include <QVector4D>

#include "psvrsensorsmanager.h"

extern "C" {
#include "../libpsvr/psvr.h"
#include <stdio.h>

static psvr_context *ctx;
static struct psvr_sensor_frame frame;

}

class QMLPSVR : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool initialized READ getInitialized NOTIFY initializedChanged)

public:
    explicit QMLPSVR(QObject *parent = 0);
    bool getInitialized() { return initialized; }

signals:
    void initializedChanged();

public slots:
    void initialize();
    void terminate();

    void resetSensors();
    void updateSensorsData();
    QVector4D retrieveOrientation();

private:
    void enableVRMode();

private:
    PSVRSensorsManager sensorsManager;
    bool initialized = false;
};

#endif // QMLPSVR_H
