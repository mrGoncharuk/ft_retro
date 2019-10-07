#include "Game.hpp"

Game::Game(): player('T', 40, 27), fieldHeight(40), fieldWidth(50), flagRunning(true), flagShoot(false), flagLeft(false), flagRight(false), flagEndStatus(true), flagNewLevel(false)
{
	initscr();
	nodelay(stdscr,true);                   //if there wasn't any key pressed don't wait for keypress
	keypad(stdscr,true);                    //init the keyboard
	noecho();                                                                       //don't write
	curs_set(0);                                                    //cursor invisible
	resizeterm(fieldHeight, fieldWidth);
	screenHeight = fieldHeight - 10;
	enemies = new Swarm(5, fieldWidth - 3, 2000, 400);
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
	enemies->spawnMob();
	enemies->moveSwarm();
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
	if (enemies->isMobDied(bullets, player.getMaxBullets()))
	{
		stat.updateScore(100);
	}
	if (enemies->isPlayerKilled(player.getXpos(), player.getYpos(), screenHeight))
	{
		if (stat.getHP() == 0) {
			flagRunning = false;
		}
		else 
		{
			stat.loseHP();
			player.setHP(stat.getHP());
		}
	}
	if (enemies->isSwarmLost())
	{
		stat.lvlUpgrade();
		flagNewLevel = true;
	}
}



void	Game::render()
{
	erase();
	player.show_player();
	player.show_bullets();
	enemies->drawSwarm();
	box(stdscr, 0, 0);

	stat.printInfo(fieldWidth, fieldHeight);

	refresh();
}


void	Game::mainloop()
{
	while (flagRunning)
	{
		events();
		update();
		render();
		if (flagNewLevel && !flagRunning)
		{
			nodelay(stdscr,false);
			flagNewLevel = false;
			int prev_enem = enemies->getSize();
			int prev_spawn_speed = enemies->getSpawnSpeed();
			int prev_speed = enemies->getMobSpeed();
			delete enemies;
			enemies = new Swarm(prev_enem + 3, fieldWidth - 3, prev_spawn_speed - 100, prev_speed - 20);
			move(fieldHeight / 2 - 4, 5);
			printw("Congratulations!!! LEVEL UP!!!");
			this->player.setHP(this->player.getHP() + 1);
			stat.setHP(player.getHP());
			getch();
			nodelay(stdscr,true);
		}
	}
	nodelay(stdscr,false); 

	move(fieldHeight / 2 - 4, 5);
	printw("End of game!!! Your score = %d", stat.getScore());
	usleep(5000);
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