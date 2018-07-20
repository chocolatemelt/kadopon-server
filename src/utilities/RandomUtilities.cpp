#include <random>

#include "utilities/RandomUtilities.hpp"

int RandomUtilities::roll_movement(int n) {
	std::random_device rd;
	std::mt19937 gen(rd());
	// see docs for full distribution of movement rolls
	std::vector<double> i{0,  1,  2,   3,   4,   5,   6,   7};
	std::vector<double> w{  5,  5,  10,  25,  25,  20,  10};
	std::piecewise_constant_distribution<> dist(i.begin(), i.end(), w.begin());
	
	return static_cast<int>(dist(gen));
}
