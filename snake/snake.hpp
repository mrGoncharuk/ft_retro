#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

#ifndef SNAKE_H
#define SNAKE_H
struct snakepart{
        int x,y;
        snakepart(int col, int row);
        snakepart();
};
 
class snakeclass{
        int points,del;
        //indicates that the snake get food (it makes the snake longer)
        bool get;
        //indicates the current direction of the snake
        char direction;
 
        int maxwidth;
        int maxheight;
        char partchar;
        char oldalchar;
        char etel;
        snakepart food;
        std::vector<snakepart> snake; //represent the snake
 
        void putfood();
        bool collision();
        void movesnake();
       
public:
        snakeclass();
        ~snakeclass();
        void start();
};
 
#endif