#include "Player.hpp"

Player::Player(): Symbol('T', 0, 0)
{
}

Player::Player(char p_symb, int p_x, int p_y): Symbol(p_symb, p_x, p_y)
{	
}

Player::~Player()
{
}