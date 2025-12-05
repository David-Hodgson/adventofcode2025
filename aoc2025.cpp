#include <iostream>

#include "dayone.hpp"
#include "dayfour.hpp"
#include "dayfive.hpp"

using namespace std;

int main(){
	cout << "Advent of Code 2025" << endl;

	DayOne::dayone();
	dayfour();
	DayFive::go();
}
