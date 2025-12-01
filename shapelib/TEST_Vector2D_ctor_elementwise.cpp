#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// element-wise initialized
	Vector2D v1(1.1, 2.1);
	cout << v1 << endl;
}
