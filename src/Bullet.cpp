#include "Bullet.hpp"

Bullet::Bullet(): Symbol('|', 0, 0, 1000), direction(-1)
{
}

Bullet::~Bullet()
{
}

Bullet::Bullet(const Bullet & src) {
    *this = src;
    return ;
}

Bullet &Bullet::operator=( Bullet const & rhs) {
    setView(rhs.getView());
    setXpos(rhs.getXpos());
    setYpos(rhs.getYpos());
	setDirection(rhs.getDirection());
	return *this;
}

Bullet::Bullet(char p_view, int p_x, int p_y, int p_dir, int p_speed): Symbol(p_view, p_x, p_y, p_speed), direction(p_dir)
{
}

Bullet::Bullet(int p_x, int p_y, int p_dir): Symbol('|', p_x, p_y, 1000), direction(p_dir)
{
}

Bullet::Bullet(int p_x, int p_y): Symbol('|', p_x, p_y, 1000), direction(-1)
{
}


void	Bullet::fly()
{
	updYpos(this->direction);
}

int		Bullet::getDirection(void) const { return (direction); }
void	Bullet::setDirection(int p_dir) { this->direction = p_dir; }


