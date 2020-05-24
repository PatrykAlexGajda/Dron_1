#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "Bryla.hh"
#include "Prostopadloscian.hh"
#define B 1

/*!
* \brief Klasa definiujaca graniastoslup, dziedziczy po klasie Bryla,
* Zawiera pola wierzcholkow aktualnych oraz bazowych graniastoslupa
*/
class Graniastoslup : public Bryla{

protected:

/*!
* \brief Wierzcholki bazowe
*/
    Wektor<double, 3> wierzcholki0[12];
/*!
* \brief Wierzcholki aktualne
*/
    Wektor<double, 3> wierzcholki[12];

public:

/*!
* \brief Konstruktor domyslny przypisujacy polozenie bryly wedlug ponizszych wzorow
*/
    Graniastoslup(){

        wierzcholki[0].ustaw(Srodek[0], (Srodek[1] - A), Srodek[2] + B);
        wierzcholki[1].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] + (B*0.5));
        wierzcholki[2].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] - (B*0.5));
        wierzcholki[3].ustaw(Srodek[0], (Srodek[1] - A), Srodek[2] - B);
        wierzcholki[4].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] - (B*0.5));
        wierzcholki[5].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] + (B*0.5));

        wierzcholki[6].ustaw(Srodek[0], (Srodek[1] - A - B), Srodek[2] + B);
        wierzcholki[7].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] + (B*0.5));
        wierzcholki[8].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] - (B*0.5));
        wierzcholki[9].ustaw(Srodek[0], (Srodek[1] - A - B), Srodek[2] - B);
        wierzcholki[10].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] - (B*0.5));
        wierzcholki[11].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] + (B*0.5));

/*!
* \brief przypisanie tych samych danych wierzcholkom bazowym
*/
        for(int i=0;i<12;i++){
            wierzcholki0[i] = wierzcholki[i];
        }
    }

    
/*!
* \brief Konstruktor parametryczny tworzacy bryle o wierzcholkach przesunietych o zadany wektor
* \param xyz wspolrzedne wektora przesuniecia
*/
    Graniastoslup(double x, double y, double z){

        Srodek.ustaw(x, y, z);

        wierzcholki[0].ustaw(Srodek[0], (Srodek[1] - A), Srodek[2] + B);
        wierzcholki[1].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] + (B*0.5));
        wierzcholki[2].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] - (B*0.5));
        wierzcholki[3].ustaw(Srodek[0], (Srodek[1] - A), Srodek[2] - B);
        wierzcholki[4].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] - (B*0.5));
        wierzcholki[5].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A), Srodek[2] + (B*0.5));

        wierzcholki[6].ustaw(Srodek[0], (Srodek[1] - A - B), Srodek[2] + B);
        wierzcholki[7].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] + (B*0.5));
        wierzcholki[8].ustaw(Srodek[0] + (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] - (B*0.5));
        wierzcholki[9].ustaw(Srodek[0], (Srodek[1] - A - B), Srodek[2] - B);
        wierzcholki[10].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] - (B*0.5));
        wierzcholki[11].ustaw(Srodek[0] - (B*sqrt(3)/2), (Srodek[1] - A - B), Srodek[2] + (B*0.5));

        for(int i=0;i<12;i++){
            wierzcholki0[i] = wierzcholki[i];
        }
    }

/*!
* \brief Metoda rysujaca graniastoslup o wierzcholkach aktualnych
* \param api lacze do gnuplota
* \return przypisana do rysunku zmienna
*/
    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api){

        int b = api->draw_polyhedron(vector<vector<Point3D> > {{
        drawNS::Point3D(wierzcholki[0][0], wierzcholki[0][1], wierzcholki[0][2]), 
        drawNS::Point3D(wierzcholki[1][0], wierzcholki[1][1], wierzcholki[1][2]), 
        drawNS::Point3D(wierzcholki[2][0], wierzcholki[2][1], wierzcholki[2][2]), 
        drawNS::Point3D(wierzcholki[3][0], wierzcholki[3][1], wierzcholki[3][2]),
        drawNS::Point3D(wierzcholki[4][0], wierzcholki[4][1], wierzcholki[4][2]), 
        drawNS::Point3D(wierzcholki[5][0], wierzcholki[5][1], wierzcholki[5][2])
        },{
 
        drawNS::Point3D(wierzcholki[6][0], wierzcholki[6][1], wierzcholki[6][2]), 
        drawNS::Point3D(wierzcholki[7][0], wierzcholki[7][1], wierzcholki[7][2]),
        drawNS::Point3D(wierzcholki[8][0], wierzcholki[8][1], wierzcholki[8][2]), 
        drawNS::Point3D(wierzcholki[9][0], wierzcholki[9][1], wierzcholki[9][2]),
        drawNS::Point3D(wierzcholki[10][0], wierzcholki[10][1], wierzcholki[10][2]), 
        drawNS::Point3D(wierzcholki[11][0], wierzcholki[11][1], wierzcholki[11][2])
        }},"red");
        
        //std::cout << Orientacja << std::endl;
        //std::cout << Srodek << std::endl;

        return b;
    }

/*!
* \brief Metoda zmieniajaca wierzcholek graniastoslupa wzgledem srodka oraz orientacji Drona
* \param srodekDrona srodek Drona
* \param macierzDrona orientacja Drona
*/
    void nowy_wierzcholekW(Wektor<double, 3> srodekDrona, MacierzOb macierzDrona){

        for(int i=0;i<12;i++){

            wierzcholki[i] = srodekDrona + macierzDrona * Srodek + macierzDrona * Orientacja * wierzcholki0[i];
        }
    }

/*!
* \brief Metoda zmieniajaca wierzcholki graniastoslupa wzgledem zmiany swoich orientacji lub srodka
*/
    void nowy_wierzcholekO(){

        for(int i=0;i<12;i++){

            wierzcholki[i] = Srodek + (Orientacja * wierzcholki0[i]);
        }
    }
};

#endif