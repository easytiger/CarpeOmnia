#ifndef PCAPFILEPROVIDER_H
#define PCAPFILEPROVIDER_H

#include "genericprovider.h"
#include <pcap/pcap.h>

namespace CarpeOmnia
{
    class PcapFileProvider : public GenericProvider
    {
    public:
        PcapFileProvider();
        ~PcapFileProvider();
        void getnextPacket();
    private:
        pcap_t * mPcap;
    };
}

#endif // PCAPFILEPROVIDER_H
