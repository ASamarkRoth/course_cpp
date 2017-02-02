#include <iostream>
#include <fstream>
#include <algorithm> //std::transform
#include <string>
#include <typeinfo>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void make_trigrams(vector<string>&, size_t&, string, size_t);

int main() {

	std::ifstream read_stream("/usr/share/dict/words");

	std::ofstream write_stream("words.txt");

	if(!read_stream) {
		cout << "Dictionary file could not be read!" << endl;
		exit(EXIT_FAILURE);
	}

	string word;
	size_t nbr_trigrams;
	int counter = 0;
	vector<string> trigrams{};

	while(read_stream >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		//Why does this not work?
		//cout << "Type of word is " << std::typeid(word).name() << endl;
		//cout << "Word: " << word << endl;
		make_trigrams(trigrams,nbr_trigrams, word, word.length());
		write_stream << word << " " << nbr_trigrams;
		for(unsigned int i = 0; i != nbr_trigrams; ++i) {
			//cout << "it = " << it << endl;
			write_stream << " " << trigrams[i];
		}
		write_stream << endl;
		++counter;
		//if(counter == 100) break;
	}

	write_stream.close();
	cout << "Counter = " << counter << endl;
	cout << "Read dictionary file and modified it to words.txt" << endl;

	return 0;
}

void make_trigrams(vector<string>& trigrams, size_t& nbr_trigrams, string word, size_t length) {
	//cout << "Making trigrams for word " << word << "of length " << length << endl;
	if(length < 3) {
		trigrams = {};
		nbr_trigrams = 0;
		return;
	}
	trigrams.resize(length-2);
	for(unsigned int i = 0; i != length-2; ++i) {
		trigrams[i] = word.substr(i,3);
	}
	nbr_trigrams = length-2;
	sort(trigrams.begin(), trigrams.end(), std::less<string>());

}
