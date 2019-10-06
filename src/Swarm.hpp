#ifndef SWARM_HPP
# define SWARM_HPP

# include "Enemy.hpp"
# include "Bullet.hpp"
class Swarm
{
private:
	int		size;
	int		died;
	int		spawnedAmount;
	int		spawnSpeed;
	Enemy	**arr;
	
	unsigned long long		lastUpdateTime;
public:
	Swarm();
	Swarm(int p_size, int p_fieldWidth, int p_spawnSpeed);
	~Swarm();
	Swarm(Swarm const &cpy);
	Swarm	&operator=(Swarm const &);
	
	void	spawnMob();
	void	moveSwarm();
	void	isMobDied(Bullet **bullets, int bulletsAmount);
	bool	isSwarmWin(int fieldHeight);
	bool	isPlayerKilled(int playerX, int playerY);
	bool	isSwarmLost();
	void	drawSwarm();
};

#endif

