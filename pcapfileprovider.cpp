#include "pcapfileprovider.h"
#include <iostream>


CarpeOmnia::PcapFileProvider::PcapFileProvider()
{
}

void
CarpeOmnia::PcapFileProvider::getnextPacket()
{
    std::cout << "Called CarpeOmnia::PcapFileProvider::getnextPacket()\n";
}
