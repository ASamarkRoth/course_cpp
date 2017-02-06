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
	string line, word, trigram;
	size_t nbr_trigrams;
	unsigned int counter = 0;
	vector<string> trigrams;

	ifstream read_stream("words.txt");
	while(getline(read_stream, line, '\n')) {
		ss << line;
		ss >> word >> nbr_trigrams;
		if(word.size() > 25) {
			ss.clear();
			ss.str("");
		}
		all_words.insert(word);
		trigrams.resize(nbr_trigrams);
		for(size_t i = 0; i != nbr_trigrams; ++i) {
			ss >> trigram;
			trigrams[i] = trigram;
		}
		Word tri_word(word, trigrams);
		//tri_word.Print();
		++counter;
		ss.clear();
		ss.str("");
		words[word.size()-1].push_back(tri_word);
		//if(counter > 50) break;
	}
	//this->Print();
}

bool Dictionary::contains(const string& word) const {
	//cout << "count = " << all_words.count(word) << endl;
	return all_words.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

vector<string> Dictionary::get_trigrams(string word) const {
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

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	// this function is const -> calls here need also be const, e.g. Word::Print(). Hmm?
	cout << "Running add_trigram_suggestions" << endl;
	int counter = 0;
	Word this_word(word, get_trigrams(word));
	this_word.Print();
	//size_t a = word.size() - 10;
	//cout << "size = " << word.size() << " and a = " << a << endl;
	//size_t can go negative, however there are no words with size 1 which aren't correct: -> safe to make subtraction!
	for(size_t i =  word.size()-2; i != word.size()+1; ++i) {
		//cout << i << ":" << " matching words " << endl;
		for(auto it = words[i].begin(); it != words[i].end(); ++it) {
			if(this_word.get_matches(it->get_trigrams()) >= static_cast<double>(this_word.get_trigrams().size()/2.)) {
				//it->Print();
				//cout << "Match: " << it->get_word() << endl;
				suggestions.push_back(it->get_word());
				++counter;
				//cout << "trigram size = " << this_word.get_trigrams().size() << endl;
				//cout << "size = " << static_cast<double>(this_word.get_trigrams().size()/2.) << endl;
			}
			//if(counter > 10) break;
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	cout << "Ranking the suggestions..." << endl;

	vector<pair<int, string>> ranks;

	//cout << "Evaluating cost ... " << endl;
	for(auto suggested : suggestions) {
		ranks.push_back(make_pair(determine_cost(suggested, word), suggested));
		cout << "Cost, suggested = " << determine_cost(suggested, word) << ", " << suggested << endl;
	}
	//Using a lambda functor
	sort(ranks.begin(), ranks.end(), [](const pair<int, string> &left, const pair<int, string> &right) {return left.first < right.first;});

	//cout << "Sorting wrt cost ... " << endl;
	for(auto rank : ranks) {
		//cout << "Cost, suggested = " << rank.first << ", " << rank.second << endl;
	}
	for(size_t i = 0; i != suggestions.size(); ++i) {
		suggestions[i] = ranks[i].second;
	}

}

int Dictionary::determine_cost(string suggest_word, const string word) const {
	int a;
	int d[26][26];
	d[0][0] = 0;
	for(int i = 1; i != 26; ++i) {
		d[i][0] = i;
		d[0][i] = i;
	}
	for(size_t i = 1; i != word.size()+1; ++i) {
		for(size_t j = 1; j != suggest_word.size()+1; ++j) {
			//cout << "(i, j) = ( " << i << ", " << j << ")" << endl;
			//cout << "d[i-1][j-1] = " << d[i-1][j-1] << " d[i-1][j] = " << d[i-1][j] << " d[i][j-1] = " << d[i][j-1] << endl;
			if(word[i-1] == suggest_word[i-1]) a = d[i-1][j-1];
			else a = d[i-1][j-1]+1;
			//cout << "a1 = "  << a << endl;
			if(d[i-1][j]+1 < a) a = d[i-1][j]+1;
			//cout << "a3 = " << a << endl;
			if(d[i][j-1]+1 < a) a = d[i][j-1]+1;
			//cout << "a4 = " << a << endl;
			d[i][j] = a;
		}
	}

	return d[word.size()][suggest_word.size()];
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	cout << "Trimming suggestions ... " << endl;

	vector<string> to_remove;

	bool remove;

	for(size_t i = 0; i != suggestions.size(); ++i) {
		remove = false;
		//cout << "Suggestions[i] = " << suggestions[i] << endl;
		for(size_t j = 0; j != suggestions.size(); ++j) {
			//cout << "compare = " << suggestions[j] << endl;
			if(suggestions[i] == suggestions[j]) cout << suggestions[i] << " = " << suggestions[j] << endl;
			else if(suggestions[i].substr(0,suggestions[i].size()-1).compare(suggestions[j]) == 0) {
				//cout << "suggestions[i] is a subset of " << suggestions[i] << " =partof " << suggestions[j] << endl;
				//cout << "Removing " << *(suggestions.begin()+i) << endl;
				remove = true;
				break;
			}
		}
		if(remove) {
			suggestions.erase(suggestions.begin()+i);
			--i;
		}
	}


	//suggestions.resize(5);



}

void Dictionary::Print() const {
	cout << "Dictionary words: " << endl;
	for(size_t i = 0; i != MAX_LENGTH_WORD; ++i) {
		cout << i+1 << ": " << endl;
		for(auto it = words[i].begin(); it!= words[i].end(); ++it) {
			it->Print();
		}
	}
}



