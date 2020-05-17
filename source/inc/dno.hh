#ifndef DNO_HH
#define DNO_HH

#include "powierzchnia.hh"

class Dno : public Powierzchnia {

protected:

public:

    void rysuj_pow_dna(std::shared_ptr<drawNS::Draw3DAPI> &api){

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
    }


};


#endif 