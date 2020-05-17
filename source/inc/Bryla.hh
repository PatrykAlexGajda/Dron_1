#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include <unistd.h>
#include "Wektor.hh"
#include "MacierzOb.hh"
#include "InterfejsRys.hh"

/*!
* \brief Funkcja czekajaca az uzytkownik wcisnie klawisz 'Enter'
*/
void wait4key() {
  do {
    std::cout << "\n Press 'Enter' to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

/*!
* \brief Klasa definiujaca Bryle w przestrzeni 3D
* Zawiera pola Orientacji bryly wzgledem ukladu osi wspolrzednych 
* oraz wektor wspolrzednych srodka bryly
*/
class Bryla : public InterfejsRysowania {

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

    Bryla(){}

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


/*!
* \brief Metoda usuwajaca narysowana figure przypisana do parametru a
* \param api lacze do gnuplota
* \param a zmienna przypisana do rysunku
*/
    void usun(std::shared_ptr<drawNS::Draw3DAPI> & api, int a){

/*!
* \brief Wywolanie metody usuwajacej figure
*/
        api->erase_shape(a);
    }

};

#endif