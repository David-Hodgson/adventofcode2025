#include <array>
#include <iostream>
#include <vector>

#include "cutil"

using namespace std;

namespace DayFour{
class PaperGrid{

	private:
		int rowCount;
		int colCount;
		vector<bool> grid;

		int getIndex(int row, int col){

			int ind = (row * colCount) + col;
			return ind;
		}
	public:
	PaperGrid(vector<string> input)
	{
		rowCount = input.size();
		colCount = input[0].length();
		for(int i=0;i<input.size();i++){
			for(int j=0;j<input[i].length();j++){
				grid.push_back(input[i][j] == '@');
			}
		}
	}

	int GetAccessibleRolls(){

		int total = 0;
		for(int r=0;r<rowCount;r++){
			for(int c=0;c<colCount;c++){

				if (hasRoll(r,c) && isAccessible(r,c)){
					total++;
				}

			}
		}
		return total;


	}

	bool hasRoll(int row, int column)
	{
		if (row < 0 || column <0 || row>=rowCount || column>=colCount)
			return false;

		int index = getIndex(row, column);
		return grid[index];
	}	

	bool isAccessible(int row, int col)
	{
		int rollCount = 0;
	
		if (hasRoll(row-1,col-1)) rollCount++;
		if (hasRoll(row-1,col)) rollCount++;
		if (hasRoll(row-1,col+1)) rollCount++;

		if (hasRoll(row,col-1)) rollCount++;
		if (hasRoll(row,col+1)) rollCount++;

		if (hasRoll(row+1,col-1)) rollCount++;
		if (hasRoll(row+1,col)) rollCount++;
		if (hasRoll(row+1,col+1)) rollCount++;

		return rollCount <4;
	}


	int RemoveAccessibleRolls(){

		int total = 0;
		for(int r=0;r<rowCount;r++){
			for(int c=0;c<colCount;c++){

				if (hasRoll(r,c) && isAccessible(r,c)){
					total++;
					int index = getIndex(r,c);
					grid[index] = false;
				}

			}
		}
		return total;


	}

};

void partOne(vector<string> input){

	cout << "\t\tPart One\n";

	PaperGrid grid = PaperGrid(input);

	int count = grid.GetAccessibleRolls();

	cout << "\t\t\tCount: " << count << endl;
}

void partTwo(vector<string> input){

	cout << "\t\tPart Two" << endl;

	PaperGrid grid = PaperGrid(input);

	int removedCount = 0;
	int totalRemoved = 0;
	do {
		removedCount = grid.RemoveAccessibleRolls();
		totalRemoved += removedCount;
	} while (removedCount != 0);

	cout << "\t\t\tTotal Removed: " << totalRemoved << endl;
}

void go(){

	cout << "\tDay Four\n";

	vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayfour.txt");

	partOne(input);
	partTwo(input);
}
}
