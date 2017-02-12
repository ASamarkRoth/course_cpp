#include "date.h"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

template <typename T>
std::string toString(T& obj) {
	cout << "toString" << endl;
	std::stringstream ss;

	ss << obj;

	return ss.str();

}

int main() {
	double d = 1.234;
	Date today;
	std::string sd = toString(d);
	std::string st = toString(today);

	cout << "Date: " << st << " double: " << sd << endl;
	return 0;
}


