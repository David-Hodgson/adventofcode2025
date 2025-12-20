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

	void partOne(map<string,Device*> devices) {
		cout << "\t\tPart One" << endl;

		Device* startDevice = devices["you"];
		int pathCount = 1;
		vector<string> paths;

		paths.push_back(startDevice->Name());
		while (paths.size() > 0) {
			Device* d = devices[paths[0]];

			vector<string> outputs = d->Outputs();
			pathCount = pathCount + outputs.size() -1;

			for(int i=0;i<outputs.size();i++){
				if (outputs[i] != "out") {
					paths.push_back(outputs[i]);
				}
			}
			
			paths.erase(paths.begin());
		}

		cout << "\t\t\tPath Count: " << pathCount << endl;
	}

	void partTwo() {
		cout << "\t\tPart Two" << endl;
	}

	void go() {
		cout << "\tDay Eleven" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayeleven.txt");

		map<string, Device*> devices = parseInput(input);
		partOne(devices);

		partTwo();
	}
}
