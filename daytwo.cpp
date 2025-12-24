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


	void partTwo(vector<Range> ranges){
		cout << "\t\tPart Two\n";
		ulong total = 0;

		for (int i=0;i<ranges.size();i++) {
			Range r = ranges[i];

			for(ulong j=r.min; j<=r.max;j++)
			{
				string svalue = "" + std::to_string(j);
				int length = svalue.length();

				bool inValid = false;

				for (int k=1;k<length;k++) {

					if (length%k == 0 && length!=k) {
						int start = 0;
						int numberOfChunks = length/k;
						bool allEqual = true;
						string checkValue = svalue.substr(0,k);

						for (int x=1; x<numberOfChunks;x++){
							string sample = svalue.substr(k*x,k);	
							if (sample !=checkValue) {
								allEqual = false;
							}
						}


						if (allEqual && !inValid) {
							inValid = true;
							total = total + j;
						}	

					}
				}
			}

		}

		cout << "\t\t\tTotal: " << total << "\n";
	}

	void go(){

		cout << "\tDay Two\n";
		string input = Util::File::readFileAsString("data/input_daytwo.txt"); 
		vector<Range> ranges = processInput(input);

		partOne(ranges);
		partTwo(ranges);
	}
}
