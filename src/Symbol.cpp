#include "Symbol.hpp"


Symbol::Symbol(): view(' '), x(0), y(0)
{
}

Symbol::Symbol(char p_view): view(p_view), x(0), y(0)
{
}

Symbol::Symbol(char p_view, int p_x, int p_y): view(p_view), x(p_x), y(p_y)
{
}

Symbol::~Symbol()
{
}

void	Symbol::updXpos(int p_x)
{
	x += p_x;
}
void	Symbol::updYpos(int p_y)
{
	y += p_y;
}

void 	Symbol::setView(char newView) {
	view = newView;
}

void	Symbol::show_symb()
{
	move(y, x);
	addch(view);
}





int		Symbol::getXpos(void) const { return (x); }
int		Symbol::getYpos(void) const { return (y); }
char	Symbol::getView(void) const { return (view ); }
void	Symbol::setXpos(int p_x) { x = p_x; }
void	Symbol::setYpos(int p_y) { y = p_y; }
