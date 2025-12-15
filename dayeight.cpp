#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

#include "cutil"

#include "dayeight.hpp"

using namespace std;

namespace DayEight{

	class Circuit;

	class JunctionBox{
		public:
		uint x;
		uint y;
		uint z;
		Circuit* circuit;

		public:
			bool inCircuit = false;

			JunctionBox(uint x, uint y, uint z):
				x(x),y(y),z(z)
			{
				inCircuit = false;
			}

			float GetDistance(JunctionBox* otherBox){

				float distance = 0.0;

				uint x1 = abs(int(x - otherBox->x));
				float s1 = pow(x1, 2);
				float s2 = pow(abs(int(y - otherBox->y)), 2);
				float s3 = pow(abs(int(z - otherBox->z)), 2);

				distance = sqrt(s1+s2+s3);

				return distance;
			}

			void SetCircuit(Circuit* c){
				circuit = c;
				inCircuit = true;
			}
	};


	class Circuit{
		vector<JunctionBox*> boxes;
		public:
			Circuit()
			{}

			void AddJunctionBox(JunctionBox* boxToAdd){
				boxes.push_back(boxToAdd);
				boxToAdd->SetCircuit(this);
			}

			int GetCircuitSize(){
				return boxes.size();
			}

			vector<JunctionBox*> GetBoxes(){
				return boxes;
			}

			void Clear(){
				boxes.clear();
			}

			void Merge(Circuit* otherCircuit){
				vector<JunctionBox*> otherBoxes = otherCircuit->GetBoxes();

				for (int i=0; i<otherBoxes.size(); i++){
					AddJunctionBox(otherBoxes[i]);	
				}

				otherCircuit->Clear();
				
			}
	};

	class DistanceMap{
		vector<JunctionBox*> junctionBoxes;
		
		public:
			DistanceMap(vector<JunctionBox*> inputBoxes)
			{
				for (int i=0;i<inputBoxes.size();i++){

					JunctionBox jb = *inputBoxes[i];
					junctionBoxes.push_back(inputBoxes[i]);
				}


				for (int i=0;i<junctionBoxes.size();i++){
					JunctionBox jb = *junctionBoxes[i];
				}

			}

			vector<tuple<float,JunctionBox*,JunctionBox*>> GenerateDistance(){

				vector<tuple<float,JunctionBox*,JunctionBox*>> distanceList;

				for(int i=0;i<junctionBoxes.size();i++){
					for(int j=i+1;j<junctionBoxes.size();j++){


						float distance = junctionBoxes[i]->GetDistance(junctionBoxes[j]);

						tuple<float, JunctionBox*,JunctionBox*> tp = {distance, junctionBoxes[i], junctionBoxes[j]};

						distanceList.push_back(tp);
					}
				}

				struct{
					bool operator() (tuple<float, JunctionBox*,JunctionBox*> a, tuple<float, JunctionBox*, JunctionBox*> b) const {return get<0>(a) < get<0>(b);}} customLess;

				sort(distanceList.begin(), distanceList.end(), customLess);

				return distanceList;
			}
	};

	vector<JunctionBox*> parseInput(vector<string> input){
		vector<JunctionBox*> boxes;

		for(int i=0; i<input.size();i++){
			string coords = input[i];
			int split = coords.find(',');
			int x = stoi(coords.substr(0,split));
			coords = coords.substr(split+1);
			split = coords.find(',');
			int y = stoi(coords.substr(0,split));
			int z = stoi(coords.substr(split+1));

			JunctionBox* jb = new  JunctionBox(x,y,z);

			boxes.push_back(jb);
		}
		return boxes;
	}

	vector<tuple<float,JunctionBox*, JunctionBox*>> distanceMap(vector<JunctionBox*> boxes){
		DistanceMap map(boxes);
		return map.GenerateDistance();
	}

	vector<Circuit*> buildCircuits(vector<tuple<float,JunctionBox*,JunctionBox*>> distanceList)
	{
		vector<Circuit*> circuits;

		for(int i=0;i<1000;i++){

			tuple<float,JunctionBox*,JunctionBox*> pair = distanceList[i];

			JunctionBox* box1 = get<1>(pair);
			JunctionBox* box2 = get<2>(pair);

			if (box1->inCircuit || box2->inCircuit){

				if (!box1->inCircuit){
					//Box 1 is not in a circuit
					//Box 2 must be in the circuit
					//
					//add box 1 to the box 2 circuit
					//
					Circuit* b2Circuit = box2->circuit;
					b2Circuit->AddJunctionBox(box1);
					
				} else if (!box2->inCircuit){

					//Box 2 is not in a circuit
					//Box 1 must be in the circuit
					//
					//add box 2 to the box 1 circuit
					Circuit* b1Circuit = box1->circuit;
					b1Circuit->AddJunctionBox(box2);
				}
				else {
					//Both boxes are in circuit
					//so we should merge circuits	
					if (box1->circuit != box2->circuit){

						//Need to merge circuits
						Circuit* b1Circuit = box1->circuit;
						Circuit* b2Circuit = box2->circuit;
						
						b1Circuit->Merge(b2Circuit);

					}
				}
			} else {
				Circuit* newCircuit = new Circuit();

				newCircuit->AddJunctionBox(box1);
				newCircuit->AddJunctionBox(box2);

				circuits.push_back(newCircuit);
			}	
		}

		return circuits;
	}

	void partOne(vector<string> input){
		cout << "\t\tPart One" << endl;

		vector<JunctionBox*> boxes = parseInput(input);

		vector<tuple<float,JunctionBox*,JunctionBox*>> distanceList = distanceMap(boxes);
		vector<Circuit*> circuits = buildCircuits(distanceList);

		int biggest = 0;
		int nextBiggest = 0;
		int thirdBiggest = 0;

		for (int i=0;i<circuits.size();i++){

			int circuitSize = circuits[i]->GetCircuitSize();

			if (circuitSize > thirdBiggest)
				thirdBiggest = circuitSize;

			if (circuitSize > nextBiggest){
				thirdBiggest = nextBiggest;
				nextBiggest = circuitSize;
			}

			if (circuitSize > biggest) {
				nextBiggest = biggest;
				biggest = circuitSize;
			}
		}

		int total = biggest * nextBiggest * thirdBiggest;
		cout << "\t\t\tTotal: " << total << endl;

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
