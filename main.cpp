#include <iostream>

#include "pcapfileprovider.h"
#include <stdexcept>

#include <glog/logging.h>
#include <config4cpp/Configuration.h>

using namespace std;
using namespace CarpeOmnia;
using namespace config4cpp;

void init_logging(char** argv)
{
    google::InitGoogleLogging(argv[0]);
}

void init_config_manager(Configuration * cfg)
{
    cfg = Configuration::create();
}

int main(int argc, char** argv)
{
    init_logging(argv);
    Configuration * cfg;
    init_config_manager(cfg);


    LOG(INFO) << "Intialising CarpeOmnia\n";
    GenericProvider * pfp;

    try {
        pfp = new PcapFileProvider();
    } catch (std::exception const & e)
    {
        LOG(INFO) <<"Exiting after fatal exception caught: " << e.what() << endl;
        return (2);
    }

    pfp->getnextPacket();
    return 0;
}
