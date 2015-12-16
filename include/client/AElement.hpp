#pragma once
class AElement
{
	int m_id;
public:
	AElement(void);
	~AElement(void);

public:
	void setId(int);
	int getId(void) const;
	virtual void update(void) = 0;
};

