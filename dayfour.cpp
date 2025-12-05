#include <array>
#include <iostream>
#include <vector>

#include "cutil"

using namespace std;

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

};

void partOne(vector<string> input){

	cout << "Part One\n";

	PaperGrid grid = PaperGrid(input);

	int count = grid.GetAccessibleRolls();

	cout << "Count: " << count << endl;
}

void partTwo(){

	cout << "Part Two\n";
}

void dayfour(){

	cout << "Day Four\n";

	vector<string> input = Util::File::readFile("input_dayfour.txt");

	partOne(input);
	partTwo();
}
