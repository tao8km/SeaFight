#pragma once
#include <memory>
#include <vector>
#include "Cell.h"

class Ship
{
	std::vector<std::shared_ptr<ShipPart>> ship;
public:
	Ship(const std::vector<std::shared_ptr<ShipPart>>& ship)
		: ship{ ship }
	{}
	int size() const { return ship.size(); }
	bool isActive() const {
		for (const auto& part : ship) {
			if (part->isActive())
				return true;
		}
		return false;
	}
};