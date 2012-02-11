#ifndef PCAPFILEPROVIDER_H
#define PCAPFILEPROVIDER_H

#include "genericprovider.h"
#include <pcap.h>

namespace CarpeOmnia
{
    class PcapFileProvider : public GenericProvider
    {
    public:
        PcapFileProvider();
        void getnextPacket();
    private:

    };
}

#endif // PCAPFILEPROVIDER_H
