#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "Dron.hh"
#define R 16

class Powierzchnia : public InterfejsRysowania{

protected:
    Wektor<double, 3> Wek[15];

public:

    Powierzchnia(){

        for(int i=0;i<15;i++){
            Wek[i].ustaw(0,0,0);
        }
    }
};

#endif