#ifndef GENERICPROVIDER_H
#define GENERICPROVIDER_H


namespace CarpeOmnia
{
    class GenericProvider
    {
    public:
        GenericProvider();
        virtual void getnextPacket() = 0;
    };
}
#endif // GENERICPROVIDER_H
