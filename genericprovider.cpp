#include "genericprovider.h"
#include <pcap/pcap.h>
#include <glog/logging.h>"

CarpeOmnia::GenericProvider::GenericProvider()
{

}

void CarpeOmnia::GenericProvider::applyBPF(char filter_exp[])
{
    if (mPcap == NULL)
        throw runtime_error("pcap handle must be initialised before applying a BPF");

    struct bpf_program fp;		// The compiled filter expression

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
