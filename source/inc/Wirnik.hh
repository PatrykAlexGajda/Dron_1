#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "Graniastoslup.hh"

class Wirnik : public Graniastoslup{

protected:


public:

    Wirnik() {}

    void obracanieW(std::shared_ptr<drawNS::Draw3DAPI> & api){
            
        for(int i=0;i<40;i++){

            usun(api, indeks[1]);
            MacierzOb M;
            M.ObrotY(9);
            ZmianaOrientacji(M);
            nowy_wierzcholekO();
            indeks[1] = rysujW(api);
            usleep(80000);
        }
    }

    void ruchW(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance, Wektor<double, 3> srodekDron, MacierzOb orientacjaDron){

        double a = distance/40;
        Wektor<double, 3> w(0, a ,0);

        for(int i=0;i<40;i++){

            usun(api, indeks[1]);
            PrzesunSrodek(w);
            nowy_wierzcholekW(srodekDron, orientacjaDron);
            indeks[1] = rysujW(api);
            usleep(70000);
        } 
    }
};

#endif 