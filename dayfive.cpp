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

		vector<pair<ulong,ulong>>* mergeRanges(vector<pair<ulong,ulong>> input){

			vector<pair<ulong,ulong>>* output = new vector<pair<ulong,ulong>>;

			for (int i=0; i<input.size(); i++) {

				pair<ulong,ulong> ir = input[i];

				bool overlaps = false;
				pair<ulong,ulong> olrange;
				int pos = -1;
				for (int j=0;j<output->size();j++){
					pair<ulong,ulong> orange = output->at(j);

					if ( (ir.first >= orange.first && ir.first <= orange.second) ||
					 (ir.second >= orange.first && ir.second <= orange.second) ||
					 (orange.first >= ir.first && orange.first <= ir.second) ||

					 (orange.second >= ir.first && orange.second <= ir.second)) {
					       overlaps = true;
						olrange = orange;
				 		pos = j;
						break;
					}		
				}

				if (!overlaps) {
					pair<ulong,ulong> range = pair(ir.first,ir.second);
					output->push_back(range);
				} else{
					ulong min = olrange.first;
					ulong max = olrange.second;
					if (ir.first < olrange.first) {
						min = ir.first;	
					}

					if (ir.second > olrange.second) {
						max = ir.second;
					}

					output->at(pos) = pair(min,max);
				}
			}

			return output;
		}

		ulong generateFreshIDCount(){
			ulong total = 0;
			int rangesRemoved = 0;
		
			vector<pair<ulong,ulong>>* merged = &ranges;

			do{
				int beforeCount = merged->size();
				merged = mergeRanges(*merged);
				int afterCount = merged->size();

				rangesRemoved = beforeCount -afterCount;
				
			} while (rangesRemoved != 0);

			for(int i=0;i<merged->size();i++) {

				pair<ulong,ulong> r = merged->at(i);
				ulong diff = (r.second - r.first);

				diff++;

				total += diff;

			}

			return total;
		}
	};

	void partOne(vector<string> input){

		cout << "\t\tPart One" << endl;

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

		cout << "\t\t\tTotal Fresh Foods: " << totalFreshFoods << endl;
		
	}

	void partTwo(vector<string> input){
		cout << "\t\tPart Two" << endl;

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
		}

		ulong total = db.generateFreshIDCount();

		cout << "\t\t\tNumber of fresh Id's: " << total << endl;
	}
	
	void go(){
		cout << "\tDay Five" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayfive.txt");

		partOne(input);
		partTwo(input);
	}
}
