#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include "Wektor.hh"
#include "MacierzOb.hh"
#include "InterfejsRys.hh"

/*!
* \brief Klasa definiujaca Bryle w przestrzeni 3D
* Zawiera pola Orientacji bryly wzgledem ukladu osi wspolrzednych 
* oraz wektor wspolrzednych srodka bryly
*/
class Bryla {

protected:

/*!
* \brief Macierz obrotu przechowujaca informacje o orientacji bryly
*/
    MacierzOb Orientacja;
/*!
* \brief Wektor wspolrzednych srodka
*/
    Wektor<double, 3> Srodek;

public: 

/*!
* \brief Metoda zmieniajaca orientacje o podana macierz obrotu
* \param mOb macierz obrotu zawierajaca kat obrotu dla bryly wzgledem pewnej osi
* \return zmieniona orientacja bryly
*/
    MacierzOb ZmianaOrientacji(const MacierzOb & mOb){
        
        Orientacja *= mOb;
        return Orientacja;
    }
/*!
* \brief Metoda przesuwa srodek o dany wektor
* \param W wektor przesuwajacy srodek wedlug jednej osi
* \return przesuniety srodek bryly
*/
    Wektor<double, 3> PrzesunSrodek(const Wektor<double, 3> & W){

        Srodek = Srodek + Orientacja * W;
        return Srodek;
    }
};

#endif