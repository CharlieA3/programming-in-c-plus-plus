#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// division
	Vector2D v1(8.8, 2.2);
	cout << v1 / 2 << endl;
	try {
		cout << v1 / 0 << endl;
	} catch (const invalid_argument & e) {
		cout << "caught exception" << endl;
	}
	
	v1 /= 2;
	cout << v1 << endl;
	try {
		v1 /= 0;
		cout << v1 << endl;
	} catch (const invalid_argument & e) {
		cout << "caught exception" << endl;
	}
	cout << v1 << endl;
}
