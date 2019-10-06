#pragma once

#include "Symbol.hpp"
#include "Bullet.hpp"

class Player: public Symbol
{
private:
	int		hp;
	static const int		max_bullets;
	Bullet	*bullets[3];
public:
	Player(/* args */);
	Player(char p_symb, int p_x, int p_y);
	~Player();
	void	send_bullet();
	Bullet	**getBullets();
	int		getMaxBullets();
	void	show_bullets();
};


