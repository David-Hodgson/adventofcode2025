#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#include "cutil"

using namespace std;

int getNumber(char c){
	switch (c){
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return 0;
	}
}

void partOne(vector<string> input){

	cout << "Part One\n";

	int total = 0;

	for(int i=0;i<input.size();i++){
		int tens =0;
		int units = 0;

		int tensPos = 0;
		for(int j=0; j<input[i].length()-1;j++)
		{
			int value = getNumber(input[i][j]);
			if (value>tens){
				tens = value;
				tensPos = j;
			}
		}

		tensPos++;

		for(int k=tensPos; k<input[i].length(); k++)
		{
			int value = getNumber(input[i][k]);
			if (value>units){
				units = value;
			}
		}

		total = total + (tens * 10) + units;
	}

	cout << "Total: " << total << "\n";
}

void partTwo(){

	cout << "Part Two\n";
}

int main(){

	cout << "Day Three\n";

	vector<string> input = Util::File::readFile("input_daythree.txt");

	partOne(input);
	partTwo();
}
