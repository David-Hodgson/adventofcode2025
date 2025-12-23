#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#include "cutil"
#include "daytwo.hpp"

using namespace std;

namespace DayTwo{

	class Range{
		public:
			ulong min = 0;
			ulong max = 0;

			Range(ulong min,ulong max):
				min(min),
				max(max)
			{}

	};

	std::ostream& operator<<(std::ostream& os, const Range& obj) {
		os << "Min: " << obj.min << ", ";
		os << "Max: " << obj.max;
		return os;
	}

	Range parseRange(string);

	vector<Range> processInput(string input){
		vector<Range> ranges;
		const char* str = input.c_str();
		char *token = strtok(strdup(str), ",");
		while(token != nullptr){
			ranges.push_back(parseRange(token));
			token = strtok(nullptr,",");
		}
		return ranges;
	}

	Range parseRange(string input){

		ulong min = 0;
		ulong max = 0;

		int splitPoint = input.find('-');
		min = std::stoul(input.substr(0,splitPoint));
		max = std::stoul(input.substr(splitPoint+1));

		return Range(min,max);
	}

	void partOne(vector<Range> ranges){

		cout << "\t\tPart One\n";

		ulong total = 0;
		for(int i=0;i<ranges.size(); i++){

			Range r = ranges[i];

			for(ulong j=r.min; j<=r.max;j++)
			{
				string svalue = "" + std::to_string(j);

				if (svalue.length() % 2 == 0)
				{
					int sublength = svalue.length() /2;
					string s1 = svalue.substr(0,sublength);
					string s2 = svalue.substr(sublength);

					if (s1==s2){
						total = total + j;
					}
				}
			}
		}

		cout << "\t\t\tTotal: " << total << "\n";
	}


	void partTwo(){

		cout << "\t\tPart Two\n";

		//TODO much like part one, but instead of just dividing 
		//string by two, we need to find all the whole factors
		// factors will be limited from 1->(string length/2)
	}

	void go(){

		cout << "\tDay Two\n";
		string input = Util::File::readFileAsString("data/input_daytwo.txt"); 
		vector<Range> ranges = processInput(input);

		partOne(ranges);
		partTwo();
	}
}
