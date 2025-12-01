#include <iostream>
using namespace std;

bool mystery1a(int i) {
	if (i < -3) {
		return false;
	} else if (i == 10) {
		cout << "mystery" << endl;
		return true;
	} else {
		return true;
	}
}

void mystery1b() {
	int i = 40;
	int m1b = 7;
	do {
		int z = (m1b * 2) % 41;
		m1b = z;
		-- i;
	} while (mystery1a(i));
}

void mystery2() {
	int m2 = 0;
	for (int ii = 100; ii >= 0; -- ii) {
		int v = 200 / ii;
		m2 += v % 17;
	}
	cout << m2 << endl;
}

int main() {
	cout << "Enter a number:" << endl;

	int input = 0;
	if (cin >> input) {
		mystery1b();
	} else {
		mystery2();
	}
}
