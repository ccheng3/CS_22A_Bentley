// This program adapts from homework 6 and uses functions; it also 
// includes new computations 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const int STUDENT_ID_LENGTH = 8;
const int NUM_ASSIGNMENTS = 11;
const int MAX_POINTS_TOTAL = 400;	

char Get_Letter_Grade(int grade_percentage);		 // returns letter grade 
char Get_Letter_Grade_Mod(int grade_percentage); // returns mod (+/-/none)
void Print_Letter_Grades_Tally(int num_grade_A, int num_grade_B, 
										int num_grade_C, int num_grade_D, 
										int num_grade_F);  // prints tally of class 
																 // letter grades 
void Print_End_Message(string file_name);			 // prints custom end message
void Record_Letter_Grade_Instance(char letter_grade, int& num_grade_A, 
											int& num_grade_B, int& num_grade_C,
											int& num_grade_D, int& num_grade_F);
void Process_Summary_Stats(string input_file_name);

int main() {
	string input_file_name = "ass7data.txt";
	string output_file_name = "student_results_hw7.txt";
	string file_string = "";
	int file_val = 0, 				// current queried value in input file buffer 
		 assign_sum = 0, 				// assignment sum before adjustment
		 adjusted_assign_sum = 0,  // assignment sum after adjustment
		 total_points = 0,			// total points received in class
		 midterm_score = 0,			
		 final_score = 0,
		 lab_score = 0,				// sum of lab exercise points
		 lowest_assign_score = 0,
		 grade_percentage = 0,
		 num_grade_A = 0,				// number of A's
		 num_grade_B = 0,
		 num_grade_C = 0,
		 num_grade_D = 0,
		 num_grade_F = 0;
	char letter_grade = 32;
	char letter_grade_mod = 32;	// + or - or no mod to letter grade

	// create input file stream object, open input file (to read data from)
	ifstream inputFile(input_file_name);

	ofstream outputFile(output_file_name);

	// check both input and output files for successful open
	if (inputFile.fail()) {
		cerr << "Unable to open file: " << input_file_name << endl;
		return(1);
	}

	if (outputFile.fail()) {
		cerr << "Unable to open file: " << output_file_name << endl;
	}

	outputFile << "Student   -----   Assignment Grades  -----  Ass  Mid Fin LEx Total"
		  << "  Pct Gr\n" << "--------  -- -- -- -- -- -- -- -- -- -- --  ---  "
		  << "--- --- --- -----  --- --\n";  

	while (inputFile >> file_string) {
		if (file_string.length() == STUDENT_ID_LENGTH) {
			outputFile << file_string;
			assign_sum = 0;
			for (int counter = 1; counter <= NUM_ASSIGNMENTS; ++counter) {
				inputFile >> file_val;
				if (counter == 1) {
					outputFile << setw(4) << file_val;
					lowest_assign_score = file_val;
				}
				else {
					outputFile << setw(3) << file_val;
					if (file_val < lowest_assign_score) {
						lowest_assign_score = file_val;
					}
				}
				assign_sum += file_val;
			}
			// report the adjusted assignment total 
			adjusted_assign_sum = assign_sum - lowest_assign_score;
			outputFile << setw(5) << adjusted_assign_sum << " ";

			// report the midterm total
			inputFile >> file_val;
			midterm_score = file_val;
			outputFile << setw(4) << midterm_score;
			
			// report final exam total
			inputFile >> file_val;
			final_score = file_val;
			outputFile << setw(4) << final_score;
			
			// report lab exercise total
			inputFile >> file_val;
			lab_score = file_val;
			outputFile << setw(4) << lab_score;

			// report total points accumulated 
			total_points = (adjusted_assign_sum + midterm_score + final_score + 
									lab_score);
			outputFile << " " << setw(5) << total_points;

			// report grade as a percentage
			grade_percentage = round((static_cast<double>(total_points) / 
												MAX_POINTS_TOTAL) * 100);
			outputFile << "  " << setw(3) << grade_percentage << " ";

	
	// determine letter grade plus/minus/none status
	letter_grade_mod = Get_Letter_Grade_Mod(grade_percentage);

	// send final letter grade to output file
	letter_grade = Get_Letter_Grade(grade_percentage);
	outputFile << letter_grade << letter_grade_mod << endl; 

	// record instance of letter grade 
	Record_Letter_Grade_Instance(letter_grade, num_grade_A, num_grade_B, 
											num_grade_C, num_grade_D, num_grade_F);
		}
	}
	// print the tally of letter grades to output
	Print_Letter_Grades_Tally(num_grade_A, num_grade_B, num_grade_C, 
										num_grade_D, num_grade_F);

	// process Part 2 summary stats to second output file
	Process_Summary_Stats(input_file_name);
	
	// close the input file
	Print_End_Message(output_file_name);
	inputFile.close();

	return 0;
}



