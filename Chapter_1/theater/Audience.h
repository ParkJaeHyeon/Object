#pragma once

#include "Bag.h"

typedef class Audience
{
public:
	Audience(Bag& bag);
	virtual ~Audience();

private:
	Bag _bag;

public:
	Bag getBag();

} *pAudience;

