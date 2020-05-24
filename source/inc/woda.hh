#ifndef WODA_HH
#define WODA_HH

#include "powierzchnia.hh"

/*!
* \brief Klasa definiujaca Woda, dziedziczy po klasie Powierzchnia
*/
class Woda : public Powierzchnia{

protected:

public:

/*!
* \brief Konstruktor domyslny dla tworzenia zmiennej typu Woda
*/
	Woda(){}

/*!
* \brief Metoda rysujaca powierzchnie wody
* \param api lacze do gnuplota
*/
    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api){

		int a=100;

		api->draw_surface(vector<vector<Point3D> > {{
		drawNS::Point3D(-R*0.8,-R*0.8,R*0.8), drawNS::Point3D(-R*0.8,0,R*0.8), drawNS::Point3D(-R*0.8,R*0.8,R*0.8)
		},{
		drawNS::Point3D(-R*0.4,-R*0.8,R), drawNS::Point3D(-R*0.4,0,R), drawNS::Point3D(-R*0.4,R*0.8,R)       
		},{
		drawNS::Point3D(-0,-R*0.8,R*0.8), drawNS::Point3D(-0,0,R*0.8), drawNS::Point3D(-0,R*0.8,R*0.8)       
		},{
		drawNS::Point3D(R*0.4,-R*0.8,R), drawNS::Point3D(R*0.4,0,R), drawNS::Point3D(R*0.4,R*0.8,R)       
		},{
		drawNS::Point3D(R*0.8,-R*0.8,R*0.8), drawNS::Point3D(R*0.8,0,R*0.8), drawNS::Point3D(R*0.8,R*0.8,R*0.8)       
		}},"blue");

	  return a;
    }
};


#endif 