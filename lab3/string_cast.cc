#include "date.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;

//const required for string literal
template <typename T>
T string_cast(const string& s) {
	cout << "Converting " << s << endl;

	std::stringstream ss;
	//Need to initialise type
	T tmp;

	ss << s;

	ss >> tmp;

	if(!ss) {
		throw std::invalid_argument("string_cast failed!");
	}

	return tmp;
}

int main() {
	cout << "string_casting ... " << endl;
	try{
		int i = string_cast<int>("123");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("1992-06-08");

		cout << "int = " << i << " double = " << d << " date = " << date << endl;

		//double f = string_cast<double>("asjhla.34!");
		Date dates = string_cast<Date>("199-06-08");

	}
	catch (std::invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}

}
