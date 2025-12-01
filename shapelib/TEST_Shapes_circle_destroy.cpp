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
	unique_ptr<Shape> ps1(new Circle(Vector2D(1.1, 2.2), 3.3));
}
