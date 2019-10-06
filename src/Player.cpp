#include "Player.hpp"

const int Player::max_bullets = 3;

Player::Player(): Symbol('T', 0, 0), hp(3)
{
	for (int i = 0; i < max_bullets; i++)
		bullets[i] = NULL;
}

Player::Player(char p_symb, int p_x, int p_y): Symbol(p_symb, p_x, p_y), hp(3)
{	
}

Player::~Player()
{
}

Bullet	**Player::getBullets()
{
	return (bullets);
}

int		Player::getMaxBullets()
{
	return (Player::max_bullets);
}

void	Player::send_bullet()
{
	for (int i = 0; i < max_bullets; i++)
	{
		if (bullets[i] == NULL)
		{
			bullets[i] = new Bullet(this->x, this->y - 1);
			break ;
		}
	}
}

void	Player::show_bullets()
{
	for (int i = 0; i < Player::max_bullets; i++)
	{
		if (bullets[i] != NULL)
			bullets[i]->show_symb();
	}
}
