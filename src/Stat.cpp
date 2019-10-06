#include "Stat.hpp"

Stat::Stat(void) : _hp(3), _lvl(1), _time(0), _score(0)  {
    return ;
}
Stat::~Stat(void) {
    return ;
}
Stat::Stat(const Stat & src) {
    *this = src;
}

void Stat::setLvl(unsigned int lvl) {
    this->_lvl = lvl;
}
void Stat::setTime(unsigned int time) {
    this->_time = time;
}
void Stat::setScore(unsigned int score) {
    this->_score = score;
}
void Stat::setHP(unsigned int hp) {
    this->_hp = hp;
}

void Stat::lvlUpgrade( void ) { this->_lvl++; }
void Stat::loseHP( void ) { this->_hp--; }

unsigned int Stat::getLvl(void) { return this->_lvl; }
unsigned int Stat::getTime(void) { return this->_time; }
unsigned int Stat::getScore(void) { return this->_score; }
unsigned int Stat::getHP(void) { return this->_hp; }

// Stat &Stat::operator=( Stat const & rhs ) {
// 	setLvl(rhs.getLvl());
//     setScore(rhs.getScore());
//     setHP(rhs.getHP());
//     setTime(rhs.getTime());
//     return *this;
// }

void Stat::printInfo( int fieldWidth, int fieldHeight) {
    for (int i = 1; i < fieldWidth - 2; i++) {
		move(fieldHeight - 10, i);
		addch('#');
	}
    move(fieldHeight - 8, 2);
    printw("| Level | Score | Time | HP |");
    move(fieldHeight - 7, 2);
    printw("-----------------------------");
    move(fieldHeight - 6, 2);
    printw("|   %d   |   %d   |  %d   |  %d |", this->_lvl, this->_score, this->_time, this->_hp);

}
