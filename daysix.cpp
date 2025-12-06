#include <iostream>
#include <vector>

#include "cutil"

#include "daysix.hpp"

using namespace std;

namespace DaySix{

	void processInput(vector<string> input){

		for(int i=0;i<input.size()-1;i++)
		{
			vector<uint> numberrow;
			string numberDigits = "";
			for (int k=0;k<input[i].length();k++)
			{
				if (input[i][k] != ' '){
					numberDigits = numberDigits + input[i][k];
				}
				else {
					if (numberDigits.length() > 0){
						int number = stoi(numberDigits);
						numberrow.push_back(number);
						numberDigits = "";
					}
				}
			}

			cout << numberrow.size() << endl;
		}

		//cout << input[input.size()-1] << endl;
	}

	void partOne(){
		cout << "Part One" << endl;
	}

	void partTwo(){
		cout << "Part Two" << endl;
	}

	void go(){
		cout << "Day Six" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_daysix.txt");
		processInput(input);

		partOne();
		partTwo();
	}
}
