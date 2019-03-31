#include "concretecontroller.h"

ConcreteController::ConcreteController(Data *data, QObject *parent) :
    Controller(parent),
    data(data)
{

}

/**
 * @brief ConcreteController::httpRequest sends the request to the server
 * @param lineEdit the word to send in the request
 * @param search whether the server has to use the search or the generate method
 */
void ConcreteController::httpRequest(const QString &lineEdit, bool search)
{
    processed = false;
    lastSearchWord = lineEdit;

    QString sUrl = "http://lijleen.zicp.io:3003/?"
              "fbclid=IwAR2N8eb4ALHWowQszDRBA0C68myMHT4gxyXDCK33Sgfg3BJjmUdVnS7UV5w"
              "&seed=" + QString(lineEdit).replace(" ", "%20");
    if (!search)
        sUrl.append("&method=generate");

    access.get(QNetworkRequest(QUrl(sUrl)));

    connect(&access, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleReply(QNetworkReply*)));
}

void ConcreteController::searchWord(const QString &lineEdit)
{
    httpRequest(lineEdit, true);
}

void ConcreteController::generateWord(const QString &lineEdit)
{
    httpRequest(lineEdit, false);
}

/**
 * @brief ConcreteController::handleReply handles the reply of the server
 * request sent in the httpRequest function
 * @param reply
 */
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
