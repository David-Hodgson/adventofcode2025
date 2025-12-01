#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> readFile(string filename){
	ifstream inputfile(filename);
	string readLine;
	vector<string> lines;
	while(getline(inputfile,readLine)){
					lines.push_back(readLine);
	}

	return lines;
}

void partOne(vector<string> commands){

	cout << "Part One\n";

	int currentPos = 50;
	int zeroCount = 0;


	for(int i=0;i<commands.size();i++){
//					cout << "Current Pos: " << currentPos << "\n";
//					cout << "Processing " << commands[i] << "\n";
				 
					char dir = commands[i][0];
				 	int steps = std::stoi(commands[i].substr(1));

//					cout << "Dir: " << dir << ", Steps: " << steps << "\n";

					if (dir == 'R') {
									currentPos = currentPos + steps;
					}
					else
					{
									currentPos = currentPos - steps;
					}

//					cout << "New Pos (before adjustment): " << currentPos << "\n";
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

					cout << "Moving " << steps << " " << dir << "\n";

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

int main(){

	cout << "Day One\n";
	vector<string> commands = readFile("input_dayone.txt");

	partOne(commands);
	partTwo(commands);
}
