//
// Game.cpp for Game in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:21:06 2015 Anthony Bury
// Last update Tue Nov 17 13:17:47 2015 Anthony Bury
//

#include "Game.hpp"

Game::Game(void)
{
  this->win = new Graph();
}

Game::~Game(void)
{

}

bool Game::init(void)
{
  if (!this->win->init())
    return (false);
  return (true);
}

void Game::checkEvent(void)
{
  if (this->event.type == sf::Event::Closed)
    this->win->close();
  if (this->event.type == sf::Event::KeyPressed)
    if (this->event.key.code == sf::Keyboard::Escape)
      this->win->close();
}

void Game::loop(void)
{
  while (this->win->isOpen())
    {
      while (this->win->pollEvent(this->event))
	  this->checkEvent();
      this->win->clear();
      this->win->display();
    }
}
