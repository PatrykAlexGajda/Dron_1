#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "Graniastoslup.hh"

class Wirnik : public Graniastoslup{

protected:


public:

    Wirnik() {}

    void obracanieW(std::shared_ptr<drawNS::Draw3DAPI> & api, double alfa){
            
        for(int i=0;i<10;i++){

            usun(api, indeks[1]);
            MacierzOb M;
            M.ObrotY(alfa/10);
            ZmianaOrientacji(M);
            indeks[1] = rysujW(api);
            usleep(50000);
        }
    }

    void ruchW(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance){

        double a = distance/100;
        Wektor<double, 3> w(0, a ,0);

        for(int i=0;i<100;i++){

            usun(api, indeks[1]);
            PrzesunSrodek(w);
            nowy_wierzcholekW();
            indeks[1] = rysujW(api);
            usleep(50000);
        } 
    }
};

#endif 