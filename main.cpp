#include <iostream>
#include "test_generated.h"
#include "connect.h"

using namespace MyData;

int main()
{
    flatbuffers::FlatBufferBuilder builder(1024);
    auto name = builder.CreateString("Test");
    auto version = builder.CreateString("Version 1.25.1");
    int serialNumber = 1234;
    auto aboutInfo = builder.CreateString("Information about client");
    auto data = CreateData(builder, name, version, serialNumber, aboutInfo);
    builder.Finish(data); 
    uint8_t* buf{};
    int port_number = 30000;
    int connection = connect(port_number); //Выполняем подключение к сокету
    while (1)
    {
        ssize_t bytes = write(connection, &data, sizeof(data));
        if (bytes < 0)
            break;
        read(connection, buf, sizeof(buf));
        auto data2 = GetData(buf);
        auto name2 = data2->name()->c_str();
        // и т.д.
    }
    return 0;
}