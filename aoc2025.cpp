#include <iostream>

#include "dayone.hpp"
#include "daytwo.hpp"
#include "daythree.hpp"
#include "dayfour.hpp"
#include "dayfive.hpp"
#include "daysix.hpp"
#include "dayseven.hpp"
#include "dayeight.hpp"
#include "daynine.hpp"
#include "dayten.hpp"
#include "dayeleven.hpp"
#include "daytwelve.hpp"

using namespace std;

int main(){
	cout << "Advent of Code 2025" << endl;

	DayOne::dayone();
	DayTwo::go();
	DayThree::go();
	DayFour::go();	
	DayFive::go();
	DaySix::go();
	DaySeven::go();
	DayEight::go();
	DayNine::go();
	DayTen::go();
	DayEleven::go();
	DayTwelve::go();
}
