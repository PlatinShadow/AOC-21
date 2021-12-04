#include "Reflection.h"
#include <iostream>
#include <fstream>
#include <string>

AoeReflector::AoeReflector(AoeLevel level) {
	AoeLevelStore::Instance().RegisterLevel(level);
}

void AoeLevelStore::RegisterLevel(const AoeLevel& level) {
	m_Levels.push_back(level);
}

std::vector<AoeLevel>& AoeLevelStore::GetLevels() {
	return m_Levels;
}

AoeLevelStore& AoeLevelStore::Instance() {
	static AoeLevelStore instance;
	return instance;
}