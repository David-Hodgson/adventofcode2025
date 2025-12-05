#include <iostream>
#include <fstream>
#include <vector>

#include "cutil"

#include "dayone.hpp"

using namespace std;

namespace DayOne {

	void partOne(vector<string> commands){

		cout << "Part One\n";

		int currentPos = 50;
		int zeroCount = 0;


		for(int i=0;i<commands.size();i++){
				 
			char dir = commands[i][0];
			int steps = std::stoi(commands[i].substr(1));


			if (dir == 'R') {
				currentPos = currentPos + steps;
			}
			else
			{
				currentPos = currentPos - steps;
			}

			if (currentPos < 0){
				while(currentPos<0){
					currentPos = currentPos + 100;
				}
			}

			if (currentPos > 99){
				currentPos = currentPos % 100;
			}

			if (currentPos == 0)
				zeroCount++;
		}

		cout << "Number of zero's: " << zeroCount << "\n";
	}


	void partTwo(vector<string> commands){

		cout << "Part Two\n";

		int currentPos = 50;
		int zeroCount = 0;

		for(int i=0;i<commands.size();i++){
				 
			char dir = commands[i][0];
			int steps = std::stoi(commands[i].substr(1));

			int stepDir = dir == 'R' ? 1 : -1;
			for (int j=0;j<steps;j++)
			{
				currentPos = currentPos + stepDir;

				if (currentPos > 99)
					currentPos = 0;

				if (currentPos < 0)
					currentPos = 99;

				if (currentPos ==0)
					zeroCount++;
								
			}
		}

		cout << "Number of zero's: " << zeroCount << "\n";
	}

	void dayone(){

		cout << "Day One\n";
		vector<string> commands = Util::File::readFile("data/input_dayone.txt");

		partOne(commands);
		partTwo(commands);
	}
}
