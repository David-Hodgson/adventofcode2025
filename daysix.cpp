#include <iostream>
#include <vector>

#include "cutil"

#include "daysix.hpp"

using namespace std;

namespace DaySix{

	vector<vector<uint>> getNumberRowsFromInput (vector<string> input){

		vector<vector<uint>> rows;

		for(int i=0;i<input.size()-1;i++)
		{
			vector<uint> numberrow;
			string numberDigits = "";
			for (int k=0;k<input[i].length();k++)
			{
				if (input[i][k] != ' '){
					numberDigits = numberDigits + input[i][k];
				}
				else {
					if (numberDigits.length() > 0){
						int number = stoi(numberDigits);
						numberrow.push_back(number);
						numberDigits = "";
					}
				}
			}

			//Parse last entry
			if (numberDigits.length() > 0) {
				int lastnumber = stoi(numberDigits);
				numberrow.push_back(lastnumber);
			}
			rows.push_back(numberrow);
		}

		return rows;
	}

	vector<char> getOperatorsFromInput(vector<string> input){

		vector<char> operators;
		string operatorString = input[input.size()-1];

		for(int i=0; i< operatorString.length() ;i++)
		{
			if (operatorString[i] == ' ')
			{
				continue;
			}
			operators.push_back(operatorString[i]);
		}
		return operators;
	}

	ulong totalColumn(vector<uint> column, char op){
		ulong total = column[0];
	
		if (op == '+'){
			for (int i=1;i<column.size();i++)
			{
				total = total + column[i];
			}
		}

		if (op == '*'){
			for (int i=1;i<column.size();i++){
				total = total * column[i];
			}
		}
		
		return total;
	}

	void partOne(vector<vector<uint>> numbers, vector<char> operators){
		cout << "\t\tPart One" << endl;

		int colCount = numbers[0].size();
		ulong total = 0;

		for (int i=0;i<colCount;i++)
		{
			vector<uint> col;
			for(int j=0;j<numbers.size();j++)
			{
				col.push_back(numbers[j][i]);
			}
			total = total + totalColumn(col, operators[i]);
		}

		cout << "\t\t\tTotal: " << total << endl;
	}

	void partTwo(){
		cout << "\t\tPart Two" << endl;
	}

	void go(){
		cout << "\tDay Six" << endl;

		vector<string> input = Util::File::readFileAsListOfStrings("data/input_daysix.txt");
		vector<vector<uint>> numberRows = getNumberRowsFromInput(input);
		vector<char> operators = getOperatorsFromInput(input);
		
		partOne(numberRows, operators);
		
		partTwo();
	}
}
