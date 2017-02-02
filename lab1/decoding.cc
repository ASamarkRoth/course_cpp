#include "coding.h"

using namespace std;

int main(int argc, char** argv) {

	if(argc != 2) {
		cerr << "Please provide the name of the file to be coded!" << endl;
		//exit(EXIT_FAILURE);
	}

	string file_name = argv[1];
	cout << "file name is: " << file_name << endl;

	//why not this?
	//ifstream i_filestream = ifstream(file_name.c_str());
	ifstream i_filestream(file_name.c_str());

	string file_output = file_name.substr(0,file_name.find_last_of('.'))+".dec";
	cout << "output file: " << file_output << endl;
	ofstream o_filestream(file_output);

	char ch;

	while(i_filestream.get(ch)) {
		o_filestream << Coding::decode(ch);
	}

	return 0;
}
