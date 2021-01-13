#include "Board.h"
#include <string>
using namespace std;

void Board::createBoard(istream& in)
{
	string line;
	while (getline(in, line)) {
		vector<shared_ptr<Cell>> row;
		row.push_back(make_shared<Water>(WATER));
		for (auto c : line) {
			shared_ptr<Cell> cell;
			if (c == WATER) {
				cell = make_shared<Water>(WATER);
			}
			else if (c == SHIP) {
				cell = make_shared<ShipPart>(SHIP);
			}
			row.push_back(cell);
		}
		row.push_back(make_shared<Water>(WATER));
		cells.push_back(row);
	} // while

	vector<shared_ptr<Cell>> row(cells[0].size(),
		make_shared<Water>(WATER));
	cells.insert(cells.begin(), row);
	cells.push_back(row);
}

bool Board::isBoardCorrect() const
{
	return true;
}

void Board::createShips()
{
	for (int i = 1; i < cells.size() - 1; i++) {
		for (int j = 1; j < cells[i].size() - 1; j++) {
			if (cells[i][j]->getSymbol() == SHIP) {
				std::vector<std::shared_ptr<ShipPart>> ship;
				while (cells[i][j+1]->getSymbol() == SHIP) {
					ship.push_back(make_shared<ShipPart>(cells[i][j]));
					++j;
				}
				int k = i;
				while (cells[k+1][j]->getSymbol() == SHIP) {
					ship.push_back(make_shared<ShipPart>(cells[k][j]));
					++k;
				}
				ships.push_back(make_shared<Ship>(ship));
			}
		}
	}
}
