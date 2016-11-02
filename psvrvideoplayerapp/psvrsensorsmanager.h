#ifndef PSVRSENSORSMANAGER_H
#define PSVRSENSORSMANAGER_H

#include <QObject>
#include <QVector4D>

class PSVRSensorsManager : public QObject
{
    Q_OBJECT
public:
    explicit PSVRSensorsManager(QObject *parent = 0);

signals:

public slots:
    void reset();
    void updateWithRawData(int16_t rawGyroX, int16_t rawGyroY, int16_t rawGyroZ, int16_t rawAccX, int16_t rawAccY, int16_t rawAccZ);
    QVector4D retrieveOrientation();

private:
    float parseAccelerometerData(int16_t data);
    float parseGyroscopeData(int16_t data);

private:
    float q0 = 1.0;
    float q1 = 0.0;
    float q2 = 0.0;
    float q3 = 0.0;

    float beta = 0.025;
    float sampleFreq = 120;
    void madgwickAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);
    float invSqrt(float x);
};

#endif // PSVRSENSORSMANAGER_H
