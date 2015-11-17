//
// Graph.cpp for Graph in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Tue Nov 17 13:03:46 2015 Anthony Bury
//

#include "Graph.hpp"

Graph::Graph(void) :
  video(800, 600)
{
}

Graph::~Graph(void)
{

}

bool Graph::init(void)
{
  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
  return (true);
}
