#include "Reflection.h"
#include <iostream>

//std::vector<AOE_FUNCTION_PTR> VoidReflector::s_Functions;
//
//VoidReflector::VoidReflector(AOE_FUNCTION_PTR ptr) {
//	VoidReflector::s_Functions.push_back(ptr);
//	std::cout << "Registered Function! n="  << VoidReflector::s_Functions.size()  << std::endl;
//}

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