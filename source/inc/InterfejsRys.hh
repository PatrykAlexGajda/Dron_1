#ifndef INTERFEJSRYSOWANIA_HH
#define INTERFEJSRYSOWANIA_HH

#include "Dr3D_gnuplot_api.hh"

/*!
* \brief Klasa definiujaca interfejs rysowania,
* zawiera dane potrzebne do rysowania danych figur np ich indeks do usuwania lub rysowania
*/
class InterfejsRysowania{

protected:
    std::shared_ptr<drawNS::Draw3DAPI> rysownik;
    int indeks[3] = {10, 10, 10};

public:

/*  Virtuale generuja undefined reference to vtable oraz undefined reference to InterfejsRysowania::usun / ::rysuj
    Z kolei po przyrownaniu do zera tworzac Dno i Woda w mainie: "klasa abstrakcyjna niedozwolona"

    virtual int rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api);
    virtual void usun(std::shared_ptr<drawNS::Draw3DAPI> & api, int a);

*/

};

#endif