#ifndef WIRNIK_HH
#define WIRNIK_HH

#include "Graniastoslup.hh"

/*!
* \brief Klasa definiujaca Wirnik, dziedziczy po klasie Graniastoslup
*/
class Wirnik : public Graniastoslup{

protected:

public:

/*!
* \brief Konstruktor domyslny
*/
    Wirnik(){}

/*!
* \brief Konstruktor tworzacy zmienna typu Wirnik o podanym w parametrze srodku
* \param xyz wspolrzedne przesuniecia srodka od swojego pierwotnego punktu zerowego
*/
    Wirnik(double x, double y, double z){

        this->Srodek.ustaw(x, y, z);
        Graniastoslup g(x, y, z);
    }

/*!
* \brief Metoda obraca wirnik wzgledem osi y
* \param api lacze do gnuplota
*/
    void obracanieW(std::shared_ptr<drawNS::Draw3DAPI> & api){
        
/*!
* \brief Petla tworzaca animacje obortu wirnika
*/
        for(int i=0;i<40;i++){

            usun(api, indeks[1]);
            MacierzOb M;
            M.ObrotY(9);
            ZmianaOrientacji(M);
            nowy_wierzcholekO();
            indeks[1] = rysuj(api);
            usleep(80000);
        }
    }

/*!
* \brief Metoda powoduje ruszenie sie wirnika wzgledem Drona
* \param api lacze do gnuplota
* \param distance dystans o ktory przesunie sie wirnik (ten sam co dla drona)
* \param srodekDron srodek Drona
* \param orientacjaDron orientacja drona
*/
    void ruchW(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance, Wektor<double, 3> srodekDron, MacierzOb orientacjaDron){

        double a = distance/40;
        Wektor<double, 3> w(0, a ,0);

/*!
* \brief Petla tworzaca animacje ruchu wirnika
*/
        for(int i=0;i<40;i++){

            usun(api, indeks[1]);
            PrzesunSrodek(w);
            nowy_wierzcholekW(srodekDron, orientacjaDron);
            indeks[1] = rysuj(api);
            usleep(80000);
        } 
    }
};

#endif 