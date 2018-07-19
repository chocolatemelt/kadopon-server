#include <iostream>
#include <random>

#include "utilities/RandomUtilities.hpp"

int RandomUtilities::roll_movement(int numofrolls) {
	//int roll;
    std::mt19937 gen;
    // 5% of the time, roll a 0
    // 5% of the time, roll a 1
    // 10% of the time, roll a 2
    // 25% of the time, roll a 3
    // 25% of the time, roll a 4
    // 20% of the time, roll a 5
    // 10% of the time, roll a 6
    std::vector<double> i{0,  1,  2,   3,   4,   5,   6,   7};
    std::vector<double> w{  5,  5,  10,  25,  25,  20,  10};
    std::piecewise_constant_distribution<> rolldie(i.begin(), i.end(), w.begin());

    //roll = (int)ceil(rolldie(gen));

    /*
    std::map<int, int> rolldist;
    for(int i=0; i<10000; ++i) {
        ++rolldist[d(gen)];
    }
    for(auto r : rolldist) {
        std::cout << r.first << ' ' << std::string(r.second/100, '*') << '\n';
    }
    */
    return 1;
}