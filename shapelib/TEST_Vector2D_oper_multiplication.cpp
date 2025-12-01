#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// multiplication
	Vector2D v1(1.1, 2.2);
	cout << 2.0 * v1 << endl;
	cout << v1 * 3.0 << endl;
	v1 *= 4.0;
	cout << v1 << endl;
}
