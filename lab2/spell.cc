#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include "dictionary.h"

#include "word.h"

using namespace std;

int main() {
	Dictionary dict;
	string word;
	/*
	word = "seperated";

	const vector<string> trigrams{"all", "kal", "llt"};
	const vector<string> trigrams2{"all", "llt"};

	Word sykel("kallt", trigrams);

	cout << "kallt matches: " << sykel.get_matches(trigrams2) << endl;

	cout << "Contains = " << dict.contains(word) << endl;
	vector<string> suggestions = dict.get_suggestions(word);
		*/

	while (cin >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (dict.contains(word)) {
			cout << "Correct." << endl;
		}
		else {
			vector<string> suggestions = dict.get_suggestions(word);
			if (suggestions.empty()) {
				cout << "Wrong, no suggestions." << endl;
			} else {
				cout << "Wrong. Suggestions:" << endl;
				for (const auto& w : suggestions) {
					cout << "    " << w << endl;
				}
			}
		}
	}
}
