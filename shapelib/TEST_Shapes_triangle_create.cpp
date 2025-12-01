#include "Vector2D.hpp"
#include "Shapes.hpp"
#include <memory>
#include <iomanip>
#include <iostream>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// create shape
	Triangle tri(Vector2D(1.1, 2.2), Vector2D(2.2, 3.3), Vector2D(3.3, 4.4));
}
