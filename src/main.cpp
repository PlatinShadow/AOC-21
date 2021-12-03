#include <iostream>
#include <fstream>
#include "Days/Days.h"

#define DAY 3
#define PART B

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define PASTER(x,y) x ## y
#define EVALUATOR(x,y) PASTER(x,y)

#define AOE_RUN EVALUATOR(AOE_DAY_,EVALUATOR(DAY,PART))
#define AOE_FILE STR(EVALUATOR(input/, DAY.txt))

void main() {
	std::cout << "Running: " << STR(AOE_RUN) << std::endl;
	
	std::ifstream infile(AOE_FILE);
	if (infile.is_open() == false) {
		std::cout << "Could not find file: " << AOE_FILE << std::endl;
		return;
	}

	AOE_RUN(infile);
}
