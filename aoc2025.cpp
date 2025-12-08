#include <iostream>

#include "dayone.hpp"
#include "daytwo.hpp"
#include "daythree.hpp"
#include "dayfour.hpp"
#include "dayfive.hpp"
#include "daysix.hpp"
#include "dayseven.hpp"

using namespace std;

int main(){
	cout << "Advent of Code 2025" << endl;

	DayOne::dayone();
	DayTwo::go();
	DayThree::go();
	dayfour();
	DayFive::go();
	DaySix::go();
	DaySeven::go();
}
