#include "Bag.h"
#include <stdio.h>

Bag::Bag(long amount)
	: _amount(amount)
{
	_invitation = nullptr;
	_ticket = nullptr;
}

Bag::Bag(Invitation& invitation, long amount)
	  : _amount(amount)
{
	_invitation = &invitation;
	_ticket = nullptr;
}

Bag::~Bag()
{
}

bool 
Bag::hasInvitation()
{
	return nullptr == _invitation ? false : true;
}

bool
Bag::hasTicket()
{
	return nullptr == _ticket ? false : true;
}

long 
Bag::get_amount()
{
	return _amount;
}

long
Bag::hold(Ticket ticket)
{
	if (hasInvitation())
	{
		setTicket(ticket);
		return 0L;
	}
	else
	{
		setTicket(ticket);
		minusAmount(ticket.getFee());
		return ticket.getFee();
	}
}

void
Bag::setTicket(Ticket& ticket)
{
	_ticket = &ticket;
}

void
Bag::minusAmount(long amount)
{
	_amount -= amount;
}

void
Bag::plusAmount(long amount)
{
	_amount += amount;
}