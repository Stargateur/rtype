#pragma once

#include "View.hpp"

class View;

typedef enum e_id
{
	BUTTON = 1,
	TEXT = 2,
	SPRITE = 3
} ID;

class AElement
{
	int m_id;
public:
	AElement(int);
	~AElement(void);

public:
	void setId(int);
	int getId(void) const;
	virtual void update(void) = 0;
	virtual void aff(View &) = 0;
};

