#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

//#include <curl/curl.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:

public slots:

};

#endif // CONTROLLER_H
