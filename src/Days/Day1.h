#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "Reflection.h"

AOE_DAY(1A) {
	std::string line;

	int prevDepth = 0;
	int increments = -1;
	while (std::getline(file, line)) {
		int depth = std::stoi(line);

		if (depth > prevDepth) {
			increments++;
		}

		prevDepth = depth;
	}

	std::cout << "Result: " << increments << " increments" << std::endl;
}

AOE_DAY(1B) {
	std::string line;

	int m1 = 0;
	int m2 = 0;
	int m3 = 0;
	int m4 = 0;

	int counter = 0;

	int increments = -1;
	while (std::getline(file, line)) {
		int depth = std::stoi(line);

		m1 = m2;
		m2 = m3;
		m3 = m4;
		m4 = depth;

		if (counter > 2) {
			if (m1 + m2 + m3 <  m2 + m3 + m4) {
				increments++;
			}
		}


		counter++;
	}


	if (m1 + m2 + m3 < m2 + m3 + m4) {
		increments++;
	}

	std::cout << "Result: " << increments << " increments" << std::endl;
}