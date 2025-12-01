#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// get elements
	const Vector2D v1(6.6, 7.1);
	cout << v1.getX() << " " << v1.getY() << endl;
}
