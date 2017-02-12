#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <string>
#include <iomanip> // for setw and setfill

using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::setfill;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
	if(month < 1 || month > 12) {
		cout << "Please provide a \"good\" month" << endl;
		exit(EXIT_FAILURE);
	}
	if(day < 1 || day > daysPerMonth[month-1]) {
		cout << "Please provide a \"good\" day" << endl;
		exit(EXIT_FAILURE);
	}
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	++day;
	if(day > daysPerMonth[month-1]) {
		if(month == 12) {
			++year;
			month = 1;
		}
		else {
			++month;
		}
		day = 1;
	}
}

//Since they take the user-defined type as the right argument (b in a@b), they must be implemented as non-members.

std::ostream& operator<<(std::ostream& os, const Date& d) {
	os << setw(4) << setfill('0') << d.getYear() << '-';
	os << setw(2) << setfill('0') << d.getMonth() << '-';
	os << setw(2) << setfill('0') << d.getDay();
	return os;
}

std::istream& operator>>(std::istream& is, Date& d) {
	string input;
	is >> input;
	string temp;
	size_t l;

	//cout << "Extraction 1 " << input << endl;

	l = input.find_first_of("-");
	//cout << "l = " << l << endl;
	if(l != 4) {
		is.setstate(std::ios::failbit);
		return is;
	}
	d.year = stoi(input.substr(0,l));
	input.erase(0,l+1);

	//cout << "Extraction 2 " << input << endl;
	l = input.find_first_of("-");
	if(stoi(input.substr(0,l+1)) > 12 || stoi(input.substr(0,l+1)) < 1) {
		is.setstate(std::ios::failbit);
		return is;
	}
	d.month = stoi(input.substr(0,l+1));
	input.erase(0,l+1);

	//cout << "Extraction 3 " << input << endl;
	l = input.find_first_of("-");
	if(l == string::npos) l = input.size()-1;
	if(stoi(input.substr(0, l+1)) > d.daysPerMonth[d.getMonth()] || stoi(input.substr(0,l+1)) < 1) {
		is.setstate(std::ios::failbit);
		return is;
	}
	d.day = stoi(input.substr(0,l+1));
	//is.setstate(std::ios::eofbit);
	return is;
}
