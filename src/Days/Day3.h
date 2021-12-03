#pragma once

#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

#define NUMBER_BITS 12

AOE_DAY(3A) {
	std::string entry;

	int ones[NUMBER_BITS] = {0};
	int zeros[NUMBER_BITS] = {0};


	while (file >> entry) {
		for (int i = 0; i < NUMBER_BITS; i++) {
			if (entry[i] == '1') {
				ones[i] += 1;
			}
			else {
				zeros[i] += 1;
			}
		}
	}

	std::bitset<NUMBER_BITS> rate;

	for (int i = 0; i < NUMBER_BITS; i++) {
		if (ones[i] > zeros[i]) {
			rate[NUMBER_BITS-i-1] = 1;
		}
	}

	std::cout << "Gamma Rate: " << rate << std::endl;

	int gammaRate = (int)rate.to_ulong();
	rate.flip();
	std::cout << "Epsilon Rate: " << rate << std::endl;
	int epsilonRate = (int)rate.to_ulong();

	std::cout << "Total Power Consumption: " << gammaRate * epsilonRate << std::endl;

}

std::string FindBitCriteria(std::vector<std::string> entries, bool filterForMostCommon) {
	std::vector<std::string> b;

	auto* set = &entries;
	auto* filtered = &b;

	bool found = false;
	int bitPos = 0;
	char keepBit = '0';

	int ones = 0;
	int zeroes = 0;


	while (!found) {
		
		for (auto x : *set) {
			if (x[bitPos] == '1') {
				ones++;
			}
			else {
				zeroes++;
			}
		}

		if (filterForMostCommon) {
			keepBit = ones > zeroes ? '1' : '0';
			keepBit = ones == zeroes ? '1' : keepBit;
		} else {
			keepBit = ones < zeroes ? '1' : '0';
			keepBit = ones == zeroes ? '0' : keepBit;
		}

		for (auto x : *set) {
			if (x[bitPos] == keepBit) {
				filtered->push_back(x);
			}
		}

		if (filtered->size() == 1) {
			found = true;
			break;
		}

		auto* tmp = filtered;
		filtered = set;
		set = tmp;
		filtered->clear();
		bitPos++;
		ones = 0;
		zeroes = 0;
	}

	return (*filtered)[0];
}

AOE_DAY(3B) {
	std::string entry;
	std::vector<std::string> entries;

	while (file >> entry) {
		entries.push_back(entry);
	}

	std::string strOxyRating = FindBitCriteria(entries,  true);
	std::string strCo2Rating = FindBitCriteria(entries, false);

	int oxyRating = std::stol(strOxyRating, nullptr, 2);
	int co2Rating = std::stol(strCo2Rating, nullptr, 2);

	std::cout << "Oxy " << oxyRating << " (" << strOxyRating  << ")" << std::endl;
	std::cout << "Co2 " << co2Rating << " (" << strCo2Rating << ")" << std::endl;

	std::cout << "Life Support Rating: " << oxyRating * co2Rating;
}