#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

#define MAX_LENGTH_WORD 25

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	void Print() const;
private:
	std::unordered_set<std::string> all_words;
	std::vector<std::string> get_trigrams(std::string) const;
	std::vector<Word> words[MAX_LENGTH_WORD];

	void add_trigram_suggestions(std::vector<std::string>&, const std::string&) const;
	void rank_suggestions(std::vector<std::string>&, const std::string&) const;
	int determine_cost(std::string, const std::string) const;
	void trim_suggestions(std::vector<std::string>&) const;
};

#endif
