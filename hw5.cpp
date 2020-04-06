// This program simulates an easy dice game following the spec. 

#include <iostream>
#include <cstdlib> 			// for rand() function.
using namespace std;

int main() {
	const short MAX_NUM_ROLLS_PER_TURN = 3;	// maximum num rolls per turn
	const short DUD_ROLL_SUM = 7;					// if get this sum, then this
															// roll's sum does not count and 
															// turn ends.

	unsigned short cumulative_sum = 0,
						this_turn_sum = 0,
						first_roll_val = 0,
						second_roll_val = 0,
						roll_sum = 0,
						turn_number = 1;

	while (cumulative_sum < 100) {
		cout << "This is your turn #" << turn_number << endl;
		// roll up to 3 times for this turn
		this_turn_sum = 0;

		for (int i = 0; i < MAX_NUM_ROLLS_PER_TURN; ++i) {
			// a six-sided dice has values from 1 to 6 inclusive. 
			first_roll_val = (rand() % 6) + 1; 
			second_roll_val = (rand() % 6) + 1;
			roll_sum = (first_roll_val + second_roll_val);

			cout << "* You rolled " << first_roll_val << " and " << second_roll_val
				  << ".   " << "That's ";

			if (roll_sum == DUD_ROLL_SUM) {
				roll_sum = 0;
				cout << roll_sum << endl;
				break;
			}
			else {
				cout << roll_sum << endl;
				this_turn_sum += (first_roll_val + second_roll_val);
			}
		}

		cout << "** You scored " << this_turn_sum << " points for this turn\n";

		cumulative_sum += this_turn_sum;
		cout << "*** Your total is now " << cumulative_sum << endl;
		++turn_number;
	}

	return 0;
}