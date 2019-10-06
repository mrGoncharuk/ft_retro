#ifndef BULLET_HPP
# define BULLET_HPP

#include "Symbol.hpp"


class Bullet: public Symbol
{
	private:
		int		direction;
		unsigned long long		lastUpdateTime;
	public:
		Bullet();
		Bullet(char p_view, int p_x, int p_y, int p_dir);
		Bullet(int p_x, int p_y, int p_dir);
		Bullet(int p_x, int p_y);
		~Bullet();
		void	fly();
};


#endif