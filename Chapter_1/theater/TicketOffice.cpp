#include "TicketOffice.h"

TicketOffice::TicketOffice(
	long amount,
	std::list<Ticket>& ticket
)
	: _amount(amount),
	  _tickets(ticket)
{
}

TicketOffice::~TicketOffice()
{
}

Ticket&
TicketOffice::getTicket()
{
	Ticket ticket = _tickets.front();
	_tickets.pop_front;
	return ticket;
}

void
TicketOffice::minusAmount(long amount)
{
	_amount -= amount;
}

void
TicketOffice::plusAmount(long amount)
{
	_amount += amount;
}
