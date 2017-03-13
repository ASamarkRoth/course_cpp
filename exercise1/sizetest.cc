/*
 * Explain the output of the following program.
 */

#include "point.h"

#include <iostream>

using namespace std;

int main() {
	Point p(1, 2);
	int test;
	cout << "sizeof(p)      = " << sizeof(p) << endl;
	cout << "sizeof(int)      = " << sizeof(test) << endl;

	Point* pp = new Point(1, 2);
	cout << "sizeof(pp)     = " << sizeof(pp) << endl;
	cout << "sizeof(*pp)    = " << sizeof(*pp) << endl;

	delete pp;
}
