#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;

//Why do we pass by reference?
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
	//cout << "Getting matches" << endl;
	for(unsigned int i = 0; i != trigrams.size(); ++i) {
		if(it_trigram == t.end()) {
			//cout << "At iterator end!" << endl;
			break;
		}
		while(true) {
			++counter;
			compare = trigrams[i].compare(*it_trigram);
			//cout << "this_trigram: " << trigrams[i] << " and compare with: " << *it_trigram << endl;
			//cout << "compare = " << compare << endl;
			if(compare == 0) {
				++matches;
				++it_trigram;
				break;
			}
			else if(compare > 0) {
				++it_trigram;
				if(it_trigram == t.end()) break;
			}
			else {
				break;
			}
			//if(counter > 10) break;
		}

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
