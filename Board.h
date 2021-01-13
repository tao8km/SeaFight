#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include "Cell.h"
#include "Ship.h"

class Board
{
	std::vector<std::vector<std::shared_ptr<Cell>>> cells;
	std::vector<std::shared_ptr<Ship>> ships;
public:
	Board(std::istream& in) {
		createBoard(in);
		if (!isBoardCorrect()) {
			throw std::invalid_argument("Board is not correct");
		}
		createShips();
	}

	enum { WATER = ' ', SHIP = '#' };

private:
	void createBoard(std::istream& in);
	bool isBoardCorrect() const;
	void createShips();
};

