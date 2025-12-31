#include <iostream>
#include <vector>
#include <utility>
#include <set>

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
				cout << "Processing " << ir.first << "-" << ir.second << endl;

				bool overlaps = false;
				pair<ulong,ulong> olrange;
				int pos = -1;
				for (int j=0;j<output->size();j++){
					pair<ulong,ulong> orange = output->at(j);

					cout << orange.first << endl;

					if (ir.first > orange.first && ir.first < orange.second) {
						overlaps = true;
						olrange = orange;
						pos = j;
						break;
					}

					if (ir.second > orange.first && ir.second < orange.second) {
						overlaps = true;
						olrange = orange;
						pos = j;
						break;
					}	
				}

				if (!overlaps) {
					cout << "no overlap, pushing range" << endl;
					pair<ulong,ulong> range = pair(ir.first,ir.second);
					output->push_back(range);
				} else{

					cout << "overlap" << endl;
					cout << "\t" << ir.first << "-" << ir.second << endl;
					cout << "\t" << olrange.first << "-" << olrange.second << endl;

					if (ir.first < olrange.first) {
						//olrange.first = ir.first;
						output->at(pos) = pair(ir.first,olrange.second);

					}

					if (ir.second > olrange.second) {
						//olrange.second = ir.second;
						output->at(pos) = pair(olrange.first, ir.second);
					}

				}
			}

			return output;
		}

		ulong generateFreshIDCount(){
			ulong total = 0;

			set<ulong> ids;

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
				cout << r.first << "-" << r.second << endl;

				ulong diff = (r.second - r.first) + 1;
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

		cout << "Done the reading" << endl;

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
