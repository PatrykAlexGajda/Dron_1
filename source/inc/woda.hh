#ifndef WODA_HH
#define WODA_HH

#include "powierzchnia.hh"

class Woda : public Powierzchnia{

protected:

public:

    void rysuj_pow_wody(std::shared_ptr<drawNS::Draw3DAPI> &api){

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
    }
};



#endif 