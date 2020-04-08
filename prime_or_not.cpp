// This program determines if a number less than 100 is prime or not

#include <iostream>

using namespace std;

int main() {
	int counter = 0;

	for (int i = 2; i <= 100; ++i) {
		counter = 0;
		for (int j = 1; j <= 100; ++j) {
			if ((i % j) == 0) {
				++counter;
			}
		}
		// 1 divides a prime number and the prime number divides itself,
		// that's it. (so if counter is 2 then the number is prime)
		if (counter == 2) {
			cout << i << " is prime.\n";
		}
		else {
			cout << i << " is NOT prime.\n";
		}
	}

	return 0;
}