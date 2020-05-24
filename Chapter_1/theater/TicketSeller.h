#pragma once

#include "TicketOffice.h"
#include "Audience.h"

typedef class TicketSeller
{
public:
	TicketSeller(TicketOffice& ticektOffice);
	virtual ~TicketSeller();

private:
	TicketOffice _ticketOffice;


public:
//	refac
//	TicketOffice& getTicketOffice();
	void sellTo(Audience& audience);

public:
	long get_amount();
	size_t get_ticket_count();

} *pTicketSeller;

