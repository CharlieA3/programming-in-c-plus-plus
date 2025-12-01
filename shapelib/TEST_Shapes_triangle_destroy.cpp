#include "Vector2D.hpp"
#include "Shapes.hpp"
#include <memory>
#include <iomanip>
#include <iostream>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// this creates and destroys through an Shape pointer
	unique_ptr<Shape> ps1(new Triangle(Vector2D(1.1, 2.2), Vector2D(2.2, 3.3), Vector2D(3.3, 4.4)));
}
