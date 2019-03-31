#ifndef CONCRETECONTROLLER_H
#define CONCRETECONTROLLER_H

#include "controller.h"
#include "../model/data.h"

#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <iostream>

/**
 * @brief The ConcreteController class
 *
 * A concrete controller in the MVC design that uses html call to communicate
 * with JiaLin's part.
 */
class ConcreteController : public Controller
{
    Q_OBJECT
public:
    explicit ConcreteController(Data * data, QObject *parent = nullptr);
    void httpRequest(const QString & lineEdit, bool search = true);

signals:

public slots:
    virtual void searchWord(const QString & lineEdit) override;
    virtual void generateWord(const QString & lineEdit) override;
    void handleReply(QNetworkReply *reply);

private:
    QString lastSearchWord;

    Data * data;

    QNetworkAccessManager access;

    bool processed;
};

#endif // CONCRETECONTROLLER_H
