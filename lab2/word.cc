#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return string(word);
}

unsigned int Word::get_matches(const vector<string>& t) const {
	//Compare the elements of two vectors, use the fact that they both are in alphabetical order
	return 0;
}
