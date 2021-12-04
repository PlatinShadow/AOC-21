#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include <fcntl.h>
#include <io.h>

#include "Core/Reflection.h"
#include "Core/Logging.h"

void main() {

	AOE_INFO("Registered " << AoeLevelStore::Instance().GetLevels().size() << " AOE Levels");
	std::ifstream infile;

	auto& levels = AoeLevelStore::Instance().GetLevels();
	
	for (auto& level : levels) {
		AOE_INFO("---------- Level " << level.Name << " ----------");
		
		std::ifstream infile("input/" + level.Name.substr(0, 1) + ".txt");
		if (infile.is_open() == false) {
			AOE_ERROR("Fatal Error: could not open file for level " << level.Name);
			return;
		}

		level.Ptr(infile);
		std::cout << std::endl;
	}	
}
