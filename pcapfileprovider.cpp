#include "pcapfileprovider.h"
#include <iostream>


CarpeOmnia::PcapFileProvider::PcapFileProvider()
{
    std::cout << "Constructing CarpeOmnia::PcapFileProvider::PcapFileProvider\n";
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    mPcap = pcap_open_offline("/tmp/test.pcap",errbuf);

    if (mPcap == NULL)
    {
        std::cerr << "Cannot open file: " << errbuf << "\n";
        throw runtime_error(errbuf);
    }

}

void CarpeOmnia::PcapFileProvider::getnextPacket()
{
    std::cout << "Called CarpeOmnia::PcapFileProvider::getnextPacket()\n";
}


CarpeOmnia::PcapFileProvider::~PcapFileProvider()
{
    pcap_close(mPcap);
}
