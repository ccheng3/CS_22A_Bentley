// This program calculates student grades using specified rules and spec

#include <iostream>
#include <cmath> 				// for round() function. 
#include <iomanip>

using namespace std;

int main() {
	const int MAX_POINTS = 400;
	unsigned short assign_one_points = 0, assign_two_points = 0,
						assign_three_points = 0, assign_four_points = 0,
						assign_five_points = 0, assign_six_points = 0,
						assign_seven_points = 0, assign_eight_points = 0,
						assign_nine_points = 0, assign_ten_points = 0,
						assign_elev_points = 0,
						lowest_assign_score = 0,
						total_assign_points = 0,
						adjusted_total_assign = 0,
						lab_points = 0,
						midterm_points = 0,
						final_points = 0,
						letter_grade_score = 0,
						total_points = 0;
	char letter_grade = 'A';
	char letter_grade_mod = 'a';
	double percent_total = 0.0;

	// read in user input
	cout << "Enter assignment 1 points ";
	cin >> assign_one_points;
	lowest_assign_score = assign_one_points;
	cout << "Enter assignment 2 points ";
	cin >> assign_two_points;
	if (assign_two_points < lowest_assign_score) {
		lowest_assign_score = assign_two_points;
	}
	cout << "Enter assignment 3 points ";
	cin >> assign_three_points;
	if (assign_three_points < lowest_assign_score) {
		lowest_assign_score = assign_three_points;
	}
	cout << "Enter assignment 4 points ";
	cin >> assign_four_points;
	if (assign_four_points < lowest_assign_score) {
		lowest_assign_score = assign_four_points;
	}
	cout << "Enter assignment 5 points ";
	cin >> assign_five_points;
	if (assign_five_points < lowest_assign_score) {
		lowest_assign_score = assign_five_points;
	}
	cout << "Enter assignment 6 points ";
	cin >> assign_six_points;
	if (assign_six_points < lowest_assign_score) {
		lowest_assign_score = assign_six_points;
	}
	cout << "Enter assignment 7 points ";
	cin >> assign_seven_points;
	if (assign_seven_points < lowest_assign_score) {
		lowest_assign_score = assign_seven_points;
	}
	cout << "Enter assignment 8 points ";
	cin >> assign_eight_points;
	if (assign_eight_points < lowest_assign_score) {
		lowest_assign_score = assign_eight_points;
	}
	cout << "Enter assignment 9 points ";
	cin >> assign_nine_points;
	if (assign_nine_points < lowest_assign_score) {
		lowest_assign_score = assign_nine_points;
	}
	cout << "Enter assignment 10 points ";
	cin >> assign_ten_points;
	if (assign_ten_points < lowest_assign_score) {
		lowest_assign_score = assign_ten_points;
	}
	cout << "Enter assignment 11 points ";
	cin >> assign_elev_points;
	if (assign_elev_points < lowest_assign_score) {
		lowest_assign_score = assign_elev_points;
	}

	cout << "Enter lab exercise points ";
	cin >> lab_points;
	cout << "Enter midterm points ";
	cin >> midterm_points;
	cout << "Enter final points ";
	cin >> final_points;

	cout << endl;

	cout << "Assignment Grades: ";
	cout << setw(4) << assign_one_points << setw(4) << assign_two_points 
		  << setw(4) << assign_three_points << setw(4) << assign_four_points 
		  << setw(4) << assign_five_points << setw(4) << assign_six_points 
		  << setw(4) << assign_seven_points << setw(4) << assign_eight_points 
		  << setw(4) << assign_nine_points << setw(4) << assign_ten_points
		  << setw(4) << assign_elev_points;

	total_assign_points = (assign_elev_points + assign_ten_points + 
									assign_nine_points + assign_eight_points + 
									assign_seven_points + assign_six_points +
		  	   					assign_five_points + assign_four_points +
		  	   					assign_three_points + assign_two_points + 
		  	   					assign_one_points);
	// remove lowest assignment grade 
	adjusted_total_assign = total_assign_points - lowest_assign_score;

	cout << endl << "Assignment Points:" << setw(4) 
		  << adjusted_total_assign << endl;
	cout << "Lab Exercise:" << setw(9) << lab_points << endl;
	cout << "Midterm:" << setw(14) << midterm_points << endl;
	cout << "Final:" << setw(16) << final_points << endl;

	total_points = (adjusted_total_assign + lab_points + midterm_points + 
						final_points);
	cout << "Total Points:" << setw(9) << total_points << endl;

	// determine letter grade score and corresponding letter grade
	letter_grade_score =  round(static_cast<double>(total_points) / 
																MAX_POINTS * 100);
	cout << "Percent of total:" << setw(5) << letter_grade_score << "%\n";

	switch (letter_grade_score) {
		case 60:
		case 61:
		case 62:
		case 63:
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 69: 
			letter_grade = 'D';
			break;
		case 70:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79: 
			letter_grade = 'C';
			break;
		case 80:
		case 81:
		case 82:
		case 83:
		case 84:
		case 85:
		case 86:
		case 87:
		case 88:
		case 89: 
			letter_grade = 'B';
			break;
		case 90:
		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
		case 97:
		case 98:
		case 99: 
			letter_grade = 'A';
			break;
		default :
			letter_grade = 'F';
	}
	
	// determine letter grade plus/minus/none status
	if ((letter_grade_score == 100) || (letter_grade_score == 99) ||
		(letter_grade_score == 98) || (letter_grade_score == 89) ||
		(letter_grade_score == 88) || (letter_grade_score == 79) || 
		(letter_grade_score == 78) || (letter_grade_score == 69) || 
			(letter_grade_score == 68)) 
	{
		letter_grade_mod = '+';
		//cout << letter_grade_mod << endl;
	}
	else if ((letter_grade_score == 91) || (letter_grade_score == 90) ||
		(letter_grade_score == 81) || (letter_grade_score == 80) ||
		(letter_grade_score == 71) || (letter_grade_score == 70) || 
		(letter_grade_score == 61) || (letter_grade_score == 60)) 
	{
		letter_grade_mod = '-';
	}
	else {
		letter_grade_mod = 32;
	}
	
	cout << "Grade: " << letter_grade << letter_grade_mod; 

	// print a message if applicable
	if (letter_grade == 'A') {
		cout << endl << "Excellent work\n";
	}
	else if ((letter_grade == 'B') || (letter_grade == 'C')) {
		cout << endl << "Not bad!\n";
	}
	else {
		cout << "You better try again\n";
	}

	return 0;
}
