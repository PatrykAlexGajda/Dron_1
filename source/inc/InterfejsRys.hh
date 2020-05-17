#ifndef INTERFEJSRYSOWANIA_HH
#define INTERFEJSRYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"

class InterfejsRysowania
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
    int indeks[2] = {10, 10};

public:
    InterfejsRysowania() {}
    //virtual int rysuj();
    //virtual int usun();

};

#endif