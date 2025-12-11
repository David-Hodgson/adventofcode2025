#include <iostream>
#include <vector>

#include "cutil"

#include "dayeight.hpp"

using namespace std;

namespace DayEight{

	class JunctionBox{
		uint x;
		uint y;
		uint z;

		public:

			JunctionBox(uint x, uint y, uint z):
				x(x),y(y),z(z)
			{}
	};

	vector<JunctionBox> parseInput(vector<string> input){
		vector<JunctionBox> boxes;

		for(int i=0; i<input.size();i++){
			string coords = input[i];
			int split = coords.find(',');
			int x = stoi(coords.substr(0,split));
			coords = coords.substr(split+1);
			split = coords.find(',');
			int y = stoi(coords.substr(0,split));
			int z = stoi(coords.substr(split+1));

			JunctionBox jb = JunctionBox(x,y,z);
			boxes.push_back(jb);
		}
		return boxes;
	}

	void partOne(vector<string> input){
		cout << "\t\tPart One" << endl;

		cout<< "Got: " << input.size() << " input" << endl;
		vector<JunctionBox> boxes = parseInput(input);

		cout << "Parsed into " << boxes.size() << " junction boxes" << endl;

	}

	void partTwo(){
		cout << "\t\tPart Two" << endl;
	}

	void go(){
		cout << "\tDay Eight" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayeight.txt");
		partOne(input);
		partTwo();
	}
}
