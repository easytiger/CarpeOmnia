#include "pcapfileprovider.h"
#include <iostream>
#include <glog/logging.h>

CarpeOmnia::PcapFileProvider::PcapFileProvider()
{
    LOG(INFO) << "Constructing CarpeOmnia::PcapFileProvider::PcapFileProvider\n";
    char *dev, errbuf[PCAP_ERRBUF_SIZE];

    mPcap = pcap_open_offline("/tmp/test.pcap",errbuf);

    if (mPcap == NULL)
    {
        LOG(ERROR) << "Cannot open file: " << errbuf << "\n";
        throw runtime_error(errbuf);
    }


}

void CarpeOmnia::PcapFileProvider::getnextPacket()
{
    LOG(INFO) << "Called CarpeOmnia::PcapFileProvider::getnextPacket()\n";
}


CarpeOmnia::PcapFileProvider::~PcapFileProvider()
{
    pcap_close(mPcap);
}
