#include <iostream>
#include <fstream>
#include "cutil"

namespace Util{
	namespace File{
		std::vector<std::string> readFileAsListOfStrings(std::string filename) {
			std::ifstream inputfile(filename);

			if (!inputfile){
				std::cerr << "Error reading input file" << std::endl;
			}
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

	namespace String{
		std::vector<std::string> split(std::string inputString, char splitChar){
			//std::cout << "spliting string " << inputString << std::endl;
			std::vector<std::string> parts;
			
			std::string localString = inputString;
			int splitPoint = -1;

			do{
				splitPoint = localString.find(splitChar);

				//std::cout << "split point: " << splitPoint << std::endl;
				std::string part = localString.substr(0,splitPoint);
				//std::cout << "Part: " << part << std::endl;

				localString = localString.substr(splitPoint+1);
				//break;
				//
				parts.push_back(part);
			} while (splitPoint != -1);

			return parts;
	    }
	}
}
