#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	cout << "Day One\n";

	string readLine;
	int readCount = 0;
	vector<string> commands;

	ifstream inputFile("input_dayone.txt");

	while (getline(inputFile, readLine)) {
		commands.push_back(readLine);
		readCount++;
	}

	cout << "Read: " << readCount << " commands\n\n";

	int currentPos = 50;
	int zeroCount = 0;

	for(int i=0;i<commands.size();i++){
					cout << "Current Pos: " << currentPos << "\n";
					cout << "Processing " << commands[i] << "\n";
				 
					char dir = commands[i][0];
				 	int steps = std::stoi(commands[i].substr(1));

					cout << "Dir: " << dir << ", Steps: " << steps << "\n";

					if (dir == 'R') {
									currentPos = currentPos + steps;
					}
					else
					{
									currentPos = currentPos - steps;
					}

					cout << "New Pos (before adjustment): " << currentPos << "\n";
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
