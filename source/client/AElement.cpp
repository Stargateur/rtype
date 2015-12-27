#include "AElement.hpp"



AElement::AElement(int id, const std::string &name, const bool &canFocus) :
	m_id(id), m_name(name), m_canFocus(canFocus), m_isFocus(false)
{
}


AElement::~AElement(void)
{
}

void AElement::setId(int id)
{
	this->m_id = id;
}

void AElement::setFocus(const bool &focus)
{
	this->m_isFocus = this->m_canFocus && focus;
}

int AElement::getId(void) const
{
	return (this->m_id);
}

bool AElement::isFocus(void) const
{
	return (this->m_canFocus && this->m_isFocus);
}

const std::string &AElement::getName(void) const
{
	return (this->m_name);
}
