#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "Macierz.hh"
#include <iostream>
#include <math.h>

#define SIZE 3

/*!
* \brief Klasa definiujaca macierz obrotu dziedziczaca po klasie Macierz
* Przechowuje zmienna typu Macierz 3x3 
*/
class MacierzOb : public Macierz<double, 3>{
public:
/*!
* \brief Konstruktor tworzacy macierz obrotu na identyczna do parametru M
* \param M dowolna macierz 3x3 ktora jest macierza obrotu
*/
    MacierzOb(const Macierz<double, 3> & M) : Macierz<double, 3>(M){

        *this = M;
    }
/*!
* \brief Konstruktor domyslny tworzacy macierz obrotu jako macierz jednostkowa
*/
    MacierzOb(){

        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                tab[i][j] = 0;
            }
        }

        for(int i=0;i<SIZE;i++){
            tab[i][i] = 1;
        }
    }
/*!
* \brief Metoda obracajaca istniejaca macierz obrotu wokol osi Z
* \param alfa kat o ktory obroci sie bryla
*/
    void ObrotZ(double alfa){

        MacierzOb temp;

        temp[0][0] = cos((alfa*M_PI)/180);
        temp[0][1] = -sin((alfa*M_PI)/180);
        temp[0][2] = 0;
        temp[1][0] = sin((alfa*M_PI)/180);
        temp[1][1] = cos((alfa*M_PI)/180);
        temp[1][2] = 0;
        temp[2][0] = 0;
        temp[2][1] = 0;
        temp[2][2] = 1;

        *this = temp;
    }
/*!
* \brief Metoda obracajaca istniejaca macierz obrotu wokol osi X
* \param alfa kat o ktory obroci sie bryla
*/
    void ObrotX(double alfa){

        MacierzOb temp;

        temp[0][0] = 1;
        temp[0][1] = 0;
        temp[0][2] = 0;
        temp[1][0] = 0;
        temp[1][1] = cos((alfa*M_PI)/180);
        temp[1][2] = -sin((alfa*M_PI)/180);
        temp[2][0] = 0;
        temp[2][1] = sin((alfa*M_PI)/180);
        temp[2][2] = cos((alfa*M_PI)/180);

        *this = temp;
    }
};

#endif