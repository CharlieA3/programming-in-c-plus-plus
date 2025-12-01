#include "Vector2D.hpp"
#include "Shapes.hpp"
#include <memory>
#include <iomanip>
#include <iostream>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// create and display shape
	Circle cir(Vector2D(1.1, 2.2), 3.3);
	
	const Shape & shp = cir;
	shp.display(cout) << endl;
}
