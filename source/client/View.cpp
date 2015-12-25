//
// View.cpp for View in /home/bury_a/rendu/rtype
// 
// Made by Anthony Bury
// Login   <anthony.bury@epitech.eu>
// 
// Started on  Tue Nov 17 12:26:59 2015 Anthony Bury
// Last update Fri Dec 25 02:21:45 2015 Anthony Bury
//

#include "View.hpp"

View::View(void) :
  video(800, 600)
{
	this->m_mutex = new Mutex;
}

View::~View(void)
{
}

void	View::handleEvent(void)
{
	 while (this->pollEvent(this->event))
	 	{
	 		if (this->event.type == sf::Event::Closed)
	 			this->close();
	 		if ((this->event.type == sf::Event::KeyPressed) && (this->event.key.code == sf::Keyboard::Escape))
	 			this->close();
	 		//sf::Vector2i localPosition = sf::Mouse::getPosition(*this);
	 		//this->m_control.update(this->event, this->m_model, sf::Vector2f(localPosition.x, localPosition.y));
	 	}
}

bool View::init(void)
{
	AThread *thread = new Thread;
	Network *net = new Network(this->m_model);

  this->create(this->video, "R-Type", sf::Style::Titlebar | sf::Style::Close);
	net->setMutex(this->m_mutex);
	net->setThread(thread);
	if (!thread->create(&threadNetwork, reinterpret_cast<void *>(net)))
	{
		delete (net);
		this->close();
		return (false);
	}
  return (true);
}

void View::aff(void)
{
	std::vector<AElement *> tmp = this->m_model.getElements();

	for (size_t i = 0; i < tmp.size(); i++)
		tmp[i]->aff(this);
}

void View::loop(void)
{
	while (this->isOpen())
		{
			this->clear();
			this->handleEvent();
			this->aff();
			this->display();
			this->m_mutex->lock();
			if (this->m_model.getEnd())
				this->close();
			this->m_mutex->unlock();
    }
	this->m_model.setEnd(true);
}

void *threadNetwork(void *data)
{
	AThread *thread;

	reinterpret_cast<Network *>(data)->loop();
	thread = reinterpret_cast<Network *>(data)->getThread();
	delete (reinterpret_cast<Network *>(data));
	thread->exit(0);
	return (NULL);
}
