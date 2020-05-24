#pragma once

#include "Ticket.h"
#include "Audience.h"
#include <queue>

typedef class TicketOffice
{
public:
	TicketOffice(long amount,
				 std::queue<Ticket> ticket);

	virtual ~TicketOffice();

private:
	long _amount;
	std::queue<Ticket> _tickets;

//	refac
//public:
//	Ticket getTicket();
//	void minusAmount(long amount);
//	void plusAmount(long amount);

private:
	Ticket getTicket();
	void minusAmount(long amount);
	void plusAmount(long amount);
	
public:
	void sellTicketTo(Audience& audience);

public:
	size_t get_ticket_count();
	long get_amount();
} *pTicketOffice;

