#include <sstream>
#include "Player.hpp"
#include "Network.hpp"

Player::Player(Model &model, Network &net) :
	m_model(model), m_net(net)
{
}


Player::~Player()
{
}

void Player::sprites(IUDP_protocol & iudp_protocol, std::list<IUDP_protocol::Sprite*> const & sprites)
{
	AElement *elem;

	for (auto sprite : sprites)
	{
		if ((elem = this->m_model.getElementByUniqueID(sprite->id)) == NULL)
		{
			elem = new Sprite(sprite->x, sprite->y, "", "", 1, 1);
			elem->setUnique(sprite->id);
			this->m_model.addElement(new Sprite(sprite->x, sprite->y, "", "", 1, 1));
		}
		else
		{
			elem->setPos(static_cast<float>(sprite->x), static_cast<float>(sprite->y));
			if (!this->m_model.isElementInState(elem, Model::GAME))
				this->m_model.addElement(elem);
		}
	}
}

void Player::sounds(IUDP_protocol & iudp_protocol, std::list<IUDP_protocol::Sound*> const & sounds)
{
}

void Player::input(IUDP_protocol & iudp_protocol, std::string const & login, IUDP_protocol::Input const & input)
{
}

void Player::sprites(IUDP_protocol & iudp_protocol, std::list<IUDP_protocol::Sprite*> const & sprites, IUDP_server::u_sockaddr const & sockaddr, socklen_t len)
{
}

void Player::sounds(IUDP_protocol & iudp_protocol, std::list<IUDP_protocol::Sound*> const & sounds, IUDP_server::u_sockaddr const & sockaddr, socklen_t len)
{
}

void Player::input(IUDP_protocol & iudp_protocol, std::string const & login, IUDP_protocol::Input const & input, IUDP_server::u_sockaddr const & sockaddr, socklen_t len)
{
}
