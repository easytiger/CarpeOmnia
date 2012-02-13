#ifndef GENERICPROVIDER_H
#define GENERICPROVIDER_H

#include <string>
#include <stdexcept>

using namespace std;

namespace CarpeOmnia
{
    class GenericProvider
    {
    public:
        GenericProvider();
        virtual bool getnextPacket() = 0;

    };
}
#endif // GENERICPROVIDER_H
