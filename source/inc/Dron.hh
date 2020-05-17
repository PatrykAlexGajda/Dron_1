#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"

/*!
* \brief Klasa definiujaca dron, dziedziczy po klasie Prostopadloscian
*/
class Dron : public Prostopadloscian{

protected:

public:
/*!
* \brief Konstruktor domyslny tworzacy drona jako bryle o domyslnych polach dziedziczonych klas
*/
    Dron(){
        Prostopadloscian p;
        MacierzOb Or;
        Orientacja = Or;
        Wektor<double, 3> sr;
        this->Srodek = sr;   
    }

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
            usleep(50000);

        } 
    }

    void obracanie(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa){

        if(a == 'x'){
            
            for(int i=0;i<100;i++){

                usun(api, indeks[0]);
                MacierzOb M;
                M.ObrotX(alfa/100);
                ZmianaOrientacji(M);
                nowy_wierzcholek();
                indeks[0] = rysuj(api);
                usleep(50000);
            }
        }
    }

};

#endif
