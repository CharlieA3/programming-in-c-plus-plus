#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// set elements
	Vector2D v1(3.3, 4.1);
	v1.setX(5.5);
	v1.setY(6.1);
	cout << v1 << endl;
}
