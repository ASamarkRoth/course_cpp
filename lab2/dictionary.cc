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
		all_words.insert(word);
		++counter;
		//if(counter > 20) break;
	}
}

bool Dictionary::contains(const string& word) const {
	//cout << "count = " << all_words.count(word) << endl;
	return all_words.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}

vector<string> Dictionary::get_trigrams(string word) {
	vector<string> trigrams;
	if(word.length() < 3) {
		trigrams = {};
	}
	else {
		trigrams.resize(word.length()-2);
		for(unsigned int i = 0; i != word.length()-2; ++i) {
			trigrams[i] = word.substr(i,3);
		}
		sort(trigrams.begin(), trigrams.end(), less<string>());
	}

	return trigrams;

}




