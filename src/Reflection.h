#pragma once

#include <vector>
#include <fstream>

using AOE_FUNCTION_PTR = void (*)(std::ifstream& file);


struct AoeLevel {
	AOE_FUNCTION_PTR Ptr;
	std::string Name;
};

class AoeLevelStore {
public:
	std::vector<AoeLevel>& GetLevels();
	void RegisterLevel(const AoeLevel& level);

	//Singleton
	static AoeLevelStore& Instance();
	AoeLevelStore(AoeLevelStore const&) = delete;
	void operator=(AoeLevelStore const&) = delete;
private: 
	AoeLevelStore() = default;
	std::vector<AoeLevel> m_Levels;
};

class AoeReflector {
public:
	AoeReflector(AoeLevel level);
};

#define AOE_DAY(name)																					\
	void AOE_DAY_##name(std::fstream& file);															\
	AoeReflector AOE_DAY_REFLECTOR_##name({(AOE_FUNCTION_PTR)&AOE_DAY_##name, STR(name)});				\
	void AOE_DAY_##name(std::fstream& file)																\

