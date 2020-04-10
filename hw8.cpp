// This program creates a more detailed dice game simulation between 
// three different gambling personalities (Larry, Curly, and Moe)

// Larry rolls only once during his turn, Curly rolls at most three times 
// during his turn, and Moe continues to roll during his turn until he rolls
// a 1 or wins the game. 

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

const int WINNING_SUM = 100;
const int LARRY_MAX_NUM_ROLLS = 1;
const int CURLY_MAX_NUM_ROLLS = 3;
const int MOE_MAX_NUM_ROLLS = 1000;

// function prototypes
void Roll_Dice(int& total_sum, int num_rolls);


// main function
int main() {
	//int total_sum = 0;
	int larry_sum = 0, curly_sum = 0, moe_sum = 0;
	
	int player_num = 1;


	// replicate dice rolling base behavior
while ((larry_sum < 100) && (curly_sum < 100) && (moe_sum < 100)) {
	switch(player_num) {
		case 1 :
			cout << "Larry, its your turn\n";
			Roll_Dice(larry_sum, LARRY_MAX_NUM_ROLLS);
			++player_num;
			break;
		case 2 :
			cout << "Curly, its your turn\n";
			Roll_Dice(curly_sum, CURLY_MAX_NUM_ROLLS);
			++player_num;
			break;
		case 3 :
			cout << "Moe, its your turn\n";
			Roll_Dice(moe_sum, MOE_MAX_NUM_ROLLS);
			player_num = 1;
			break; 
	}
}

	return 0;
}

// function definitions
void Roll_Dice(int& total_sum, int num_rolls) {
	int dice_roll_one, dice_roll_two, current_roll_sum;
	int total_dice_roll = 0;

	//while (total_sum < 100) {
		for (int roll_number = 1; roll_number <= num_rolls; ++roll_number) {
			dice_roll_one = (rand() % 6) + 1;
			dice_roll_two = (rand() % 6) + 1;
			current_roll_sum = dice_roll_one + dice_roll_two;

			cout << "    You rolled " << dice_roll_one << " and " 
				  << dice_roll_two << ".";

			if ((dice_roll_one == 1) && (dice_roll_two == 1)) {
				cout << "  That's SKUNK\n";
				current_roll_sum = 0;
				total_dice_roll = 0;
				total_sum = 0;
			}
			else if ((dice_roll_one == 1) || (dice_roll_two == 1)) {
				current_roll_sum = 0;
				total_dice_roll = 0;
				cout << "  That's " << current_roll_sum << endl;
			}
			else {
				cout << "  That's " << current_roll_sum << endl;
			} 

			if (((dice_roll_one == 1) && (dice_roll_two == 1)) || 
				((dice_roll_one == 1) || (dice_roll_two == 1))) {
				
				cout << "  That's " << current_roll_sum 
					  << " points for your turn\n";
				break;
			}
			total_dice_roll += current_roll_sum;
		}
		total_sum += total_dice_roll;
		cout << "Total points = " << total_sum << endl;
	//}
	
	return;
}
