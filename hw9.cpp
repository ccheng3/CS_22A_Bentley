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

void Print_Header_Text();
void Print_Current_Student_Summary(const int total_sum, const char letter_grade,
												const int letter_grade_mod, 
												const int percent_grade);
void Calculate_Assignment_Total(int& student_assign_sum, int data_array[], 
											const int ARRAY_NUM_ELEMENTS);
void Calculate_Total_Course_Points(int& total_sum, int data_array[], 
											int ARRAY_NUM_ELEMENTS,  
											const int student_assign_sum);
void Calculate_Percent_Grade(const int& total_sum, 
										int& percent_grade);
void Determine_Letter_Grade(const int& percent_grade, char& letter_grade);
void Determine_Letter_Grade_Mod(const int& percent_grade, char& letter_grade_mod);
void Store_Input_Val_In_Array(int data_array[], int ARRAY_NUM_ELEMENTS, 
										int storage_val, int& working_index_increment);

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

	Print_Header_Text();

	while (input_File >> file_val) {
		working_index_increment = 1;
		cout << setw(8) << setfill('0') << file_val << setfill(' ') << "  ";
		
		// read in each student data
		data_array[0] = file_val;
		for (int counter = 1; counter <= LAST_DATA_COLUMN_INDEX; ++counter) {
			input_File >> file_val;
			data_array[counter] = file_val;
		}

		// calc and store assignment total
		Calculate_Assignment_Total(student_assign_sum, data_array, 
											ARRAY_NUM_ELEMENTS);
		Store_Input_Val_In_Array(data_array, ARRAY_NUM_ELEMENTS, 
										student_assign_sum, working_index_increment);
		cout << " " << student_assign_sum;

		// calculate and store total points
		Calculate_Total_Course_Points(total_sum, data_array, ARRAY_NUM_ELEMENTS, 
												student_assign_sum);
		Store_Input_Val_In_Array(data_array, ARRAY_NUM_ELEMENTS, 
										total_sum, working_index_increment);

		// calculate, store percent grade
		Calculate_Percent_Grade(total_sum, percent_grade);
		Store_Input_Val_In_Array(data_array, ARRAY_NUM_ELEMENTS, 
										percent_grade, working_index_increment);

		// calculate, store letter grade
		Determine_Letter_Grade(percent_grade, letter_grade);
		Store_Input_Val_In_Array(data_array, ARRAY_NUM_ELEMENTS, 
										letter_grade, working_index_increment);

		// calculate, store letter grade mod
		Determine_Letter_Grade_Mod(percent_grade, letter_grade_mod);
		Store_Input_Val_In_Array(data_array, ARRAY_NUM_ELEMENTS, 
										letter_grade_mod, working_index_increment);	

		Print_Current_Student_Summary(total_sum, letter_grade, letter_grade_mod, 
												percent_grade);	
	}

	// close the input file
	input_File.close();
	output_File.close();

	return 0;
} 

void Print_Header_Text() {
	cout << "Student   -----   Assignment Grades  -----  Ass  Mid  Fin  LEx Total"
		  << "  Pct Gr\n";
	cout << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  ---  ---  --- "
		  << "-----  --- --\n";
	return;
}

void Print_Current_Student_Summary(const int total_sum, const char letter_grade,
												const int letter_grade_mod, 
												const int percent_grade) {
	cout << setw(6) << total_sum << "  ";
	cout << setw(3) << percent_grade << " ";
	cout << static_cast<char>(letter_grade);
	cout << static_cast<char>(letter_grade_mod) << endl;
	return;
}

void Calculate_Assignment_Total(int& student_assign_sum, int data_array[], 
											const int ARRAY_NUM_ELEMENTS) {
	int lowest_assign_score;
	student_assign_sum = 0;
		
	for (int counter = FIRST_ASSIGN_DATA_INDEX; 
		counter <= LAST_ASSIGN_DATA_INDEX; ++counter) {
		cout << setw(2) << data_array[counter] << " ";
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
	return;
}

void Calculate_Total_Course_Points(int& total_sum, int data_array[], 
											int ARRAY_NUM_ELEMENTS,  
											const int student_assign_sum) {
	total_sum = 0;
	for (int counter = LAST_ASSIGN_DATA_INDEX + 1;
	 counter <= LAST_DATA_COLUMN_INDEX; ++counter) {
	 	cout << "  " << setw(3) << data_array[counter];
		total_sum += data_array[counter];
	}
	total_sum += student_assign_sum;
	return;
}

void Calculate_Percent_Grade(const int& total_sum, int& percent_grade) {
	percent_grade = round((static_cast<double>(total_sum) / MAX_POINTS) 
										* 100);
	return;
}

void Determine_Letter_Grade(const int& percent_grade, char& letter_grade) {
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
	return;
}

void Determine_Letter_Grade_Mod(const int& percent_grade, 
											char& letter_grade_mod) {
	if ((percent_grade == 100) || (percent_grade == 99) ||
			(percent_grade == 100) || (percent_grade == 89) || 
			(percent_grade == 88) || (percent_grade == 79) || 
			(percent_grade == 78) || (percent_grade == 69) ||
			(percent_grade == 68)) 
	{
			letter_grade_mod = '+';
	}
	else if ((percent_grade == 91) || (percent_grade == 90) || 
		(percent_grade == 81) || (percent_grade == 80) || 
		(percent_grade == 71) || (percent_grade == 70) || 
		(percent_grade == 61) || (percent_grade == 60)) 
	{
		letter_grade_mod = '-';
	}
	else {
		letter_grade_mod = 32;
	}
	return;
}

void Store_Input_Val_In_Array(int data_array[], int ARRAY_NUM_ELEMENTS, 
										int storage_val, int& working_index_increment) {
	data_array[LAST_DATA_COLUMN_INDEX + working_index_increment] = storage_val;
	++working_index_increment;
	return;
}
