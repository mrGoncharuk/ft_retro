#include "Enemy.hpp"

Enemy::Enemy() {

}


Enemy::Enemy(char view, int maxWidth) {
    setView(view);
    setYpos(2);
    putEnemy(maxWidth);
}

Enemy::~Enemy()
{
}

Enemy::Enemy(const Enemy & src) {
    *this = src;
    return ;
}

Enemy &Enemy::operator=( Enemy const & rhs) {
    setView(rhs.getView());
    setXpos(rhs.getXpos());
    setYpos(rhs.getYpos());

	return *this;
}

void Enemy::putEnemy(int maxWidth) {
    int tmpx;
    
    while (true) {
        tmpx = (rand() % maxWidth) + 1;
        if (tmpx >= maxWidth - 2)
            continue;
        else
            break;
    }
    x = tmpx;
}

