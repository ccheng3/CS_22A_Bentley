// testing EOF concept

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	string filename = "testfile.txt";
	ifstream inputFile(filename.c_str());
	int x;

	if (inputFile.fail()) {
		cerr << "Unable to open file " << filename << endl;
		exit(1);
	}

	cout << boolalpha;
	// you've just opened the file, and not at end of file
	cout << "inputFile.eof()=" << inputFile.eof() << endl;

	while (inputFile >> x) {
		cout << x << endl;
	}
	// after while loop finishes, then you're at the end of file
	cout << "fin.eof()=" << inputFile.eof() << endl << endl << endl;
	inputFile.close();
	inputFile.open(filename);
	// if you close and re-open the file, you start back at beginning of 
	// file buffer so not at end of file. 
	cout << "fin.eof()=" << inputFile.eof() << endl;

	return 0;
}