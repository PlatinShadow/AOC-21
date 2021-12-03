#include <iostream>
#include <fstream>
#include "Util.h"
#include "Reflection.h"
#include "Days/Days.h"
#include <functional>

#define DAY 3
#define PART B


#define AOE_RUN EVALUATOR(AOE_DAY_,EVALUATOR(DAY,PART))
#define AOE_FILE STR(EVALUATOR(input/, DAY.txt))

void main() {
	std::cout << "Registered " << AoeLevelStore::Instance().GetLevels().size()  << " AOE Levels" << std::endl;

	for (auto& level : AoeLevelStore::Instance().GetLevels()) {
		std::cout << "Running Level " << level.Name << std::endl;
		
		std::ifstream infile("input/" + level.Name.substr(0,1) + ".txt");
		if (infile.is_open() == false) {
			std::cout << "Fatal Error: could not open file for level " << level.Name << std::endl;
			return;
		}


		level.Ptr(infile);
	}	
}
