#include "Vector2D.hpp"
#include "Shapes.hpp"
#include <memory>
#include <iomanip>
#include <iostream>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);

	// create and translate shape
	Circle cir(Vector2D(1.1, 2.2), 3.3);
	
	Shape & shp = cir;
	shp.translate(Vector2D(0.4, 0.5));
	shp.display(cout) << endl;
}
