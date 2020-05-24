#pragma once

#include "Invitation.h"
#include "Ticket.h"

typedef class Bag
{
public:
	Bag(long amount);
	Bag(Invitation& invitation, long amount);
	virtual ~Bag();

private:
	long _amount;
	pInvitation _invitation;
	pTicket _ticket;

public:
	bool hasInvitation();
	bool hasTicket();

public:
	void setTicket(Ticket& ticket);
	void minusAmount(long amount);
	void plusAmount(long amount);
} *pBag;

