#pragma once
#include <fstream>
#include <string>

void AOE_DAY_2A(std::ifstream& file) {
	std::string command;
	int delta;
	int horizontal = 0;
	int depth = 0;
	while (file >> command >> delta) {
		switch (command[0]) {
		case 'f':
			horizontal += delta;
			break;
		case 'd':
			depth += delta;
			break;
		case 'u':
			depth -= delta;
			break;
		}
	}

	std::cout << "Final Position: " << horizontal * depth << std::endl;
}

void AOE_DAY_2B(std::ifstream& file) {
	std::string command;
	int delta;
	int horizontal = 0;
	int depth = 0;
	int aim = 0;

	while (file >> command >> delta) {
		switch (command[0]) {
		case 'f':
			horizontal += delta;
			depth += aim * delta;
			break;
		case 'd':
			aim += delta;
			break;
		case 'u':
			aim -= delta;
			break;
		}
	}

	std::cout << "Final Position: " << horizontal * depth << std::endl;
}