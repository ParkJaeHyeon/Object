#include "TicketOffice.h"

TicketOffice::TicketOffice(
	long amount,
	std::queue<Ticket> ticket
)
	: _amount(amount),
	  _tickets(ticket)
{
}

TicketOffice::~TicketOffice()
{
}

Ticket
TicketOffice::getTicket()
{
	Ticket ticket = _tickets.front();
	_tickets.pop();
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

void
TicketOffice::sellTicketTo(Audience& audience)
{
	plusAmount(audience.buy(getTicket()));
}

size_t
TicketOffice::get_ticket_count()
{
	return _tickets.size();
}

long
TicketOffice::get_amount()
{
	return _amount;
}