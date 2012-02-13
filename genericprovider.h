#ifndef GENERICPROVIDER_H
#define GENERICPROVIDER_H

#include <string>
#include <stdexcept>

#include "pcap/pcap.h"

using namespace std;

namespace CarpeOmnia
{
    class GenericProvider
    {
    public:
        GenericProvider();
        virtual bool getnextPacket() = 0;
    protected:

        void applyBPF(char filter_exp[]);

        pcap_t * mPcap;             // pcap handle
        struct pcap_pkthdr header;	// The header that pcap gives us
        const u_char *packet;		// The actual packet



    };
}
#endif // GENERICPROVIDER_H
