#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <sstream>

using namespace std;

Dictionary::Dictionary() {
	stringstream ss;
	string word;
	ifstream read_stream("words.txt");
	unsigned int counter = 0;
	while(getline(read_stream, word, '\n')) {
		word = word.substr(0, word.find_first_of(" "));
		//cout << "Word: " << word << endl;
		//ss >> word;
		words.insert(word);
		++counter;
		//if(counter > 20) break;
	}
}

bool Dictionary::contains(const string& word) const {
	return true;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
