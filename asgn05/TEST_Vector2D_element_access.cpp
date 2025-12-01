#include "Vector2D.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

int
main() {
	cout << fixed << setprecision(2);
	
	// element access
	Vector2D v1;
	v1[0] = 8.8;
	v1[1] = 9.1;
	cout << v1 << endl;
	
	try {
		v1[2] = 0.0;
	} catch (const out_of_range & e) {
		cout << "caught exception" << endl;
	}
	
	const Vector2D & cv1 = v1;
	cout << cv1[0] << " " << cv1[1] << endl;
	
	try {
		cout << cv1[2] << endl;
	} catch (const out_of_range & e) {
		cout << "caught exception" << endl;
	}
}
