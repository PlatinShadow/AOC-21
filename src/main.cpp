#include <iostream>
#include <fstream>
#include "Reflection.h"
#include <algorithm>
#include <string>

void main() {
	std::cout << "Registered " << AoeLevelStore::Instance().GetLevels().size() << " AOE Levels" << std::endl;
	std::ifstream infile;

	auto& levels = AoeLevelStore::Instance().GetLevels();
	
	for (auto& level : levels) {
		std::cout << std::endl << std::endl << "---------- Level " << level.Name << " ----------" << std::endl;
		
		//First Run Test Case
		//std::ifstream testFile("input/" + level.Name);

		std::ifstream infile("input/" + level.Name.substr(0, 1) + ".txt");
		if (infile.is_open() == false) {
			std::cout << "Fatal Error: could not open file for level " << level.Name << std::endl;
			return;
		}

		level.Ptr(infile);
	}	
}
