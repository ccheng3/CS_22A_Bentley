// This program computes data from buying and selling stock

#include <iostream>
#include <iomanip> 				// to format output nicely
#include <fstream>
using namespace std;

int main() {
	const string STOCK_TICKER = "WMT";
	const string PURCHASE_DATE = "01/02/19";		
	const double INITIAL_INVESTMENT = 10000;	
	const int 	 NUM_SHARES_PUR = 143;				// number of shares bought	
	double purchase_price, 								// stock purchase price
			 sell_price, 									// stock sell price
			 share_sold_value,							// value of stock shares sold
			 gain,											// how much made after sell  
			 remain_cash;								// remaining investment
	string sell_date;										// stock sell date

	// open input file stream object to example data
	ifstream inputFile("hw3_data.txt");

	// if file successfully opened, 
	// read example parameters into program 
if (inputFile) {
	cout << "Enter the purchase price => ";
	inputFile >> purchase_price;
	cout << purchase_price << endl;

	cout << "Enter the sell date (mm/dd/yy) => ";
	inputFile >> sell_date;
	cout << sell_date << endl;

	cout << "Enter the sell price => ";
	inputFile >> sell_price;
	cout << sell_price << endl << endl;
}
else {
	cout << "Error with opening the input file.\n";
	return 1;
}
	
	cout << "Stock Ticker: " << STOCK_TICKER << endl << endl;

	cout << "Purchase Date: " << PURCHASE_DATE << endl;
	cout << "Purchase Price: $" << showpoint << setprecision(4)
		  << purchase_price << endl;
	cout << "Number of Shares Purchased: " << NUM_SHARES_PUR << endl << endl;

	// calculate share_sold_value and other vals
	remain_cash = INITIAL_INVESTMENT - (purchase_price * NUM_SHARES_PUR);
	share_sold_value = NUM_SHARES_PUR * sell_price;
	gain = share_sold_value - INITIAL_INVESTMENT + remain_cash;

	cout << "Sell Date: " << sell_date << endl;
	cout << "Sell Price: $" << showpoint << setprecision(4) 
		  <<  sell_price << endl;
	cout << "Value of Shares Sold: $" << fixed << showpoint << setprecision(2)
		  << share_sold_value << endl << endl;

	cout << "Gain: $" << gain << endl;
	cout << "Percent Gain: " << fixed << setprecision(1) 
		  << (gain / INITIAL_INVESTMENT * 100) << "%\n\n";

	return 0;
}