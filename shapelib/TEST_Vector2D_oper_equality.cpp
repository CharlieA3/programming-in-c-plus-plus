#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// testing (in)equality
	Vector2D v1(1, 2);
	Vector2D v2(3, 4);
	cout << (v1 == v2) << " " << (v1 == v1) << endl;
	cout << (v1 != v2) << " " << (v1 != v1) << endl;
}
