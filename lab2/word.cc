#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;

//Why do we pass by reference?
Word::Word(const string& w, const vector<string>& t) : word(w), trigrams{t}{
}

string Word::get_word() const {
	return string(word);
}

unsigned int Word::get_matches(const vector<string>& t) const {
	//Compare the elements of two vectors, use the fact that they both are in alphabetical order
	unsigned int matches = 0;
	int compare;
	auto it_trigram = t.begin();
	cout << "Getting matches" << endl;
	for(unsigned int i = 0; i != trigrams.size(); ++i) {
		while(true) {
			compare = trigrams[i].compare(*it_trigram);
			cout << "this_trigram: " << trigrams[i] << " and compare with: " << *it_trigram << endl;
			cout << "compare = " << compare << endl;
			if(compare == 0) {
				++matches;
				++it_trigram;
				break;
			}
			else if(compare > 0) {
				++it_trigram;
			}
			else {
				break;
			}
		}

	}
	/*
	for(auto this_trigram = trigrams.begin(); this_trigram != trigrams.end(); ++this_trigram) {
		cout << "this_trigram: " << *this_trigram << endl;
		compare = to_string(*this_trigram).compare(*it_trigram);

	}
	*/

	return matches;
}
