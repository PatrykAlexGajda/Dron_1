#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Wirnik.hh"

/*!
* \brief Zmienne tworzace dwa wirniki z przesunieciem na osi x wzgledem domyslnego polozenia
*/
Wirnik W1(-1.7, 0, 0);
Wirnik W2(1.7, 0, 0);

/*!
* \brief Klasa definiujaca dron, dziedziczy po klasie Prostopadloscian
*/
class Dron : public Prostopadloscian{

protected:

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
    }

/*
* \brief Metoda pozwalajaca na sterowanie dronem po plaszczyznie XY
* \param api lacze do gnuplota
* \param alfa kat o jaki ma obrocic sie dron
* \param distance dystans o jaki przesunac sie ma dron 

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

*/

/*!
* \brief Metoda powodujaca przesuwanie sie Drona wraz z dwoma wirnikami o pewien dystans z animacja
* \param api lacze do gnuplota
* \param distance dystans o jaki przesunie sie dron po skonczeniu animacji
*/
    void RuchR(std::shared_ptr<drawNS::Draw3DAPI> &api, double distance){

        double a = distance/40;
        Wektor<double, 3> w(0,a,0);
        

/*!
* \brief Petla tworzaca wzglednie plynna animacje ruchu drona z wirnikami
*/
        for(int i=0;i<40;i++){

            usun(api, indeks[0]);
            usun(api, indeks[1]);
            usun(api, indeks[2]);
            MacierzOb M;
            M.ObrotY(9);
            W1.ZmianaOrientacji(M);
            W1.nowy_wierzcholekO();
            W2.ZmianaOrientacji(M);
            W2.nowy_wierzcholekO();
            PrzesunSrodek(w);
            nowy_wierzcholek();
            W1.nowy_wierzcholekW(Srodek, Orientacja);
            W2.nowy_wierzcholekW(Srodek, Orientacja);
            indeks[0] = rysuj(api);
            indeks[1] = W1.rysuj(api);
            indeks[2] = W2.rysuj(api);
            usleep(80000);
        }
    }

/*!
* \brief Metoda powodujaca obrot drona wraz z dwoma wirnikami wzgledem danej osi o dany kat alfa z animacja
* \param api lacze do gnuplota
* \param a wybrana os wedlug ktorej nastapi obrot
* \param alfa kat o jaki obroci sie dron po skonczeniu animacji
*/
    void obracanieR(std::shared_ptr<drawNS::Draw3DAPI> & api, char a, double alfa){

/*!
* \brief Kiedy obrot ma nastapic wokol osi x
*/
        if(a == 'x'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                usun(api, indeks[1]);
                usun(api, indeks[2]);
                MacierzOb M;
                M.ObrotX(alfa/40);
                ZmianaOrientacji(M);
                W1.nowy_wierzcholekW(Srodek, Orientacja);
                W2.nowy_wierzcholekW(Srodek, Orientacja);
                nowy_wierzcholek();
                indeks[0] = rysuj(api);
                indeks[1] = W1.rysuj(api);
                indeks[2] = W2.rysuj(api);
                usleep(80000);
                
            }
        }

/*!
* \brief Kiedy obrot ma nastapic wokol osi z
*/
        if(a == 'z'){
            
            for(int i=0;i<40;i++){

                usun(api, indeks[0]);
                usun(api, indeks[1]);
                usun(api, indeks[2]);
                MacierzOb M;
                M.ObrotZ(alfa/40);
                ZmianaOrientacji(M);
                W1.nowy_wierzcholekW(Srodek, Orientacja);
                W2.nowy_wierzcholekW(Srodek, Orientacja);
                nowy_wierzcholek();
                indeks[0] = rysuj(api);
                indeks[1] = W1.rysuj(api);
                indeks[2] = W2.rysuj(api);
                usleep(80000);
                
            }
        }
    }
};

#endif
