#pragma once

#include <iostream>

#define AOE_CLR "\u001b[0m"
#define AOE_MGT "\u001b[35m"
#define AOE_CYN "\u001b[36;1m"
#define AOE_BLU "\u001b[34;1m"
#define AOE_GRN "\u001b[32;1m"
#define AOE_YLO "\u001b[33;1m"
#define AOE_RED "\u001b[31;1m"

#define AOE_LOG(msg, type, color) \
	std::cout << color << "[" << type << "] " << msg << AOE_CLR << std::endl;

#define AOE_DEBUG(msg) AOE_LOG(msg, "D", AOE_CYN)
#define AOE_INFO(msg) AOE_LOG(msg, "I", AOE_BLU)
#define AOE_SUCCESS(msg) AOE_LOG(msg, "S", AOE_GRN)
#define AOE_WARN(msg) AOE_LOG(msg, "W", AOE_YLO)
#define AOE_ERROR(msg) AOE_LOG(msg, "E", AOE_RED)