#ifndef PCAPFILEPROVIDER_H
#define PCAPFILEPROVIDER_H

#include "genericprovider.h"
#include <pcap/pcap.h>

#include <glog/logging.h>

namespace CarpeOmnia
{
    class PcapFileProvider : public GenericProvider
    {
    public:
        PcapFileProvider();
        ~PcapFileProvider();
        bool getnextPacket();
    private:
        pcap_t * mPcap;
    };
}

#endif // PCAPFILEPROVIDER_H
