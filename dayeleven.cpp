#include <iostream>
#include <vector>
#include <map>

#include "cutil"

#include "dayeleven.hpp"

using namespace std;

namespace DayEleven{

	class Device {
		string name;
		vector<string> outputs;

		public:
		Device(string name, vector<string> outputs):
			name(name), outputs(outputs)
			{}

		string Name() {
			return name;
		}

		vector<string> Outputs() {
			return outputs;
		}
	};

	map<string, Device*> parseInput(vector<string> input) {

		map<string,Device*> deviceMap;

		for (int i=0; i<input.size();i++) {
			vector<string> parts = Util::String::split(input[i], ':');
			string name = parts[0];
			vector<string> outputs = Util::String::split(parts[1].substr(1), ' ');
			Device* d = new Device(name, outputs);
			deviceMap[name] = d;
		}

		return deviceMap;
	}

	void partOne() {
		cout << "\t\tPart One" << endl;
	}

	void partTwo() {
		cout << "\t\tPart Two" << endl;
	}

	void go() {
		cout << "\tDay Eleven" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayeleven.txt");

		map<string, Device*> devices = parseInput(input);

		Device* youDevice = devices["you"];

		cout << youDevice->Name() << endl;
		for (int i=0;i<youDevice->Outputs().size();i++) {
			cout << "\t" << youDevice->Outputs()[i] << endl;
		}

		partOne();
		partTwo();
	}
}
