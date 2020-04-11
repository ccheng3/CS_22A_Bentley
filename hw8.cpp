// This program creates a more detailed dice game simulation between 
// three different gambling personalities (Larry, Curly, and Moe)

// Larry rolls only once during his turn, Curly rolls at most three times 
// during his turn, and Moe continues to roll during his turn until he rolls
// a 1 or wins the game. 

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;

const int WINNING_SUM = 100;
const int LARRY_MAX_NUM_ROLLS = 1;
const int CURLY_MAX_NUM_ROLLS = 3;
const int MOE_MAX_NUM_ROLLS = 10000;

// function prototypes
void Roll_Dice(int& total_sum, int num_rolls, string player_name);
void Play_Game_Until_Target_Score(const int max_sum = WINNING_SUM);

// main function
int main() {
	
	// replicate dice rolling base behavior
	Play_Game_Until_Target_Score();

	return 0;
}

// function definitions
void Play_Game_Until_Target_Score(const int max_sum) {
	int larry_sum = 0, 		// Larry's total sum 
		 curly_sum = 0,		// Curly's total sum
		 moe_sum = 0;			// Moe's total sum 
	int player_num = 1;		// player indicator variable 

	while ((larry_sum < max_sum) && (curly_sum < max_sum) && (moe_sum < max_sum)) {
		switch(player_num) {
			case 1 :
				cout << "Larry, its your turn\n";
				Roll_Dice(larry_sum, LARRY_MAX_NUM_ROLLS, "Larry");
				++player_num;
				break;
			case 2 :
				cout << "Curly, its your turn\n";
				Roll_Dice(curly_sum, CURLY_MAX_NUM_ROLLS, "Curly");
				++player_num;
				break;
			case 3 :
				cout << "Moe, its your turn\n";
				Roll_Dice(moe_sum, MOE_MAX_NUM_ROLLS, "Moe");
				player_num = 1;
				break; 

				return;
		}
	}
}


void Roll_Dice(int& total_sum, int num_rolls, string player_name) {
	int dice_roll_one, dice_roll_two, current_roll_sum;
	int total_dice_roll = 0;

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
		if (!(((dice_roll_one == 1) && (dice_roll_two == 1)) || 
						((dice_roll_one == 1) || (dice_roll_two == 1)))) {
				
				cout << "  That's " << total_dice_roll 
					  << " points for your turn\n";
			}
		total_sum += total_dice_roll;
		cout << "Total points = " << total_sum << endl;

		if (total_sum >= 100) {
			cout << player_name << " won the game with "
				  << total_sum << " points\n";
		}
	
	return;
}
