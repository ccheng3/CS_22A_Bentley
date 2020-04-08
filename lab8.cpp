// This program runs lab exercise 8 spec.

#include <iostream>
#include <cstdlib>
using namespace std;

int random_return(char input_char) {

	switch (input_char) {
		case 'B' :
			return (rand() % 15) + 1;
		case 'I' :
			return (rand() % 15) + 16;
		case 'N' :
			return (rand() % 15) + 31;
		case 'G' :
			return (rand() % 15) + 46;
		case 'O' :
			return (rand() % 15) + 61;
		default :
			return 0; 
	}
}

int main() {
	cout << random_return('B') << endl;
	cout << random_return('I') << endl;
	cout << random_return('N') << endl;
	cout << random_return('G') << endl;
	cout << random_return('O') << endl;
	cout << random_return('Z') << endl;
	return 0;
}