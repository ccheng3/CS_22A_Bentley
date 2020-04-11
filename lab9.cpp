// This program practices assigning array values, printing array values

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

const int NUM_ELEMENTS = 10;

int main() {
	int num_array[NUM_ELEMENTS];
	int random_even_int;

	// read in 10 random even ints
	for (int index = 0; index < NUM_ELEMENTS; ++index) {
		// find a random even int
		random_even_int = ((rand() % 99) + 2);
		if (random_even_int % 2 != 0) {
			++random_even_int;
		}
		num_array[index] = random_even_int;
	}

	// print out the info 
	for (int index = 0; index < NUM_ELEMENTS; ++index) {
		cout << setw(8) << index << setw(8) << num_array[index]
			  << setw(8) << fixed << setprecision(3) << sqrt(num_array[index])
			  << endl;
	}

	return 0;
}