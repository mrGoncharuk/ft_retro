#ifndef GAME_HPP
# define GAME_HPP

# include <ncurses.h>
# include "Symbol.hpp"
# include "Player.hpp"
# include "Bullet.hpp"
# include "Enemy.hpp"
# include "Swarm.hpp"
# define ESC_KEY 27
# define SPACE_KEY 32

class Game
{
private:
	Player	player;
	Swarm	enemies;
	int		fieldWidth;
	int		fieldHeight;
	int		screenHeight;
	bool	flagRunning;
	bool	flagEndStatus;
	bool	flagLeft;
	bool	flagRight;
	bool	flagShoot;
public:
    Game(/* args */);

    ~Game();
	void	mainloop();
	void	events();
	void	update();
	void	render();

	void	mv_left(Symbol &p_symb);
	void	mv_right(Symbol &p_symb);
	void	mv_up(Symbol &p_symb);
	void	mv_down(Symbol &p_symb);

};

#endif
