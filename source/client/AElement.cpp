#include "AElement.hpp"



AElement::AElement(void)
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
