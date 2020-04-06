// This program computes the area of a triangle. 

#include <iostream>
using namespace std;

int main() {
	double base, height, area;

	cout << "Enter a base and a height measurements, separated by space.\n";
	cin >> base >> height;

	area = 0.5 * base * height;

	cout << "The area is " << area << endl;

	return 0;
}