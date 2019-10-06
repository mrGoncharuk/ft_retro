#include "Bullet.hpp"

Bullet::Bullet(): Symbol('|', 0, 0), direction(-1), lastUpdateTime(get_curr_time())
{
}

Bullet::Bullet(char p_view, int p_x, int p_y, int p_dir): Symbol(p_view, p_x, p_y), direction(p_dir)
{
}

Bullet::Bullet(int p_x, int p_y, int p_dir): Symbol('|', p_x, p_y), direction(p_dir)
{
}

Bullet::Bullet(int p_x, int p_y): Symbol('|', p_x, p_y), direction(-1)
{
}

Bullet::~Bullet()
{

}

void	Bullet::fly()
{
	if ((get_curr_time() - lastUpdateTime) >= 100)
	{
		updYpos(direction);
		lastUpdateTime = get_curr_time();
	}
}
