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

	const vector<string> trigrams{"all", "kal", "llt"};
	const vector<string> trigrams2{"all", "fal", "llt"};

	Word sykel("sykel", trigrams2);

	cout << "sykel matches: " << sykel.get_matches(trigrams) << endl;

	while (cin >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (dict.contains(word)) {
			cout << "Correct." << endl;
		} else {
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
