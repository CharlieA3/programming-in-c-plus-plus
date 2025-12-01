#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// addition
	Vector2D v1(Vector2D(1.1, 2.1) + Vector2D(1.1, 1.0));
	cout << v1 << endl;
	
	v1 += Vector2D(1.1, 1.0);
	cout << v1 << endl;
}
