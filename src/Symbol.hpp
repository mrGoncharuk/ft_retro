#ifndef SYMBOL_HPP
# define SYMBOL_HPP

#include <curses.h>
unsigned long long	get_curr_time( void );

class Symbol
{
protected:
	char	view;
	int		x;
	int		y;
	int		speed;
	unsigned long long		lastUpdateTime;
public:
	Symbol();
	Symbol(char p_view, int p_x, int p_y, int p_speed);
	Symbol(char p_view, int p_x, int p_y);
	Symbol(char p_view);
	~Symbol();
	Symbol(const Symbol & src);
	Symbol & operator=(Symbol const & rhs);
	void	show_symb();
	bool	isReadyForUpdate();
	int		getXpos(void) const;
	int		getYpos(void) const;
	int		getSpeed(void) const;
	char	getView(void) const;	

	void	setXpos(int p_x);
	void	setYpos(int p_y);
	void	setSpeed(int p_speed);
	void	setView(char newView);

	void	updXpos(int p_x);
	void	updYpos(int p_y);


};

#endif