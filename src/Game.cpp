#include "Game.hpp"
#include <ctime>

Game::Game(): player('T', 15, 15), flagRunning(true), flagShoot(false), flagLeft(false), flagRight(false)
{
	initscr();
	nodelay(stdscr,true);                   //if there wasn't any key pressed don't wait for keypress
	keypad(stdscr,true);                    //init the keyboard
	noecho();                                                                       //don't write
	curs_set(0);                                                    //cursor invisible
	getmaxyx(stdscr,fieldHeight, fieldWidth);
}

void	Game::events()
{
	int key = getch();

    switch(key) {
        case KEY_LEFT:
			flagLeft = true;
            break;
        case KEY_RIGHT:
			flagRight = true;
            break;
        case ESC_KEY:
			flagRunning = false;
			break;
        case SPACE_KEY:
			flagShoot = true;
			break;
    }
}

void	Game::update()
{
	if (flagLeft)
	{
		flagLeft = false;
		mv_left(player);		
	}
	if (flagRight)
	{
		flagRight = false;
		mv_right(player);
	}
	if (flagShoot)
	{
		flagShoot = false;
		player.send_bullet();
	}
	
	Bullet **bullets = player.getBullets();
	for (int i = 0; i < player.getMaxBullets(); i++)
		if (bullets[i])
		{
			if (bullets[i]->getYpos() == 0)
			{
				delete bullets[i];
				bullets[i] = NULL;
			}
			else
				bullets[i]->fly();
		}
}

void	Game::render()
{
	erase();
	player.show_symb();
	player.show_bullets();
	refresh();
}

void	Game::mainloop()
{
	while (flagRunning)
	{
		events();
		update();
		render();
	}
}

Game::~Game()
{
	endwin();
}


void	Game::mv_left(Symbol &p_symb)
{
	if (p_symb.getXpos() > 0)
		p_symb.updXpos(-1);
}

void	Game::mv_right(Symbol &p_symb)
{
	if (p_symb.getXpos() < fieldWidth)
		p_symb.updXpos(1);
}

void	Game::mv_down(Symbol &p_symb)
{
	if (p_symb.getYpos() > fieldHeight)
		p_symb.updYpos(1);
}

void	Game::mv_up(Symbol &p_symb)
{
	if (p_symb.getYpos() > 0)
		p_symb.updYpos(-1);
}