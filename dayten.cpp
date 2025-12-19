#include <iostream>
#include <vector>

#include "cutil"

#include "dayten.hpp"

using namespace std;

namespace DayTen{

	class Machine{
		string targetLights;
		string currentLights;
		vector<string> buttons;

		string previousButtonPressed;
		int buttonPressedCount;
	
		string path;	
		public:

		Machine(string lights, vector<string> buttons):
			targetLights(lights), buttons(buttons)
		{
			currentLights = targetLights;
			previousButtonPressed = "";
			buttonPressedCount = 0;
			path = "";

			for(int i=0;i<currentLights.size();i++) {
				currentLights[i] = '.';
			}
		}


		Machine(string targetLights, string currentlights, vector<string> buttons, int pressedCount, string pressedButton, string path):
			targetLights(targetLights), currentLights(currentlights), buttons(buttons), buttonPressedCount(pressedCount), previousButtonPressed(pressedButton), path(path)
		{
		}

		vector<string> getAllButtons(){
			return buttons;
		}

		vector<string> getValidButtons(){
			vector<string> validButtons;

			for(int i=0;i<buttons.size();i++){
				if (buttons[i] != previousButtonPressed){
					validButtons.push_back(buttons[i]);
				}
			}
			return validButtons;
		}

		Machine* pressButton(string buttonPressed){

			string newLights = currentLights;
			for(int i=0;i<buttonPressed.size();i++){
		
				if (buttonPressed[i] != ',' && buttonPressed[i] != '(' && buttonPressed[i] != ')') {

					int lightNo = stoi(string{ buttonPressed[i]});
					newLights[lightNo] == '.' ? newLights[lightNo] = '#' : newLights[lightNo] = '.';
				}
			}

			string newpath = path + " " + buttonPressed;
			Machine* newMachine = new Machine(targetLights, newLights, getAllButtons(), buttonPressedCount+1, buttonPressed, newpath);

			return newMachine;
		}

		bool isCorrect() {
			return currentLights == targetLights;
		}

		int PressedCount(){
			return buttonPressedCount;
		}

	};

	void partOne(vector<Machine*> machines){
		cout << "\t\tPart One" << endl;

		int buttonPressCount = 0;	
		for (int i=0; i<machines.size();i++){
			vector<Machine*> machineStates;
			machineStates.push_back(machines[i]);

			
			while (machineStates.size() > 0){

				int buttonPressesToCorrect = 0;
				Machine* currentMachine = machineStates[0];


				vector<string> validButtons = currentMachine->getValidButtons();
				for (int j=0;j<validButtons.size();j++) {

					Machine* newState = currentMachine->pressButton(validButtons[j]);

					if (newState->isCorrect()){
						buttonPressesToCorrect = newState->PressedCount();
						break;
					}
					machineStates.push_back(newState);

				}

				if (buttonPressesToCorrect != 0){
					buttonPressCount += buttonPressesToCorrect;
					break;
				}
				machineStates.erase(machineStates.begin());
					
			}
			
		}
	
		cout << "\t\t\tFewest Button Presses: " << buttonPressCount << endl;	

	}

	void partTwo(){
		cout << "\t\tPart Two" << endl;
	}

	vector<Machine*> parseInput(vector<string> input){
		vector<Machine*> machines;

		for(int i=0; i<input.size(); i++) {
			string data = input[i];

			int split = data.find(']');
			string lights = data.substr(1,split-1);

			data = data.substr(split+1);
			split = data.find('{');
			string switches = data.substr(1,split-2);
			//TODO parse out jolts too

			vector<string> switchList = Util::String::split(switches, ' ');

			Machine* m = new Machine(lights, switchList);
			machines.push_back(m);
		}
		return machines;
	}

	void go(){
		cout << "\tDay Ten" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_dayten.txt");

		vector<Machine*> machines = parseInput(input);
		partOne(machines);
		partTwo();
	}
}
