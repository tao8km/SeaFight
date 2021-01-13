#pragma once

class Cell
{
	bool active = true;
	char symbol;
protected:
	void setSymbol(char c) { symbol = c; }
public:
	Cell(char c) : symbol{ c }
	{}
	virtual bool isActive() const { return active; }
	virtual char getSymbol() const { return symbol; }
	virtual void hit() { active = false; }
};

class Water : public Cell
{
public:
	Water(char c) : Cell(c)
	{}
	void hit() override {
		Cell::hit();
		setSymbol('.');
	}
};

class ShipPart : public Cell
{
public:
	ShipPart(char c) : Cell(c)
	{}
	void hit() override {
		Cell::hit();
		setSymbol('x');
	}
};