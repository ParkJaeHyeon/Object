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
Bag::getAmount()
{
	return _amount;
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