#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Wirnik.hh"

/*!
* \brief Klasa definiujaca dron, dziedziczy po klasie Prostopadloscian
*/
class Dron : public Prostopadloscian{

protected:
    Wirnik W;

public:
/*!
* \brief Konstruktor domyslny tworzacy drona jako bryle o domyslnych polach dziedziczonych klas
*/
    Dron(){}

/*!
* \brief Konstruktor tworzacy drona o srodku w danym punkcie
* \param center wektor ze wspolrzednymi srodka bryly
*/
    Dron(const Wektor<double, 3> & center){

        this->Srodek = center;
        Prostopadloscian p(center);
        MacierzOb Or;
        Orientacja = Or;        
    }

/*!
* \brief Metoda pozwalajaca na sterowanie dronem po plaszczyznie XY
* \param api lacze do gnuplota
* \param alfa kat o jaki ma obrocic sie dron
* \param distance dystans o jaki przesunac sie ma dron 
*/
    void ruch(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance){

        double a = distance/100;
        Wektor<double, 3> w(0, a ,0);

        for(int i=0;i<100;i++){

            usun(api, indeks[0]);
            PrzesunSrodek(w);
            nowy_wierzcholek();
            indeks[0] = rysuj(api);
            usleep(30000);
        } 
    }

    void obracanie(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa){

        if(a == 'x'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                MacierzOb M;
                M.ObrotX(alfa/40);
                ZmianaOrientacji(M);
                nowy_wierzcholek();
                indeks[0] = rysuj(api);
                usleep(70000);
            }
        }
    }

    void RuchR(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance){

        double a = distance/40;
        Wektor<double, 3> w(0,a,0);

        for(int i=0;i<40;i++){

            usun(api, indeks[0]);
            usun(api, indeks[1]);
            MacierzOb M;
            M.ObrotY(9);
            W.ZmianaOrientacji(M);
            W.nowy_wierzcholekO();
            PrzesunSrodek(w);
            nowy_wierzcholek();
            W.nowy_wierzcholekW(Srodek, Orientacja);
            indeks[0] = rysuj(api);
            indeks[1] = W.rysujW(api);
            usleep(80000);
        }
    }

    void obracanieR(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa){

        if(a == 'x'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                usun(api, indeks[1]);
                MacierzOb M;
                M.ObrotX(alfa/40);
                ZmianaOrientacji(M);
                W.nowy_wierzcholekW(Srodek, Orientacja);
                nowy_wierzcholek();
                indeks[0] = rysuj(api);
                indeks[1] = W.rysujW(api);
                usleep(80000);
                
            }
        }

        if(a == 'z'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                usun(api, indeks[1]);
                MacierzOb M;
                M.ObrotZ(alfa/40);
                ZmianaOrientacji(M);
                W.nowy_wierzcholekW(Srodek, Orientacja);
                nowy_wierzcholek();
                indeks[0] = rysuj(api);
                indeks[1] = W.rysujW(api);
                usleep(80000);
                
            }
        }
    }
};

#endif
