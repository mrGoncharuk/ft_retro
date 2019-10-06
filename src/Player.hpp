#pragma once

#include "Symbol.hpp"

class Player: public Symbol
{
private:
	/* data */
public:
	Player(/* args */);
	Player(char p_symb, int p_x, int p_y);
	~Player();
};


