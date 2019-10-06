#pragma once

#include <curses.h>
unsigned long long	get_curr_time( void );

class Symbol
{
protected:
	char	view;
	int		x;
	int		y;
public:
	Symbol();
	Symbol(char p_view, int p_x, int p_y);
	Symbol(char p_view);
	~Symbol();

	void	show_symb();

	int		getXpos(void) const;
	int		getYpos(void) const;
	void	setXpos(int p_x);
	void	setYpos(int p_y);
	void	setView(char newView);
	void	updXpos(int p_x);
	void	updYpos(int p_y);
	char	getView(void) const;	

};

