#include <iostream>
#include <cstdlib>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv) {
	if(argc != 1) {
		std::cout << "Please no input!" << std::endl;
		exit(EXIT_FAILURE);
	}

	//int M(atoi(argv[1]));

	const int M(100000);
	//const int M(20+1);

	string primes(M, 'P');
	primes.replace(0,2,"CC");

	size_t counter(1);
	size_t no_prime(0);

	counter = primes.find_first_of("P", counter+1);
	while(counter != string::npos) {
		//cout << "Counter = " << counter << endl;
		//cout << "Division = " << static_cast<int>(M/counter) << endl;

		for(int j = 2; j <= static_cast<int>(M/counter); ++j) {
			no_prime = counter*j;
			//cout << "C = " << no_prime << endl;
			primes[no_prime] = 'C';
		}
		counter = primes.find_first_of("P", counter+1);
	}

	for(int j = 0; j < 101; ++j) {
		cout << (j % 10);
	}
	cout << endl;
	for(int j = 0; j < 101; ++j) cout << primes[j];
	cout << endl;
	//for(int j = 0; j <= M; ++j) cout << j << primes[j] << endl;

	cout << "Largest prime: " << primes.rfind("P") << endl;

	return 0;
}
