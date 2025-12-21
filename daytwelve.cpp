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

	vector<PresentShape*> parseShapesFromInput(vector<string> input) {
		cout << "Parsing Shapes" << endl;

		vector<PresentShape*> shapes;

		for(int i=0; i<input.size();i++) {
			cout << "\t" << input[i] << endl;

			if (input[i][1] == ':') {
				cout << "\t\tFound ID line" << endl;

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

	void partOne() {
		cout << "\t\tPart One" << endl;
	}

	void partTwo() {
		cout << "\t\tPart Two" << endl;
	}

	void go() {
		cout << "\tDay Twelve" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_daytwelve.txt");

		cout << "Read " << input.size() << " lines" << endl;

		vector<PresentShape*> shapes = parseShapesFromInput(input);

		cout << "Parse " << shapes.size() << " shapes" << endl;

		partOne();
		partTwo();
	}
}
