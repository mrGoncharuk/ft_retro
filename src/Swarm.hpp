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
	int		mobSpeed;
	Enemy	**arr;
	Bullet	*bullet;
	
	unsigned long long		lastUpdateTime;
public:
	Swarm();
	Swarm(int p_size, int p_fieldWidth, int p_spawnSpeed, int p_mobSpeed);
	~Swarm();
	Swarm(Swarm const &cpy);
	Swarm	&operator=(Swarm const &);
	
	void	spawnMob();
	void	moveSwarm();
	bool	isMobDied(Bullet **bullets, int bulletsAmount);
	bool	isPlayerKilled(int playerX, int playerY, int fieldHeight);
	bool	isSwarmLost();
	void	drawSwarm();
	void	moveMobBullet();
	int		getSize() const;
	int		getSpawnSpeed() const;
	int		getMobSpeed() const;
};


#endif

