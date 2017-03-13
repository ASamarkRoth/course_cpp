#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string name);

int main() {

	string name;
	cout << "Input name to check: ";
	cin >> name;

	cout << "is_palindrome = "<< is_palindrome(name) << endl;

	return 0;

}

bool is_palindrome(string name) {
	string reverse(name);
	for(int j = 0; j < name.size(); ++j) {
		reverse[j] = name[name.size()-1-j];
	}
	cout << "Reverse = " << reverse << endl;
	if(name.compare(reverse) == 0) return true;
	else return false;
}


