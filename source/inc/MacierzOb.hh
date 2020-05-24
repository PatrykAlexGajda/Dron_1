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
* \brief Metoda sprawdzajaca czy dana macierz jest macierza obrotu
* \param M badana macierz
*/
    void checkM(const Macierz & M) const{

/*!
* \brief Tworzenie macierzy jednostkowej
*/
        Macierz I;
        for(int i=0;i<SIZE;i++){
            I[i][i] = 1;
        }

/*!
* \brief sprawdzenie czy wyznacznik podanej macierzy jest rowny 1 i czy jest ona ortagonalna
*/
        if((M.Wyznacznik() == 1) && (M.Transpozycja() * M == I)){
            std::cout << "Macierz jest macierza obrotu." << std::endl;
        } else {
            std::cerr << "BLAD: Macierz nie jest macierza obrotu! Zamykanie programu." << std::endl;
            exit(1);
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

/*!
* \brief Metoda obracajaca istniejaca macierz obrotu wokol osi y
* \param alfa kat o ktory obroci sie bryla
*/
    void ObrotY(double alfa){

        MacierzOb temp;

        temp[0][0] = cos((alfa*M_PI)/180);
        temp[0][1] = 0;
        temp[0][2] = sin((alfa*M_PI)/180);
        temp[1][0] = 0;
        temp[1][1] = 1;
        temp[1][2] = 0;
        temp[2][0] = -sin((alfa*M_PI)/180);
        temp[2][1] = 0;
        temp[2][2] = cos((alfa*M_PI)/180);

        *this = temp;
    }
};

#endif