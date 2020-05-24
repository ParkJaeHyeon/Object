#include "Audience.h"

Audience::Audience(Bag& bag)
	: _bag(bag)
{
}

Audience::~Audience()
{
}

Bag&
Audience::getBag()
{
	return _bag;
}