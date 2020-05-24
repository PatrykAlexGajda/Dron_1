#ifndef DNO_HH
#define DNO_HH

#include "powierzchnia.hh"

/*!
* \brief Klasa definiujaca Dno, dziedziczy po klasie Powierzchnia
*/
class Dno : public Powierzchnia {

protected:

public:

/*!
* \brief Konstruktor domyslny dla tworzenia zmiennej typu Dno
*/
	Dno(){}

/*!
* \brief Metoda rysujaca powierzchnie dna
* \param api lacze do gnuplota
*/
    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api){

	int a=99;

      api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-R*0.8,-R*0.8,-R*0.8), drawNS::Point3D(-R*0.8,0,-R*0.8), drawNS::Point3D(-R*0.8,R*0.8,-R*0.8)
	  },{
	drawNS::Point3D(-R*0.4,-R*0.8,-R*0.8), drawNS::Point3D(-R*0.4,0,-R*0.8), drawNS::Point3D(-R*0.4,R*0.8,-R*0.8)       
	  },{
	drawNS::Point3D(-0,-R*0.8,-R*0.8), drawNS::Point3D(-0,0,-R*0.8), drawNS::Point3D(-0,R*0.8,-R*0.8)       
	  },{
	drawNS::Point3D(R*0.4,-R*0.8,-R*0.8), drawNS::Point3D(R*0.4,0,-R*0.8), drawNS::Point3D(R*0.4,R*0.8,-R*0.8)       
	  },{
	drawNS::Point3D(R*0.8,-R*0.8,-R*0.8), drawNS::Point3D(R*0.8,0,-R*0.8), drawNS::Point3D(R*0.8,R*0.8,-R*0.8)       
	  }},"yellow");

	  return a;
    }
};


#endif 