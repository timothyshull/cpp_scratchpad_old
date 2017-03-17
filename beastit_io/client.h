#ifndef BEASTIT_IO_CLIENT_H
#define BEASTIT_IO_CLIENT_H

class Client {
private:
    Server server;
    Connection connection;
    Encoder encoder;
    Decoder decoder;
    Id id;
};

#endif // BEASTIT_IO_CLIENT_H
