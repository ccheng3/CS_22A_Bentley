// This program shows how to use default argument on setting precision
// for some example floating point values

#include <iostream>
#include <iomanip>
using namespace std;

// use default argument in function prototype
void Print_Double(double value, int decPlaces = -1);

int main() {
	Print_Double(0);
	Print_Double(1);
	Print_Double(1.5);
	Print_Double(1.5, 4);
	Print_Double(123456.789);
	Print_Double(123456.789, 2);
	Print_Double(123456.789, 5);
	Print_Double(3.141592654, 5);
	return 0;
}

void Print_Double(double value, int decPlaces) {
	if (decPlaces < 0) {
		cout << value << endl;
	}
	else {
		cout << fixed << setprecision(decPlaces) << value << endl;
	}
	return;
}