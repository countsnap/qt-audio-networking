#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    socket = 0;
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    server->listen(QHostAddress::Any, 8002);
}

void Server::newConnection()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
    connect(socket, SIGNAL(destroyed()), this, SLOT(zeropointer()));
}

void Server::zeropointer()
{
    socket = 0;
}

void Server::writeData(QByteArray data)
{
    if (socket)
        socket->write(data);
}
