#include "html.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Running html_test!" << endl;

	filebuf fbi;
	fbi.open("test.html", ios::in);
	istream is(&fbi);
	TagRemover tr1(is);
	fbi.close();

	filebuf fbo;
	fbo.open("modified.html", ios::out);
	ostream os(&fbo);
	tr1.print(os);
	fbo.close(); //necessary to close in order to save file

	//How do we get eof for cin? Well <ctrl>+d does it in Linux :)
	//Piping together with cat does it smoothly
	//cat test.html | ./html_test
	TagRemover tr(cin);
	tr.print(cout);
}

