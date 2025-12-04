#include <iostream>
#include <vector>

#include "cutil"

using namespace std;

void partOne(vector<string> input){

	cout << "Part One\n";
}

void partTwo(){

	cout << "Part Two\n";
}

int main(){

	cout << "Day Three\n";

	vector<string> input = Util::File::readFile("input_dayfour.txt");

	partOne(input);
	partTwo();
}
