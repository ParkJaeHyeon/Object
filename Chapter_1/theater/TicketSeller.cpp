#include "TicketSeller.h"

TicketSeller::TicketSeller(TicketOffice& ticketOffice)
	: _ticketOffice(ticketOffice)
{
}

TicketSeller::~TicketSeller()
{
}


TicketOffice
TicketSeller::getTicketOffice()
{
	return _ticketOffice;
}