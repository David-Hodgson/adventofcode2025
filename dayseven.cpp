#include <iostream>
#include <vector>

#include "cutil"

#include "dayseven.hpp"

using namespace std;

namespace DaySeven{

	class Manifold{
		uint width;
		uint height;

		uint startingX;

		vector<string> layout;

		public:

		Manifold(vector<string> input):
			layout(input)
		{}		

		void extendBeam(int row, int col){
			if (row < layout.size()-1){
				//Not at bottom yet
				if (layout[row+1][col] == '.'){
					layout[row+1][col] = '|';
				}

				if (layout[row+1][col] == '^'){
					if (layout[row+1][col-1] == '.'){
						layout[row+1][col-1] = '|';
					}

					if (layout[row+1][col+1] == '.'){
						layout[row+1][col+1] = '|';
					}
				}
			}

			return;
		}

		void printManifold(){
			cout << endl;
			for (int i=0;i<layout.size();i++){
				cout << layout[i] << endl;
			}

			cout << endl;
		}

		void fireBeam()
		{

			int currentRow = 0;

			for(int row=0; row<layout.size(); row++){
				for (int col=0;col<layout[row].length();col++){
					if (layout[row][col] == 'S'){
						//start Pos
						extendBeam(row,col);
					}

					if (layout[row][col] == '|'){
						//beam
						extendBeam(row,col);
					}
				}
			}
		}

		int getSplitCount(){
			//Need to count all the spliter that got hit
			int splits = 0;
			for (int i=1;i<layout.size();i++){
				for (int j=0;j<layout.size();j++){

					if (layout[i][j] == '^' && layout[i-1][j] == '|')
						splits++;
				}
			}

			
			return splits;
		}

		int getTimeLines(){

			cout << "in Get time lines" << endl;
			int timeLineCount = 0;

			vector<vector<uint>> timelineMap;

			for(int row=0;row<layout.size();row++){
				vector<uint> numberRow;
				timelineMap.push_back(numberRow);
				for(int col=0;col<layout[row].length();col++){

					timelineMap[row].push_back(0);
					if (layout[row][col] == 'S'){
						timelineMap[row][col] = 1;
					}

					if (layout[row][col] == '|'){

						uint cellValue = 0;

					
					}
				}
			}

			return timeLineCount;
		}
	};

	void partOne(vector<string> input){
		cout << "\t\tPart One" << endl;

		Manifold m = Manifold(input);
		m.fireBeam();
		int splits = m.getSplitCount();

		cout << "\t\t\tSplits: " << splits << endl;
	}

	void partTwo(vector<string> input){
		cout << "\t\tPart Two" << endl;

		Manifold m = Manifold(input);
		m.fireBeam();
		cout << "Part two splits: " << m.getSplitCount() << endl;
		int timeLineCount = m.getTimeLines();

		cout << "\t\t\tTime Lines: " << timeLineCount << endl;
	}

	void go(){
		cout << "\tDay Seven" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayseven.txt");

		partOne(input);
		partTwo(input);
	}
}
