#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

/**
 * @brief The Controller class
 *
 * The abstract controller in the MVC design.
 */
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:

public slots:
    virtual void searchWord(const QString & lineEdit) = 0;
    virtual void generateWord(const QString & lineEdit) = 0;

};

#endif // CONTROLLER_H
