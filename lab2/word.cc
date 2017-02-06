#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;

////Why do we pass by reference?
Word::Word(const string& w, const vector<string>& t) : word(w), trigrams{t} {
}

string Word::get_word() const {
	return string(word);
}

unsigned int Word::get_matches(const vector<string>& t) const {
	//Compare the elements of two vectors, use the fact that they both are in alphabetical order
	unsigned int matches = 0;
	int compare;
	int counter = 0;
	auto it_trigram = t.begin();
	auto it_this_trigram = trigrams.begin();
	//cout << "Getting matches" << endl;
	while(true) {
		if(it_this_trigram == trigrams.end() || it_trigram == t.end()) break;
		++counter;
		compare = (*it_this_trigram).compare(*it_trigram);
		//cout << "this_trigram: " << *it_this_trigram << " and compare with: " << *it_trigram << endl;
		//cout << "compare = " << compare << endl;
		if(compare == 0) {
			++matches;
			++it_trigram;
			++it_this_trigram;
		}
		else if(compare > 0) {
			++it_trigram;
		}
		else {
			++it_this_trigram;
		}
		//if(counter > 10) break;
	}

	return matches;
}

void Word::Print() const {
	cout << "Word: " << word << ", trigrams:";
	for(size_t i = 0; i != trigrams.size(); ++i) {
		cout << " " << trigrams[i];
	}
	cout << endl;
}
