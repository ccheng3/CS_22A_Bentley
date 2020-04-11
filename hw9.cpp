// This program processes the Assignment 7 input file and outputs 
// the student grade report, but uses Arrays

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ARRAY_NUM_ELEMENTS = 20;

int main() {
	// create an input file stream object 
	int data_array[ARRAY_NUM_ELEMENTS];
	int file_val;
	int student_assign_sum = 0;
	ifstream input_File("ass7data.txt");

	if (input_File.fail()) {
		cout << "Error in opening input file. Please check\n";
	}

	cout << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total"
		  << "  Pct Gr\n";
	cout << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- "
		  << "-----  --- --\n";

	while(input_File >> file_val) {
		data_array[0] = file_val;
		for (int counter = 1; counter < 15; ++counter) {
			input_File >> file_val;
			data_array[counter] = file_val;
		}

		// print assignment total
		student_assign_sum = 0;
		for (int counter = 1; counter < 12; ++counter) {
			student_assign_sum += data_array[counter];
		}
		cout << "Assignment total is: " << student_assign_sum << endl;
	}

	// close the input file
	input_File.close();

	return 0;
}