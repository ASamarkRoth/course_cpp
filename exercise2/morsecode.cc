#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

MorseCode::MorseCode() {
	ifstream file("morse.def");
	string line;
	while(getline(file, line)) {
			istringstream is(line);
			cout << "line = " << line << endl;
	}
}

string MorseCode::encode(const string& text) const {
	return "";
}

string MorseCode::decode(const string& code) const {
	return "";
}
