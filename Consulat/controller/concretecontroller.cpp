#include "concretecontroller.h"

//#include <QEventLoop> // TODO either remove this or put it in the header file
#include <iostream> // TODO remove this at the end

ConcreteController::ConcreteController(Data *data, QObject *parent) :
    Controller(parent),
    data(data)
{

}

void ConcreteController::searchWord(const QString &lineEdit)
{
    processed = false;
    lastSearchWord = lineEdit;

    access.get(QNetworkRequest(QUrl("http://lijleen.zicp.io:3003/?"
                                             "fbclid=IwAR2N8eb4ALHWowQszDRBA0C68myMHT4gxyXDCK33Sgfg3BJjmUdVnS7UV5w"
                                             "&seed=" + QString(lineEdit).replace(" ", "%20"))));

    connect(&access, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleReply(QNetworkReply*)));
}

void ConcreteController::generateWord(const QString &lineEdit)
{
    processed = false;
    lastSearchWord = lineEdit;

    access.get(QNetworkRequest(QUrl("http://lijleen.zicp.io:3003/?method=generate&"
                                             "fbclid=IwAR2N8eb4ALHWowQszDRBA0C68myMHT4gxyXDCK33Sgfg3BJjmUdVnS7UV5w"
                                             "&seed=" + QString(lineEdit).replace(" ", "%20"))));

    connect(&access, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleReply(QNetworkReply*)));
}

void ConcreteController::handleReply(QNetworkReply* reply)
{
    if (processed)
        return;
    processed = true;

    QJsonDocument JDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject JObject = JDoc.object();

    reply->deleteLater();

    QJsonValue result(JObject["result"]);

    if (JObject["isSuccess"].toBool(false))
        data->setTreeModel(lastSearchWord, result.toArray());
    else
        std::cerr << "The server has not processed the data properly" << std::endl;
}
