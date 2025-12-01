#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// copy constructor
	Vector2D v0(2.2, 3.1);
	Vector2D v1(v0);
	cout << v1 << endl;
}
