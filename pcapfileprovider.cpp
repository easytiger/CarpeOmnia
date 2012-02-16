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

    LOG(INFO) <<  "Pcap File opened successfully. Will attempt to set filter\n";
    applyBPF("tcp");

}

bool CarpeOmnia::PcapFileProvider::getnextPacket()
{
    //LOG(INFO) << "Called CarpeOmnia::PcapFileProvider::getnextPacket()\n";

    packet = pcap_next(mPcap, &header);
    bpf_u_int32 len = header.len;
    LOG(INFO) << "Received a packet of len: " << len;

    if (packet == NULL)
        return false;
    else
        return true;
}


CarpeOmnia::PcapFileProvider::~PcapFileProvider()
{
    pcap_close(mPcap);
}
