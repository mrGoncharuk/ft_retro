#include "Swarm.hpp"

Swarm::Swarm(/* args */): size(0), arr(NULL), spawnSpeed(2000), lastUpdateTime(get_curr_time()), spawnedAmount(0), died(0), mobSpeed(0), bullet(NULL)
{
}

Swarm::Swarm(int p_size, int p_fieldWidth, int p_spawnSpeed, int p_mobSpeed):size(p_size), spawnSpeed(p_spawnSpeed), mobSpeed(p_mobSpeed), spawnedAmount(0), died(0), bullet(NULL)
{
	if (size < 1)
		arr = NULL;
	else
	{
		arr = new Enemy *[size];
		for (int i = 0; i < size; i++)
			arr[i] = new Enemy('E', p_fieldWidth, mobSpeed);
	}
}

Swarm::~Swarm()
{
	for (int i = 0; i < size; i++)
		if (arr[i] != NULL)
			delete arr[i];
	delete [] arr;
	if (bullet)
		delete bullet;
}


void	Swarm::spawnMob()
{
	if ((get_curr_time() - lastUpdateTime) >= spawnSpeed && spawnedAmount < size)
	{
		spawnedAmount++;
		lastUpdateTime = get_curr_time();
		if (spawnedAmount % 5 == 4)
		{
			if (bullet == NULL)
				bullet = new Bullet('V', arr[spawnedAmount - 1]->getXpos(), arr[spawnedAmount - 1]->getYpos() + 1, 1, 150);
		}
	}
}


void	Swarm::moveSwarm()
{
	if (bullet)
		if (bullet->isReadyForUpdate())
			bullet->fly();
	for (int i = 0; i < spawnedAmount; i++)
	{
		if (arr[i] != NULL)
			if (arr[i]->isReadyForUpdate())
				arr[i]->updYpos(1);
	}
}


void	Swarm::drawSwarm()
{
	for (int i = 0; i < spawnedAmount; i++)
		if (arr[i] != NULL)
		{
			arr[i]->show_symb();
		}
	if (bullet != NULL)
		bullet->show_symb();
}

void	Swarm::isMobDied(Bullet **bullets, int bulletsAmount)
{
	for (int i = 0; i < bulletsAmount; i++)
	{
		if (bullets[i] != NULL)
		{
			for (int j = 0; j < spawnedAmount; j++)
			{
				if (arr[j] != NULL)
					if (*(arr[j]) == *(bullets[i]))
					{
						delete arr[j];
						delete bullets[i];
						arr[j] = NULL;
						bullets[i] = NULL;
						died++;
						break ;
					}
			}
		}
	}
}

bool	Swarm::isPlayerKilled(int playerX, int playerY, int fieldHeight)
{
	int		i = 0;


	if (bullet != NULL)
	{
		if (((bullet->getYpos()) >= playerY) && ((playerX - 2) >= bullet->getXpos() || (playerX - 2) <= bullet->getXpos()))
			return (true);
		if (bullet->getYpos() == fieldHeight)
		{
			delete bullet;
			bullet = NULL;
		}
	}
	while (i < size)
	{
		if (arr[i] != NULL)
		{
			if ((playerY - arr[i]->getYpos()) <= 0 && ((playerX - 2) >= arr[i]->getXpos() && (playerX - 2) < arr[i]->getXpos()))
			{
				return (true);
			}
			else
			{
				break ;
			}
		}
		i++;
	}
	while (i < size)
	{
		if (arr[i] != NULL)
		{
			if (arr[i]->getYpos() == (fieldHeight - 2))
				return (true);
		}
		i++;
	}
	return (false);
}

bool	Swarm::isSwarmLost()
{
	if (this->spawnedAmount == this->died)
		return (true);
	return (false);
}
