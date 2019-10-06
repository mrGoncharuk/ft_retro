#pragma once

#include "Symbol.hpp"
#include <stdlib.h>
#include <ctime>

class Enemy: public Symbol
{
private:
    void putEnemy(int maxWidth);
	/* data */
public:
	Enemy(/* args */);
	Enemy(char view, int maxWidth);
	~Enemy();
    Enemy(const Enemy & src);
    Enemy & operator=( Enemy const & rhs);
};