char Get_Letter_Grade(int grade_percentage) {
	char letter_grade = 32;

	switch (grade_percentage) {
		case 60 :
		case 61 :
		case 62 :
		case 63 :
		case 64 :
		case 65 :
		case 66 :
		case 67 :
		case 68 :
		case 69 : 
			letter_grade = 'D';
			break;
		case 70 :
		case 71 :
		case 72 :
		case 73 :
		case 74 :
		case 75 :
		case 76 :
		case 77 :
		case 78 :
		case 79 :
			letter_grade = 'C';
			break;
		case 80 :
		case 81 :
		case 82 :
		case 83 :
		case 84 :
		case 85 :
		case 86 :
		case 87 :
		case 88 :
		case 89 :
			letter_grade = 'B';
			break;
		case 90 :
		case 91 :
		case 92 :
		case 93 :
		case 94 :
		case 95 :
		case 96 :
		case 97 :
		case 98 :
		case 99 :
			letter_grade = 'A';
			break;
		default :
			letter_grade = 'F';
	}
	return letter_grade;
}

char Get_Letter_Grade_Mod(int grade_percentage) {
	char letter_grade_mod = 32;

	if ((grade_percentage == 100) || (grade_percentage == 99) ||
		(grade_percentage == 98) || (grade_percentage == 89) ||
		(grade_percentage == 88) || (grade_percentage == 79) || 
		(grade_percentage == 78) || (grade_percentage == 69) || 
			(grade_percentage == 68)) 
	{
		letter_grade_mod = '+';
	}
	else if ((grade_percentage == 91) || (grade_percentage == 90) ||
		(grade_percentage == 81) || (grade_percentage == 80) ||
		(grade_percentage == 71) || (grade_percentage == 70) || 
		(grade_percentage == 61) || (grade_percentage == 60)) 
	{
		letter_grade_mod = '-';
	}
	else {
		letter_grade_mod = 32;
	}

	return letter_grade_mod;
}

void Print_Letter_Grades_Tally(int num_grade_A, int num_grade_B, 
										int num_grade_C, int num_grade_D, 
										int num_grade_F){
	cout << "The number of A's = " << num_grade_A << endl;
	cout << "The number of B's = " << num_grade_B << endl;
	cout << "The number of C's = " << num_grade_C << endl;
	cout << "The number of D's = " << num_grade_D << endl;
	cout << "The number of F's = " << num_grade_F << endl;
	return;
}

void Print_End_Message(string file_name) {
	cout << "Data and Results compiled into output file: " << file_name
		  << endl;
	return;
}

void Record_Letter_Grade_Instance(char letter_grade, int& num_grade_A, 
											int& num_grade_B, int& num_grade_C,
											int& num_grade_D, int& num_grade_F) {
	switch (letter_grade) {
			case 'A' :
				++num_grade_A;
				break;
			case 'B' : 
				++num_grade_B;
				break;
			case 'C' :
				++num_grade_C;
				break;
			case 'D' :
				++num_grade_D;
				break;
			default :
				++num_grade_F;
				break;
		}
		return;
}

void Process_Summary_Stats(string input_file_name) {
	string file_string = "";
	const int NUM_ADDNL_SCORES = 3;
	int num_students = 0;
	int total_points = 0;
	int lowest_assign_score = 0;
	int file_val = 0;
	int pre_assign_sum = 0;
	int grand_total = 0;
	double grand_percent = 0.0;
	double average_percent_total = 0.0;
	string highest_grade_student = "", lowest_grade_student = "";
	int highest_grade_points = 0, lowest_grade_points = 0;
	double highest_grade_percent = 0.0, lowest_grade_percent = 0.0;

	ifstream inputFile(input_file_name);
	ofstream outputFile("summary_stats.txt");

	if (inputFile.fail()) {
		cout << "Failure in opening input file.\n";
		return;
	}
	if (outputFile.fail()) {
		cout << "Failure in creating summary stat file.\n";
		return;
	}
	// determine the number of students 
	while (inputFile >> file_string) {
		if (file_string.length() == STUDENT_ID_LENGTH) {
			++num_students;
			pre_assign_sum = 0;
			for (int counter = 0; counter < NUM_ASSIGNMENTS; ++counter) {
				inputFile >> file_val;
				if (counter == 0) {
					lowest_assign_score = file_val;
				}
				else {
					if (file_val < lowest_assign_score) {
						lowest_assign_score = file_val;
					}
				}
				pre_assign_sum += file_val;
			}
			//cout << "Pre-assign sum is: " << pre_assign_sum << endl;
			total_points = pre_assign_sum - lowest_assign_score;
			//cout << "Adjusted assign sum is: " << total_points << endl;
			for (int counter = 0; counter < NUM_ADDNL_SCORES; ++counter) {
				inputFile >> file_val;
				total_points += file_val;
				//cout << "Total points so far is: " << total_points << endl;
			}
			cout << "Total points is: " << total_points << endl;
			grand_percent += round((static_cast<double>(total_points) / 
														MAX_POINTS_TOTAL) * 100);
			grand_total += total_points;

		}
	}

	outputFile << "Number of students = " << num_students << endl;
	outputFile << "The average total points = " << fixed << setprecision(1)
				  << static_cast<double>(grand_total) / num_students << endl;
	
	average_percent_total = grand_percent / num_students; 
	outputFile << "The average percent total = " 
				  << fixed << setprecision(1) << average_percent_total 
				  << "%" << endl;

	cout << "Summary Stat was processed and transferred to output file.\n";
	inputFile.close();
}
