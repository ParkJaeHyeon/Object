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
//	refac
//	Bag& getBag();
	
	long buy(Ticket ticket);

public:
	long get_amount();
	bool has_invitation();
	bool has_ticket();

} *pAudience;

