#include "Game.hpp"

Game::Game(): player('T', 40, 27), fieldHeight(40), fieldWidth(80), enemies(20, 77, 1500, 300), flagRunning(true), flagShoot(false), flagLeft(false), flagRight(false), flagEndStatus(true)
{
	initscr();
	nodelay(stdscr,true);                   //if there wasn't any key pressed don't wait for keypress
	keypad(stdscr,true);                    //init the keyboard
	noecho();                                                                       //don't write
	curs_set(0);                                                    //cursor invisible
	resizeterm(fieldHeight - 1, fieldWidth - 1);
	screenHeight = fieldHeight - 10;
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
	enemies.spawnMob();
	enemies.moveSwarm();
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
				if (bullets[i]->isReadyForUpdate())
					bullets[i]->fly();
		}
	enemies.isMobDied(bullets, player.getMaxBullets());
	if (enemies.isPlayerKilled(player.getXpos(), player.getYpos(), screenHeight))
	{
		flagEndStatus = false;
		flagRunning = false;
	}
	if (enemies.isSwarmLost())
	{
		flagEndStatus = true;
		flagRunning = false;
	}
}



void	Game::render()
{
	erase();
	player.show_player();
	player.show_bullets();
	enemies.drawSwarm();
	box(stdscr, 0, 0);
	for (int i = 1; i < fieldWidth - 2; i++)
	{
		move(fieldHeight - 10, i);
		addch('#');
	}
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
	nodelay(stdscr,false); 
	if (flagEndStatus == true)
	{
		move(fieldHeight / 2 - 4, fieldWidth / 2);
		printw("You win!!!");
	}
	else
	{
		move(fieldHeight / 2 - 4, fieldWidth / 2);
		printw("You lose!!!");
	}
	getch();
}

Game::~Game()
{
	endwin();
}


void	Game::mv_left(Symbol &p_symb)
{
	if (p_symb.getXpos() > 3)
		p_symb.updXpos(-1);
}

void	Game::mv_right(Symbol &p_symb)
{
	if (p_symb.getXpos() < (fieldWidth - 5))
		p_symb.updXpos(1);
}

void	Game::mv_down(Symbol &p_symb)
{
	if (p_symb.getYpos() < (screenHeight - 1))
		p_symb.updYpos(1);
}

void	Game::mv_up(Symbol &p_symb)
{
	if (p_symb.getYpos() > 1)
		p_symb.updYpos(-1);
}