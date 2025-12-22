#include <iostream>
#include <vector>

#include "cutil"

#include "daytwelve.hpp"

using namespace std;

namespace DayTwelve {

	class PresentShape{
		string id;
		vector<string> visuals;
		public:

		PresentShape(string id, vector<string> visuals):
			id(id), visuals(visuals)
		{}
	};

	class Region{
		int shape1Count;
		int shape2Count;
		int shape3Count;
		int shape4Count;
		int shape5Count;

		public:

		Region(int oneCount, int twoCount, int threeCount, int fourCount, int fiveCount):
			shape1Count(oneCount), shape2Count(twoCount), shape3Count(threeCount), shape4Count(fourCount), shape5Count(fiveCount)
		{}

	};

	vector<PresentShape*> parseShapesFromInput(vector<string> input) {
		vector<PresentShape*> shapes;

		for(int i=0; i<input.size();i++) {
			if (input[i][1] == ':') {
				string id = "" + input[i][0];

				vector<string> shapelines;
				shapelines.push_back(input[i+1]);
				shapelines.push_back(input[i+2]);
				shapelines.push_back(input[i+3]);

				PresentShape* shape = new PresentShape(id, shapelines);

				shapes.push_back(shape);
			}
		}
		return shapes;
	}


	vector<Region*> parseRegionsFromInput(vector<string> input) {
		vector<Region*> regions;

		for(int i=0; i<input.size(); i++) {

			if (input[i].find('x') != -1) {
				int splitPos = input[i].find(':');
				vector<string> shapeCount = Util::String::split(input[i].substr(splitPos + 2), ' ');

				int s1 = stoi(shapeCount[0]);
				int s2 = stoi(shapeCount[1]);
				int s3 = stoi(shapeCount[2]);
				int s4 = stoi(shapeCount[3]);
				int s5 = stoi(shapeCount[4]);

				Region* r = new Region(s1,s2,s3,s4,s5);
				regions.push_back(r);
			}
		}
		return regions;

	}

	void partOne(vector<PresentShape*> shapes, vector<Region*> regions) {
		cout << "\t\tPart One" << endl;

		for(int i=0; i< regions.size(); i++) {
			cout << "Processing region " << i << endl;

			//create empty arrangement
			
			//for each arrangement
			//	get remaining presents
			//	for each present add to arrangement
			//	creating a new arrangement
			//
			//	and loop until all presents add
			//	or no space left
		}
	}

	void partTwo() {
		cout << "\t\tPart Two" << endl;
	}

	void go() {
		cout << "\tDay Twelve" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_daytwelve.txt");

		vector<PresentShape*> shapes = parseShapesFromInput(input);
		vector<Region*> regions = parseRegionsFromInput(input);

		partOne(shapes, regions);
		partTwo();
	}
}
