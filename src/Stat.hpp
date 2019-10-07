#ifndef STAT_HPP
# define STAT_HPP


#include <ncurses.h>

class Stat {
    public:
        Stat(void);
        ~Stat(void);
        Stat(const Stat & src);
        Stat &operator=(Stat const & rhs);
        
        void setLvl(unsigned int lvl);
        void setTime(unsigned int time);
        void setScore(unsigned int score);
        void setHP(unsigned int hp);
        
        void lvlUpgrade( void );
        void loseHP( void );
        void updateTime(unsigned int currentTimestamp);

        void printInfo( int fieldWidth, int fieldHeight );
        void updateScore(unsigned int score);

        unsigned int getLvl(void) const;
        unsigned int getTime(void) const;
        unsigned int getScore(void) const;
        unsigned int getHP(void) const;
    
    private:
        unsigned int _lvl;
        unsigned long long _time;
        unsigned int _score;
        unsigned int _hp;
        unsigned int _timestamp;


};

#endif
