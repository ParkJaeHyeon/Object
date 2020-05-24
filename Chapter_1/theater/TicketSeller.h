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
	TicketOffice getTicketOffice();

} *pTicketSeller;

