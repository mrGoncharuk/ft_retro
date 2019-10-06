#include "Swarm.hpp"

Swarm::Swarm(/* args */): size(0), arr(NULL), spawnSpeed(2000), lastUpdateTime(get_curr_time()), spawnedAmount(0), died(0)
{
}

Swarm::Swarm(int p_size, int p_fieldWidth, int p_spawnSpeed):size(p_size), spawnSpeed(p_spawnSpeed), spawnedAmount(0), died(0)
{
	if (size < 1)
		arr = NULL;
	else
	{
		arr = new Enemy *[size];
		for (int i = 0; i < size; i++)
			arr[i] = new Enemy('E', p_fieldWidth, 300);
	}
	
}

Swarm::~Swarm()
{
	for (int i = 0; i < size; i++)
		if (arr[i] != NULL)
			delete arr[i];
	delete [] arr;
}


void	Swarm::spawnMob()
{
	if ((get_curr_time() - lastUpdateTime) >= spawnSpeed && spawnedAmount < size)
	{
		spawnedAmount++;
		lastUpdateTime = get_curr_time();
	}
}


void	Swarm::moveSwarm()
{
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
			arr[i]->show_symb();
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


bool	Swarm::isSwarmWin(int fieldHeight)
{
	for (int i = 0; i < size; i++)
		if (arr[i] != NULL)
		{
			if (arr[i]->getYpos() == (fieldHeight - 1))
				return (true);
			else
				break ;
		}
	return (false);
}


bool	Swarm::isPlayerKilled(int playerX, int playerY)
{
	for (int i = 0; i < size; i++)
		if (arr[i] != NULL)
		{
			if ((arr[i]->getYpos() == playerY) && (arr[i]->getXpos() == playerX))
				return (true);
			else
				break ;
		}
	return (false);
}

bool	Swarm::isSwarmLost()
{
	if (this->spawnedAmount == this->died)
		return (true);
	return (false);
}


