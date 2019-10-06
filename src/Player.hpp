#ifndef PLAYER_HPP
# define PLAYER_HPP

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
	~Player();
	Player(const Player & src);
	Player & operator=(Player const & rhs);
	Player(char p_symb, int p_x, int p_y);
	void	send_bullet();
	Bullet	**getBullets();
	int		getMaxBullets();
	void	show_bullets();
};

#endif