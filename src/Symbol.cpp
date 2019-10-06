#include "Symbol.hpp"


Symbol::Symbol(): view(' '), x(0), y(0), lastUpdateTime(get_curr_time()), speed(1000)
{
}

Symbol::Symbol(char p_view): view(p_view), x(0), y(0), lastUpdateTime(get_curr_time()), speed(1000)
{
}

Symbol::Symbol(char p_view, int p_x, int p_y): view(p_view), x(p_x), y(p_y), lastUpdateTime(get_curr_time()), speed(1000)
{
}

Symbol::Symbol(char p_view, int p_x, int p_y, int p_speed): view(p_view), x(p_x), y(p_y), lastUpdateTime(get_curr_time()), speed(p_speed)
{
}

Symbol::~Symbol()
{
}

Symbol::Symbol(const Symbol & src)
{
	(*this) = src;
}
Symbol & Symbol::operator=(Symbol const & rhs)
{
	this->x = rhs.getXpos();
	this->y = rhs.getXpos();
	this->view = rhs.getView();
	this->speed = rhs.getSpeed();
	return (*this);
}


void	Symbol::updXpos(int p_x)
{
	x += p_x;
}
void	Symbol::updYpos(int p_y)
{
	y += p_y;
}



void	Symbol::show_symb()
{
	move(y, x);
	addch(view);
}

bool	Symbol::isReadyForUpdate()
{
	if ((get_curr_time() - lastUpdateTime) >= speed)
	{
		lastUpdateTime = get_curr_time();
		return (true);
	}
	return (false);
}

bool Symbol::operator== (Symbol &rhs)
{
	if (this->x == rhs.getXpos() && this->y == rhs.getYpos())
		return (true);
	return (false);
}


int		Symbol::getXpos(void) const { return (x); }
int		Symbol::getYpos(void) const { return (y); }
char	Symbol::getView(void) const { return (view ); }
int		Symbol::getSpeed(void) const { return (speed); }

void	Symbol::setXpos(int p_x) { x = p_x; }
void	Symbol::setYpos(int p_y) { y = p_y; }
void 	Symbol::setView(char newView) {	view = newView; }
void	Symbol::setSpeed(int p_speed) { speed = p_speed; }
