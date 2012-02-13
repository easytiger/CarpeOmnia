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


    // todo: extract to a common function to be shared with pcaplive
    struct bpf_program fp;		// The compiled filter expression
    char filter_exp[] = "tcp";	// The filter expression

    if (pcap_compile(mPcap, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
             // log filter here
             throw runtime_error(pcap_geterr(mPcap));
    }

    if (pcap_setfilter(mPcap, &fp) == -1) {
             throw runtime_error(pcap_geterr(mPcap));
    } else {
        LOG(INFO) << "BPF: \n" << "\"" << filter_exp << "\"" ;
        LOG(INFO) << "Set BPF filter to pcap handle OK\n";
    }
}

bool CarpeOmnia::PcapFileProvider::getnextPacket()
{
    struct pcap_pkthdr header;	/* The header that pcap gives us */
    const u_char *packet;		/* The actual packet */

    LOG(INFO) << "Called CarpeOmnia::PcapFileProvider::getnextPacket()\n";

    packet = pcap_next(mPcap, &header);
            /* Print its length */
    LOG(INFO) << "Received a packet of len: " << header.len;

    if (packet == NULL)
        return false;
    else
        return true;

}


CarpeOmnia::PcapFileProvider::~PcapFileProvider()
{
    pcap_close(mPcap);
}
