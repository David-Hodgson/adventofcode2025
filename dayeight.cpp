#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

#include "cutil"

#include "dayeight.hpp"

using namespace std;

namespace DayEight{

	class JunctionBox{
		uint x;
		uint y;
		uint z;

		public:

			JunctionBox(uint x, uint y, uint z):
				x(x),y(y),z(z)
			{}

			float GetDistance(JunctionBox otherBox){

				float distance = 0.0;

				float s1 = pow(x - otherBox.x, 2);
				float s2 = pow(y - otherBox.y, 2);
				float s3 = pow(z - otherBox.z, 2);

				distance = sqrt(s1+s2+s3);

				return distance;
			}
	};

	class DistanceMap{
		vector<JunctionBox> junctionBoxes;
		
		public:
			DistanceMap(vector<JunctionBox> inputBoxes)
			{
				for (int i=0;i<inputBoxes.size();i++){
					junctionBoxes.push_back(inputBoxes[i]);
				}
			}

			void GenerateDistance(){

				vector<tuple<float,JunctionBox,JunctionBox>> distanceList;

				for(int i=0;i<junctionBoxes.size();i++){
					for(int j=i+1;j<junctionBoxes.size();j++){

						//cout << "processing " << i << "," << j << endl;

						float distance = junctionBoxes[i].GetDistance(junctionBoxes[j]);
						//cout << "\tDistance: " << distance << endl;

						tuple<float, JunctionBox,JunctionBox> tp = {distance, junctionBoxes[i], junctionBoxes[j]};

						distanceList.push_back(tp);
					}
				}

				struct{
					bool operator() (tuple<float, JunctionBox,JunctionBox> a, tuple<float, JunctionBox, JunctionBox> b) const {return get<0>(a) < get<0>(b);}} customLess;

				sort(distanceList.begin(), distanceList.end(), customLess);

				for(int i=0;i<1000;i++){
					cout << i << ": " << get<0>(distanceList[i]) << endl;
				}
			}
	};

	vector<JunctionBox> parseInput(vector<string> input){
		vector<JunctionBox> boxes;

		for(int i=0; i<input.size();i++){
			string coords = input[i];
			int split = coords.find(',');
			int x = stoi(coords.substr(0,split));
			coords = coords.substr(split+1);
			split = coords.find(',');
			int y = stoi(coords.substr(0,split));
			int z = stoi(coords.substr(split+1));

			JunctionBox jb = JunctionBox(x,y,z);
			boxes.push_back(jb);
		}
		return boxes;
	}

	void  distanceMap(vector<JunctionBox> boxes){
		DistanceMap map(boxes);
		map.GenerateDistance();
	//	return map
	}

	void partOne(vector<string> input){
		cout << "\t\tPart One" << endl;

		cout<< "Got: " << input.size() << " input" << endl;
		vector<JunctionBox> boxes = parseInput(input);

		cout << "Parsed into " << boxes.size() << " junction boxes" << endl;

		distanceMap(boxes);


	}

	void partTwo(){
		cout << "\t\tPart Two" << endl;
	}

	void go(){
		cout << "\tDay Eight" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayeight.txt");
		partOne(input);
		partTwo();
	}
}
