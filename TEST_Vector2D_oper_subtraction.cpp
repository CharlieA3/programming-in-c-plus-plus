#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// subtraction
	Vector2D v1(Vector2D(5.5, 6.1) - Vector2D(1.1, 1.0));
	cout << v1 << endl;
	
	v1 -= Vector2D(-1.1, -1.0);
	cout << v1 << endl;
}
