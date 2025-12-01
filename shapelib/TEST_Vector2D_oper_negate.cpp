#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// element-wise negation
	cout << -Vector2D(-1.1, -2.1) << endl;
}
