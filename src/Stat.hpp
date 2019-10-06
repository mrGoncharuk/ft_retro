#pragma once
#include <ncurses.h>

class Stat {
    public:
        Stat(void);
        ~Stat(void);
        Stat(const Stat & src);
	    // Stat &operator=(Stat const & rhs);
        
        void setLvl(unsigned int lvl);
        void setTime(unsigned int time);
        void setScore(unsigned int score);
        void setHP(unsigned int hp);
        
        void lvlUpgrade( void );
        void loseHP( void );
        
        void printInfo( int fieldWidth, int fieldHeight );

        unsigned int getLvl(void);
        unsigned int getTime(void);
        unsigned int getScore(void);
        unsigned int getHP(void);
    
    private:
        unsigned int _lvl;
        unsigned int _time;
        unsigned int _score;
        unsigned int _hp;

};
