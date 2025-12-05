#include <iostream>
#include <vector>
#include <utility>

#include "cutil"

#include "dayfive.hpp"

using namespace std;

namespace DayFive{

	class IDRangeDatabase{
		private:
			vector<pair<ulong,ulong>> ranges;
		public:
		void addRange(ulong min, ulong max){
			pair<ulong,ulong> range = pair(min,max);
			ranges.push_back(range);
		}

		bool isFresh(ulong ID){
			bool isFresh = false;
			for(int i=0;i<ranges.size();i++){
				pair<ulong,ulong> r = ranges[i];
				if (r.first <= ID && r.second >= ID)
				{
					isFresh = true;
					break;
				}
			}
			return isFresh;
		}
	};

	void partOne(vector<string> input){

		cout << "Part One" << endl;

		IDRangeDatabase db;
		bool doneRanges = false;

		int totalFreshFoods = 0;
		for(int i=0;i<input.size();i++){

			if (input[i] == ""){
				doneRanges = true;
				continue;
			}

			if (!doneRanges){
				int pos = input[i].find('-');
				ulong min = stoul(input[i].substr(0,pos));
				ulong max = stoul(input[i].substr(pos+1));

				db.addRange(min,max);
			}
			else{
				ulong id = stoul(input[i]);
				
				if (db.isFresh(id))
					totalFreshFoods++;
			}

		}

		cout << "Total Fresh Foods: " << totalFreshFoods << endl;
		
	}

	void partTwo(){
		cout << "Part Two" << endl;
	}
	
	void go(){
		cout << "Day Five" << endl;

		vector<string> input = Util::File::readFile("data/input_dayfive.txt");

		partOne(input);
		partTwo();
	}
}
