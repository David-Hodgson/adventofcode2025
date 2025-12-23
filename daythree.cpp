#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#include "cutil"
#include "daythree.hpp"

using namespace std;

namespace DayThree{

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

		cout << "\t\tPart One\n";

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

		cout << "\t\t\tTotal: " << total << "\n";
	}

	void partTwo(vector<string> input){

		cout << "\t\tPart Two\n";
	
		ulong total = 0;
		
		for(int i=0;i<input.size();i++){

			string number = "";
			int numbersToFind = 12;

			int currentPos = 0;

			for (int j=0; j<numbersToFind; j++) {

				int currentHighest = 0;

				int endPos = input[i].length() - (numbersToFind - j -1);

				for(int k=currentPos; k < endPos ; k++) {

					int value = getNumber(input[i][k]);
					if (value>currentHighest) {
						currentHighest = value;
						currentPos = k;
					}
						
				}

				number = number + to_string(currentHighest);
				currentPos++;
			}

			total = total + stoul(number);
		}

		cout << "\t\t\tTotal: " << total << "\n";
	}

	void go(){

		cout << "\tDay Three\n";

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_daythree.txt");

		partOne(input);
		partTwo(input);
	}
}
