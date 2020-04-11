// This program processes the Assignment 7 input file and outputs 
// the student grade report, but uses Arrays

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const int ARRAY_NUM_ELEMENTS = 20;
const int LAST_DATA_COLUMN_INDEX = 14;
const int FIRST_ASSIGN_DATA_INDEX = 1;
const int LAST_ASSIGN_DATA_INDEX = 11;
const int MAX_POINTS = 400;

int main() {
	int data_array[ARRAY_NUM_ELEMENTS];
	int file_val;
	int student_assign_sum = 0;
	int total_sum = 0;
	int working_index_increment = 1;
	int lowest_assign_score;
	int percent_grade;
	char letter_grade = 32;
	char letter_grade_mod = 32;

	// create an input file stream object, open input file
	ifstream input_File("ass7data.txt");

	ofstream output_File("student_data_report_hw9.txt");

	if (input_File.fail()) {
		cout << "Error in opening input file. Please check\n";
	}
	/*if (output_File.fail()) {
		cout << "Error in opening output file. Please check\n";
	}*/

	cout << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin LEx Total"
		  << "  Pct Gr\n";
	cout << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  --- --- "
		  << "-----  --- --\n";

	while (input_File >> file_val) {
		cout << "Student: " << setw(8) << setfill('0') << file_val << endl;
		working_index_increment = 1;

		// read in each student data
		data_array[0] = file_val;
		for (int counter = 1; counter <= LAST_DATA_COLUMN_INDEX; ++counter) {
			input_File >> file_val;
			data_array[counter] = file_val;
		}

		// calc and store assignment total
		student_assign_sum = 0;
		for (int counter = FIRST_ASSIGN_DATA_INDEX; 
			counter <= LAST_ASSIGN_DATA_INDEX; ++counter) {
			student_assign_sum += data_array[counter];

			// find the lowest assignment score to drop 
			if (counter == FIRST_ASSIGN_DATA_INDEX) {
				lowest_assign_score = data_array[FIRST_ASSIGN_DATA_INDEX];
			}
			else {
				if (data_array[counter] < lowest_assign_score) {
					lowest_assign_score = data_array[counter];
				}
			}
		}
		student_assign_sum -= lowest_assign_score;
		data_array[LAST_DATA_COLUMN_INDEX + working_index_increment] 
				= student_assign_sum;
		++working_index_increment;
		cout << "Assignment total is: " << student_assign_sum << "\n  ";

		// calculate and store total points
		total_sum = 0;
		for (int counter = LAST_ASSIGN_DATA_INDEX + 1;
		 counter <= LAST_DATA_COLUMN_INDEX; ++counter) {
			total_sum += data_array[counter];
		}
		total_sum += student_assign_sum;
		data_array[LAST_DATA_COLUMN_INDEX + working_index_increment] = total_sum;
		cout << "Total sum is: " << total_sum << "  " << endl;
		++working_index_increment;

		// calculate, store percent grade
		percent_grade = round((static_cast<double>(total_sum) / MAX_POINTS) 
										* 100);
		cout << "Percent Grade: " << percent_grade << " " << endl;
		data_array[LAST_DATA_COLUMN_INDEX + working_index_increment] 
			= percent_grade;
		++working_index_increment;

		// calculate, store letter grade
		if ((percent_grade <= 100) && (percent_grade >= 90)) {
			letter_grade = 'A';
		}
		else if ((percent_grade <= 89) && (percent_grade >= 80)) {
			letter_grade = 'B';
		}
		else if ((percent_grade <= 79) && (percent_grade >= 70)) {
			letter_grade = 'C';
		}
		else if ((percent_grade <= 69) && (percent_grade >= 60)) {
			letter_grade = 'D';
		}
		else {
			letter_grade = 'F';
		}
		data_array[LAST_DATA_COLUMN_INDEX + working_index_increment] 
				= letter_grade;
			++working_index_increment;
		cout << static_cast<char>(letter_grade);

		// calculate, store letter grade mod
		if ((percent_grade == 100) || (percent_grade == 99) ||
			(percent_grade == 100) || (percent_grade == 89) || 
			(percent_grade == 88) || (percent_grade == 79) || 
			(percent_grade == 78) || (percent_grade == 69) ||
			(percent_grade == 68)) {
			letter_grade_mod = '+';
		}
		else if ((percent_grade == 91) || (percent_grade == 90) || 
			(percent_grade == 81) || (percent_grade == 80) || 
			(percent_grade == 71) || (percent_grade == 70) || 
			(percent_grade == 61) || (percent_grade == 60)) {
			letter_grade_mod = '-';
		}
		else {
			letter_grade_mod = 32;
		}
		data_array[LAST_DATA_COLUMN_INDEX + working_index_increment] 
				= letter_grade_mod;
		cout << static_cast<char>(letter_grade_mod) << endl;
	}

	// close the input file
	input_File.close();
	return 0;
} 