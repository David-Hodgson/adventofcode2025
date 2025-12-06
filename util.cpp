#include <iostream>
#include <fstream>
#include "cutil"

namespace Util{
	namespace File{
		std::vector<std::string> readFileAsListOfStrings(std::string filename) {
			std::ifstream inputfile(filename);
			std::string readLine;
			std::vector<std::string> lines;
    		while (getline(inputfile, readLine)) {
				lines.push_back(readLine);
    		}

			return lines;
		}


		std::string readFileAsString(std::string filename){
			std::ifstream inputfile(filename);
			std::string readLine;
			getline(inputfile,readLine);
			return readLine;
		}

	}
}
