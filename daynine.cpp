#include <iostream>
#include <vector>

#include "cutil"

#include "daynine.hpp"

using namespace std;

namespace DayNine{

	class Corner{
		int row;
		int col;

		public:
	       
			Corner(int rowNo, int colNo):
				row(rowNo), col(colNo)
			{}

			int Row(){
				return row;
			}

			int Col(){
				return col;
			}
	};

	class Rectangle{
		Corner* c1;
		Corner* c2;

		public:
			Rectangle(Corner* corner1, Corner* corner2):
				c1(corner1),
				c2(corner2)
			{}

			ulong Size() {
				ulong width = 0;
				ulong height = 0;

				if (c1->Row() > c2->Row()){
					height = c1->Row() - c2->Row();
				} else{
					height = c2->Row() - c1->Row();
				}

				height++;

				if (c1->Col() > c2->Col()){
					width = c1->Col() - c2->Col();
				} else {
					width = c2->Col() - c1->Col();
				}

				width++;

				ulong area = height * width;

				return area;
			}
	};

	vector<Corner*> parseInput(vector<string> input){
		vector<Corner*> corners;

		for(int i=0; i<input.size();i++){
			int split = input[i].find(',');
			int col = stoi(input[i].substr(0,split));
			int row = stoi(input[i].substr(split+1));

			Corner* c = new Corner(row,col);
			corners.push_back(c);
		}
		return corners;
	}

	void partOne(vector<Corner*> corners) {
		cout << "\t\tPart One" << endl;

		ulong  maxSize = 0;
		for(int i=0;i<corners.size()-1;i++) {
			for(int j=i+1;j<corners.size();j++){

				Rectangle r = Rectangle(corners[i], corners[j]);

				if (r.Size() > maxSize)
					maxSize = r.Size();
			}
			

		}

		cout << "\t\t\tMax Size Rectangle: " << maxSize << endl;

	}

	void partTwo() {
		cout << "\t\tPart Two" << endl;
	}

	void go() {
		cout << "\tDay Nine" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_daynine.txt");

		vector<Corner*> corners = parseInput(input);

		partOne(corners);
		partTwo();
	}
}
