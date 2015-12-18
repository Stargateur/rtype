#include "AElement.hpp"



AElement::AElement(int id) :
	m_id(id)
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
