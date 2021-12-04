#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include <fcntl.h>
#include <io.h>
#include <filesystem>

#include "Core/Reflection.h"
#include "Core/Logging.h"

void main() {

	AOE_DEBUG("Registered " << AoeLevelStore::Instance().GetLevels().size() << " AOE Levels");
	std::ifstream infile;

	auto& levels = AoeLevelStore::Instance().GetLevels();
	
	for (auto& level : levels) {
		AOE_INFO("---------- Level " << level.Name << " ----------");
		
		//First Run Test Case
		std::ifstream testFile("input/" + level.Name + "_TEST.txt");
		if (testFile.is_open()) {
			std::string expectedStr;
			std::getline(testFile, expectedStr);
			expectedStr.erase(0, 2);

			if (expectedStr.length() < 1) {
				AOE_ERROR("Error in Test Case File Syntax");
				return;
			}

			int expectedResult = std::stoi(expectedStr);
			int result = level.Ptr(testFile);
			if (result != expectedResult) {
				AOE_ERROR("Level failed Test Case");
				AOE_ERROR("Expected: " << expectedResult << " Got: " << result);
				return;
			}
			else {
				AOE_INFO("Passed Test Case");
			}
		}
		else {
			AOE_WARN("No Test Case File found!");
		}

		//Run Acctual Ibput
		std::ifstream infile("input/" + level.Name.substr(0, 1) + ".txt");
		if (infile.is_open() == false) {
			AOE_ERROR("Fatal Error: could not open file for level " << level.Name);
			return;
		}

		int answer = level.Ptr(infile);
		AOE_SUCCESS("Answer: " << answer);
		std::cout << std::endl;
	}	
}
