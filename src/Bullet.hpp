#ifndef BULLET_HPP
# define BULLET_HPP

#include "Symbol.hpp"


class Bullet: public Symbol
{
	private:
		int		direction;
	public:
		Bullet();
		~Bullet();
		Bullet(const Bullet & src);
		Bullet & operator=(Bullet const & rhs);
		Bullet(char p_view, int p_x, int p_y, int p_dir, int p_speed);
		Bullet(int p_x, int p_y, int p_dir);
		Bullet(int p_x, int p_y);
	
		void	fly();
		int		getDirection(void) const;
		void	setDirection(int p_dir);
};


#endif