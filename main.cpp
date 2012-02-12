#include <iostream>

#include "pcapfileprovider.h"
#include <stdexcept>

using namespace std;
using namespace CarpeOmnia;

int main()
{
    cout << "Hello World!" << endl;
    GenericProvider * pfp;

    try {
        pfp = new PcapFileProvider();
    } catch (std::exception const & e)
    {
        cout <<"Exiting after fatal exception caught: " << e.what() << endl;
        return (2);
    }

    pfp->getnextPacket();
    return 0;
}
