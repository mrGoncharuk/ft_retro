#ifndef ENEMY_HPP
# define ENEMY_HPP


#include <stdlib.h>
#include <ctime>

#include "Symbol.hpp"
#include "Bullet.hpp"

class Enemy: public Symbol
{
private:
	int getRandPosition(int maxWidth);
public:
	Enemy();
	Enemy(char view, int maxWidth, int speed);
	~Enemy();
	Enemy(const Enemy & src);
	Enemy & operator=( Enemy const & rhs);
};

#endif
