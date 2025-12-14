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

				float s1 = pow(x - otherBox->x, 2);
				float s2 = pow(y - otherBox->y, 2);
				float s3 = pow(z - otherBox->z, 2);

				distance = sqrt(s1+s2+s3);

				return distance;
			}

			void SetCircuit(Circuit* c){
				//cout << "Setting circuit for junction box" << endl;
				circuit = c;
				inCircuit = true;
			}
	};


	class Circuit{
		vector<JunctionBox> boxes;
		public:
			Circuit()
			{}

			void AddJunctionBox(JunctionBox* boxToAdd){
			//	cout << "Adding box to circuit" << endl;
				boxes.push_back(*boxToAdd);
				boxToAdd->SetCircuit(this);
			}

			int GetCircuitSize(){
				return boxes.size();
			}
	};

	class DistanceMap{
		vector<JunctionBox*> junctionBoxes;
		
		public:
			DistanceMap(vector<JunctionBox*> inputBoxes)
			{
				for (int i=0;i<inputBoxes.size();i++){

					JunctionBox jb = *inputBoxes[i];
			//		cout << "x: " << jb.x << endl;
					junctionBoxes.push_back(inputBoxes[i]);
				}


				for (int i=0;i<junctionBoxes.size();i++){
					JunctionBox jb = *junctionBoxes[i];
			//		cout << "JB " << i << " x: " << jb.x << ", inCircuit: " << jb.inCircuit << endl;
				}

			}

			vector<tuple<float,JunctionBox*,JunctionBox*>> GenerateDistance(){

				vector<tuple<float,JunctionBox*,JunctionBox*>> distanceList;

				for(int i=0;i<junctionBoxes.size();i++){
					for(int j=i+1;j<junctionBoxes.size();j++){

						//cout << "processing " << i << "," << j << endl;

						float distance = junctionBoxes[i]->GetDistance(junctionBoxes[j]);
						//cout << "\tDistance: " << distance << endl;

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

			//cout << "JB: " << i << " x: " << jb->x << ", y: " << jb->y << ", z: " << jb->z << ", inCircuit: " << jb->inCircuit << endl; 
			boxes.push_back(jb);
		}
		return boxes;
	}

	vector<tuple<float,JunctionBox*, JunctionBox*>> distanceMap(vector<JunctionBox*> boxes){
		DistanceMap map(boxes);
		return map.GenerateDistance();
	//	return map
	}

	void buildCircuits(vector<tuple<float,JunctionBox*,JunctionBox*>> distanceList)
	{
		cout << "Building Circuits" << endl;
		vector<Circuit*> circuits;

		for(int i=0;i<1000;i++){

			tuple<float,JunctionBox*,JunctionBox*> pair = distanceList[i];

			JunctionBox* box1 = get<1>(pair);
			JunctionBox* box2 = get<2>(pair);

			//cout << box1 << endl;
			//cout << "Box 1 - x: " << box1.x << ", y: " << box1.y << ", z: " << box1.z << " Incircuit: " << box1.inCircuit << endl;

			//cout << "Box 2 - x: " << box2.x << ", y: " << box2.y << ", z: " << box2.z << " Incircuit: " << box2.inCircuit << endl;

			if (box1->inCircuit || box2->inCircuit){
			//	cout << "A box is in a circuit" << endl;

			//	cout << "\t" << box1->inCircuit << endl;
				//cout << "\t" << box2->inCircuit << endl;

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
					cout << "Both boxes are already in circuits" << endl;

					if (box1->circuit == box2->circuit){
						cout << "Both boxes already in same circuit" << endl;
					}
				}
			} else {
				//cout << "Neither box is in a circuit" << endl;
				Circuit* newCircuit = new Circuit();

				//cout << "Box 1 inCircuit: " << box1.inCircuit << endl;
				//cout << "Box 2 inCircuit: " << box2.inCircuit << endl;
				newCircuit->AddJunctionBox(box1);
				newCircuit->AddJunctionBox(box2);

				//cout << "Box 1 inCircuit: " << box1.inCircuit << endl;
				//cout << "Box 2 inCircuit: " << box2.inCircuit << endl;
				//
				
				circuits.push_back(newCircuit);
			}	
		}

		cout << "Built " << circuits.size() << " circuits" << endl;
	}

	void partOne(vector<string> input){
		cout << "\t\tPart One" << endl;

		cout<< "Got: " << input.size() << " input" << endl;
		vector<JunctionBox*> boxes = parseInput(input);

		JunctionBox* jb = boxes[0];
		JunctionBox jb1 = *jb;
		//cout << "x: " << jb1.x << endl;

		//cout << "Parsed into " << boxes.size() << " junction boxes" << endl;

		vector<tuple<float,JunctionBox*,JunctionBox*>> distanceList = distanceMap(boxes);
		buildCircuits(distanceList);

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
