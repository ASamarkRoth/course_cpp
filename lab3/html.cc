#include "html.h"
#include <iostream>
#include <string>

using namespace std;

TagRemover::TagRemover(istream& input) {
	cout << "Removing tags!" << endl;
	string string_in;

	//while(input >> string_in) {
	while(getline(input, string_in)) {
		all += string_in + "\n";
		//all += string_in;
	}

	cout << all << endl;
	//cout << "start = " << all.find_first_of("<") << " end = " << all.find_first_of(">") << endl;

	size_t tag1 = all.find_first_of("<");
	size_t tag2 = all.find_first_of(">");
	while(tag1 != string::npos || tag2 != string::npos) {
		all.erase(tag1, tag2-(tag1-1));
		tag1 = all.find_first_of("<");
	  tag2 = all.find_first_of(">");
	}
	cout << all << endl;


	find_and_replace(all, "&lt;", "<");
	find_and_replace(all, "&gt;", ">");
	find_and_replace(all, "&nbsp;", " ");
	find_and_replace(all, "&amp;", "&");

	cout << all << endl;

}


void TagRemover::find_and_replace(string& all, const string& to_match, const string& replace) {
	size_t first = all.find(to_match);
	while(first != string::npos) {
		all.replace(first, to_match.size(), replace);
		first = all.find(to_match);
	}
}


TagRemover::~TagRemover() {
	cout << "Destructor!" << endl;
}

void TagRemover::print(ostream& output) {
	cout << "Printing processed input!" << endl;
	output << all;

}
