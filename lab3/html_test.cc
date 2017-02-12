#include "html.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Running html_test!" << endl;

	filebuf fb;
	fb.open("test.html", ios::in);
	istream is(&fb);
	TagRemover tr1(is);
	TagRemover tr(cin);
	tr.print(cout);
}

