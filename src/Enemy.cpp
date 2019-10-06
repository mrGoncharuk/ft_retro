#include "Enemy.hpp"

Enemy::Enemy() {

}


Enemy::Enemy(char view, int maxWidth, int speed): Symbol(view, 5, 1, speed)  {
}

Enemy::~Enemy()
{
}

Enemy::Enemy(const Enemy & src) {
    *this = src;
    return ;
}

Enemy &Enemy::operator=( Enemy const & rhs) {
    this->view = rhs.getView();
    this->x = rhs.getXpos();
    this->y = rhs.getYpos();
    this->speed = speed;
	return *this;
}

int     Enemy::getRandPosition(int maxWidth)
{
    int tmpx;
    
    while (true) {
        tmpx = (rand() % maxWidth) + 1;
        if (tmpx >= maxWidth - 2)
            continue;
        else
            break;
    }
    return (tmpx);
}

