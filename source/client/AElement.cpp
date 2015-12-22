#include "AElement.hpp"



AElement::AElement(int id, const std::string &name) :
	m_id(id), m_name(name)
{
}


AElement::~AElement(void)
{
}

void AElement::setId(int id)
{
	this->m_id = id;
}

int AElement::getId(void) const
{
	return (this->m_id);
}

const std::string &AElement::getName(void) const
{
	return (this->m_name);
}