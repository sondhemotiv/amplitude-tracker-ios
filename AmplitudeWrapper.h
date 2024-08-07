#ifndef AMPLITUDE_WRAPPER_H
#define AMPLITUDE_WRAPPER_H

#include <QObject>
#include "ios/AmplitudeBridge.h"


class AmplitudeWrapper : public QObject {
    Q_OBJECT
public:
    explicit AmplitudeWrapper(QObject* parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE void initAmplitude(const QString& apiKey) {
        ::initAmplitude(apiKey.toUtf8().constData());
    }

    Q_INVOKABLE void logEvent(const QString& eventName) {
        ::logEvent(eventName.toUtf8().constData());
    }
};

#endif // AMPLITUDE_WRAPPER_H
