#ifndef SERVER_H
#define SERVER_H

#include <QtCore>
#include <QtNetwork>
#include <QtMultimedia>
#include <QTimer>

#include "audioinput.h"
#include "model.h"

#define UDP_PORT 8002

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    void startAudioSend();
    void endAudioSend();
    void setVolume(float volume);
    void changeDevice(QAudioDeviceInfo devinfo);

signals:

public slots:
    void writeDatagram(QByteArray data);
    void appendClient(QString client);

private slots:
    //void acceptTCPConnection();
    void sendBroadcast();

private:
    QUdpSocket *socketUDP;
    //QTcpSocket *socketTCP;
    //QTcpServer *serverTCP;
    QTimer *broadcastTimer;

public:
    ClientList *clientList;
    QHostAddress serverIP;
    AudioInput *input;
    QAudioDeviceInfo devinfo;
};

#endif // SERVER_H
