#include <iostream>

#include <pcap.h>

#include "pcapfileprovider.h"

using namespace std;
using namespace CarpeOmnia;

int main()
{
    cout << "Hello World!" << endl;
    GenericProvider * pfp;

    pfp = new PcapFileProvider();
    pfp->getnextPacket();
    return 0;
}
