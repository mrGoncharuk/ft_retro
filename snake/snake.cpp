#include "snake.hpp"
using namespace std;
snakepart::snakepart(int col,int row)
{
        x=col;
        y=row;
}
 
snakepart::snakepart()
{
        x=0;
        y=0;
}
snakeclass::snakeclass()
{
        initscr();
        nodelay(stdscr,true);                   //if there wasn't any key pressed don't wait for keypress
        keypad(stdscr,true);                    //init the keyboard
        noecho();                                                                       //don't write
        curs_set(0);                                                    //cursor invisible
        getmaxyx(stdscr,maxheight,maxwidth);
        partchar='x';
        oldalchar=(char)219;
        etel='*';
        food.x=0;
        food.y=0;
        for(int i=0;i<5;i++)
                snake.push_back(snakepart(40+i,10));
        points=0;
        del=110000;
        get=0;
        direction='l';
        srand(time(NULL));
        putfood();
        //make the game-board -- up-vertical
        for(int i=0;i<maxwidth-1;i++)
        {
                move(0,i);
                addch(oldalchar);
        }
        //left-horizontal
        for(int i=0;i<maxheight-1;i++)
        {
                move(i,0);
                addch(oldalchar);
        }
        //down-vertical
        for(int i=0;i<maxwidth-1;i++)
        {
                move(maxheight-2,i);
                addch(oldalchar);
        }
        //right-horizontal
        for(int i=0;i<maxheight-1;i++)
        {
                move(i,maxwidth-2);
                addch(oldalchar);
        }
        //draw the snake
        for(int i=0;i<snake.size();i++)
        {
                move(snake[i].y,snake[i].x);
                addch(partchar);
        }
        move(maxheight-1,0);
        printw("%d",points);
        move(food.y,food.x);
        addch(etel);
        refresh();
}
 
snakeclass::~snakeclass()
{
        nodelay(stdscr,false);                  //turn back
        getch();                                                                                //wait until a key is pressed
        endwin();
}
 
void snakeclass::putfood()
{
        while(1)
        {
                int tmpx=rand()%maxwidth+1;
                int tmpy=rand()%maxheight+1;
                for(int i=0;i<snake.size();i++)
                        if(snake[i].x==tmpx && snake[i].y==tmpy)
                                continue;
                if(tmpx>=maxwidth-2 || tmpy>=maxheight-3)
                        continue;
                food.x=tmpx;
                food.y=tmpy;
                break;
        }
        move(food.y,food.x);
        addch(etel);
        refresh();
}
 
bool snakeclass::collision()
{
        if(snake[0].x==0 || snake[0].x==maxwidth-1 || snake[0].y==0 || snake[0].y==maxheight-2)
                return true;
        for(int i=2;i<snake.size();i++)
        {
                if(snake[0].x==snake[i].x && snake[0].y==snake[i].y)
                        return true;
        }
        //collision with the food
        if(snake[0].x==food.x && snake[0].y==food.y)
        {
                get=true;
                putfood();
                points+=10;
                move(maxheight-1,0);
                printw("%d",points);
                if((points%100)==0)
                        del-=10000;
        }else
                get=false;
        return false;
}
 
 
void snakeclass::movesnake()
{
        //detect key
        int tmp=getch();
        switch(tmp)
        {
                case KEY_LEFT:
                        if(direction!='r')
                                direction='l';
                        break;
                case KEY_UP:
                        if(direction!='d')
                                direction='u';
                        break;
                case KEY_DOWN:
                        if(direction!='u')
                                direction='d';
                        break;
                case KEY_RIGHT:
                        if(direction!='l')
                                direction='r';
                        break;
                case KEY_BACKSPACE:
                        direction='q';
                        break;
        }
        //if there wasn't a collision with food
        if(!get)
        {
                move(snake[snake.size()-1].y,snake[snake.size()-1].x);
                printw(" ");
                refresh();
                snake.pop_back();
        }
        if(direction=='l')
        {
                snake.insert(snake.begin(),snakepart(snake[0].x-1,snake[0].y));
        }else if(direction=='r'){
                snake.insert(snake.begin(),snakepart(snake[0].x+1,snake[0].y));
 
        }else if(direction=='u'){
                snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y-1));
        }else if(direction=='d'){
                snake.insert(snake.begin(),snakepart(snake[0].x,snake[0].y+1));
        }
                move(snake[0].y,snake[0].x);
                addch(partchar);
        refresh();
}
 
void snakeclass::start()
{
        while(1)
        {
                if(collision())
                {
                        move(12,36);
                        printw("game_over");
                        break;
                }
                movesnake();
                if(direction=='q')                              //exit
                        break;
                usleep(del);                    //Linux delay
        }
}