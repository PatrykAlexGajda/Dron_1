#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include <unistd.h>


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
    void ruch_plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &api, double alfa, double distance){

/*!
* \brief dzielenie w celu zwiekszenia plynnosci animacji
*/
        double a = distance/100;
/*!
* \brief ruch do przodu odbywa sie wzgledem osi Y
*/
        Wektor<double, 3> w(0, a ,0);
        MacierzOb mObZ;
        mObZ.ObrotZ(alfa);
        ZmianaOrientacji(mObZ);

/*!
* \brief Petla rysuje przemieszczenie sie drona
*/
        for(int i=0;i<100;i++){

            int a = rysuj(api);

            usleep(30000);
            PrzesunSrodek(w);
            nowy_wierzcholek();
            usun(api, a);
        } 
    }

/*!
* \brief Metoda pozwalajaca na sterowanie dronem obracajacym sie wokol osi X
* \param api lacze do gnuplota
* \param alfa kat o ktory obroci sie dron
* \param distance dystans o jakie przesunac sie ma dron
*/
    void ruch_gora_dol(std::shared_ptr<drawNS::Draw3DAPI> &api, double alfa, double distance){

        double a = distance/100;

        Wektor<double, 3> w(0, a ,0);
        MacierzOb mObX;
        mObX.ObrotX(alfa);
        ZmianaOrientacji(mObX);

        for(int i=0;i<100;i++){

            int a = rysuj(api);

            usleep(30000);
            PrzesunSrodek(w);
            nowy_wierzcholek();
            usun(api, a);
        } 
    }

};

#endif
