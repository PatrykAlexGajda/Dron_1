#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Bryla.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"
#include "InterfejsRys.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

/*!
* \brief Funkcja czekajaca az uzytkownik wcisnie klawisz 'Enter'
*/
void wait4key() {
  do {
    std::cout << "\n Press 'Enter' to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main(){
  
/*!
* \brief Lacze z gnuplotem tworzy rysownik 3D o podanych wymiarach
*/
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-300,300,-300,300,-300,300,0));

  char quit;
  Dron D;

/*!
* \brief Petla komunikuje sie z uzytkownikiem i na podstawie wprowadzonych w terminalu danych rysuje przemieszczanie sie drona po plaszczyznie XY
* Konczy dzialanie po wprowadzeniu litery 'h' lub 'q'
*/
  while(quit != 'q' && quit != 'h'){

    double kat = 0;
    double odl = 0;

    std::cout << "Podaj kat obrotu (dodatni - obrot w lewo, ujemny - w prawo): ";
    std::cin >> kat;
    std::cout << "Podaj odleglosc przesuniecia (obszar rysownika - 300x300x300): ";
    std::cin >> odl;

    D.ruch_plaszczyzna(api, kat, odl);

    std::cout << "Kontynuuj - dowolna litera + 'Enter' \nWylacz program - 'q' + 'Enter' \nZmien wysokosc 'h' + 'Enter' " << std::endl;
    std::cin >> quit;

    if(quit != 'h' && quit != 'q'){
    }
  }

/*!
* \brief Petla komunikuje sie z uzytkownikiem, na podstawie wprowadzaonych w terminalu danych rysuje przemieszczenie sie drona obracajacego sie wzgledem osi Z
* Konczy dzialanie po wprowadzeniu litery 'q'
*/
  while(quit != 'q'){

    double kat = 0;
    double odl = 0;

    std::cout << "Podaj kat obrotu (dodatni - do gory, ujemny - w dol): ";
    std::cin >> kat;
    std::cout << "Podaj odleglosc przesuniecia (obszar rysownika - 300x300x300): ";
    std::cin >> odl;

    D.ruch_gora_dol(api, kat, odl);

    std::cout << "Kontynuuj - dowolna litera + 'Enter' " << "\nWylacz program - 'q' + 'Enter' " << std::endl;
    std::cin >> quit;

    if(quit != 'q'){
    }
  }


  
/*  

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać

*/

}
