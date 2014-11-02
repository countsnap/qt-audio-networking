#ifndef SERVER_H
#define SERVER_H

#include <QtCore>
#include <QtNetwork>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(quint16 port, QObject *parent = 0);

signals:

public slots:
    void writeData(QByteArray data);

private slots:
    void newConnection();
    void zeropointer();

private:
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // SERVER_H
