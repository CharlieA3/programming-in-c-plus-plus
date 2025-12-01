#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);

	// copy assignment
	Vector2D v1;
	Vector2D v2;
	v1 = v2 = Vector2D(3.3, 4.1);
	v2 = Vector2D(4.4, 5.1);
	cout << v1 << endl;
	cout << v2 << endl;
}
