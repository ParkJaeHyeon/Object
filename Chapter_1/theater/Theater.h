#pragma once

#include "Audience.h"
#include "TicketSeller.h"

typedef class Theater
{
public:
	Theater(TicketSeller& ticketseller);
	virtual ~Theater();

private:
	TicketSeller _ticketseller;

public:
	void enter(Audience& audience);
	long get_amount();
	size_t get_ticket_count();
} *pTheater;

