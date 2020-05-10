#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Wektor.hh"
#define A 8

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

/*!
* \brief Klasa definiujaca prostopadloscian, dziedziczy po klasie Bryla
* Zawiera dwa pola wektorow przechowujacych wspolrzedne wierzcholkow bryly
*/
class Prostopadloscian : public Bryla{

protected:
/*!
* \brief Wektor przechowujacy wspolrzedne aktualnych wierzcholkow bryly
*/
    Wektor<double, 3> wierzcholek[8];
/*!
* \brief Wektor przechowujacy wspolrzedne wierzcholkow poczatkowych bryly
*/
    Wektor<double, 3> wierzcholek0[8];

public:

/*!
* \brief Konstruktor domyslny ustalajacy wspolrzedne wierzcholkow aktualnych oraz poczatkowych
* wedlug srodka bryly oraz stalej A przechowujacej odleglosc srodka od wierzcholka
*/
    Prostopadloscian(){
        wierzcholek[0].ustaw(Srodek[0] + A, Srodek[1] + A, Srodek[2] + A);
        wierzcholek[1].ustaw(Srodek[0] - A, Srodek[1] + A, Srodek[2] + A);
        wierzcholek[2].ustaw(Srodek[0] - A, Srodek[1] - A, Srodek[2] + A);
        wierzcholek[3].ustaw(Srodek[0] + A, Srodek[1] - A, Srodek[2] + A);
        wierzcholek[4].ustaw(Srodek[0] + A, Srodek[1] + A, Srodek[2] - A);
        wierzcholek[5].ustaw(Srodek[0] - A, Srodek[1] + A, Srodek[2] - A);
        wierzcholek[6].ustaw(Srodek[0] - A, Srodek[1] - A, Srodek[2] - A);
        wierzcholek[7].ustaw(Srodek[0] + A, Srodek[1] - A, Srodek[2] - A);

        wierzcholek0[0].ustaw(Srodek[0] + A, Srodek[1] + A, Srodek[2] + A);
        wierzcholek0[1].ustaw(Srodek[0] - A, Srodek[1] + A, Srodek[2] + A);
        wierzcholek0[2].ustaw(Srodek[0] - A, Srodek[1] - A, Srodek[2] + A);
        wierzcholek0[3].ustaw(Srodek[0] + A, Srodek[1] - A, Srodek[2] + A);
        wierzcholek0[4].ustaw(Srodek[0] + A, Srodek[1] + A, Srodek[2] - A);
        wierzcholek0[5].ustaw(Srodek[0] - A, Srodek[1] + A, Srodek[2] - A);
        wierzcholek0[6].ustaw(Srodek[0] - A, Srodek[1] - A, Srodek[2] - A);
        wierzcholek0[7].ustaw(Srodek[0] + A, Srodek[1] - A, Srodek[2] - A);

    }
    
/*!
* \brief Konstruktor tworzacy prostopadloscian o podanej lokalizacji srodka
* \param srodek wektor przechowujacy wspolrzedne srodka
*/
    Prostopadloscian(const Wektor<double, 3> & srodek){

        Srodek = srodek;

        wierzcholek[0].ustaw(srodek[0] + A, srodek[1] + A, srodek[2] + A);
        wierzcholek[1].ustaw(srodek[0] - A, srodek[1] + A, srodek[2] + A);
        wierzcholek[2].ustaw(srodek[0] - A, srodek[1] - A, srodek[2] + A);
        wierzcholek[3].ustaw(srodek[0] + A, srodek[1] - A, srodek[2] + A);
        wierzcholek[4].ustaw(srodek[0] + A, srodek[1] + A, srodek[2] - A);
        wierzcholek[5].ustaw(srodek[0] - A, srodek[1] + A, srodek[2] - A);
        wierzcholek[6].ustaw(srodek[0] - A, srodek[1] - A, srodek[2] - A);
        wierzcholek[7].ustaw(srodek[0] + A, srodek[1] - A, srodek[2] - A);

        wierzcholek0[0].ustaw(srodek[0] + A, srodek[1] + A, srodek[2] + A);
        wierzcholek0[1].ustaw(srodek[0] - A, srodek[1] + A, srodek[2] + A);
        wierzcholek0[2].ustaw(srodek[0] - A, srodek[1] - A, srodek[2] + A);
        wierzcholek0[3].ustaw(srodek[0] + A, srodek[1] - A, srodek[2] + A);
        wierzcholek0[4].ustaw(srodek[0] + A, srodek[1] + A, srodek[2] - A);
        wierzcholek0[5].ustaw(srodek[0] - A, srodek[1] + A, srodek[2] - A);
        wierzcholek0[6].ustaw(srodek[0] - A, srodek[1] - A, srodek[2] - A);
        wierzcholek0[7].ustaw(srodek[0] + A, srodek[1] - A, srodek[2] - A);
    }

/*!
* \brief Metoda rysujaca prostopadloscian o danym srodku oraz wierzcholkach
* \param api lacze z programem "gnuplot"
* \return liczba calkowita uzywana do przypisania narysowanej figury w programie
*/
    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api){

        int a = api->draw_polyhedron(vector<vector<Point3D> > {{
        drawNS::Point3D(wierzcholek[0][0], wierzcholek[0][1], wierzcholek[0][2]), 
        drawNS::Point3D(wierzcholek[1][0], wierzcholek[1][1], wierzcholek[1][2]), 
        drawNS::Point3D(wierzcholek[2][0], wierzcholek[2][1], wierzcholek[2][2]), 
        drawNS::Point3D(wierzcholek[3][0], wierzcholek[3][1], wierzcholek[3][2])
        },{
        drawNS::Point3D(wierzcholek[4][0], wierzcholek[4][1], wierzcholek[4][2]), 
        drawNS::Point3D(wierzcholek[5][0], wierzcholek[5][1], wierzcholek[5][2]), 
        drawNS::Point3D(wierzcholek[6][0], wierzcholek[6][1], wierzcholek[6][2]), 
        drawNS::Point3D(wierzcholek[7][0], wierzcholek[7][1], wierzcholek[7][2])
        }},"red");
        
        //std::cout << Orientacja << std::endl;
        //std::cout << Srodek << std::endl;

        return a;
    }

/*!
* \brief Metoda tworzaca nowe wspolrzedne wierzcholkow po przesunieciu i zmiany orientacji srodka
*/
    void nowy_wierzcholek(){

        for(int i=0;i<8;i++){

            wierzcholek[i] = Srodek + (Orientacja * wierzcholek0[i]);
        }
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
