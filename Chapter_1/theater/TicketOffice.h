#pragma once

#include <list>
#include "Ticket.h"

typedef class TicketOffice
{
public:
	TicketOffice(long amount,
				 std::list<Ticket>& ticket);

	virtual ~TicketOffice();

private:
	long _amount;
	std::list<Ticket> _tickets;

public:
	Ticket& getTicket();
	void minusAmount(long amount);
	void plusAmount(long amount);

} *pTicketOffice;

