#include "TicketSeller.h"

TicketSeller::TicketSeller(TicketOffice& ticketOffice)
	: _ticketOffice(ticketOffice)
{
}

TicketSeller::~TicketSeller()
{
}


//	refac
//TicketOffice&
//TicketSeller::getTicketOffice()
//{
//	return _ticketOffice;
//}

void
TicketSeller::sellTo(Audience& audience)
{
	//	refac
	//if (audience.getBag().hasInvitation())
	//{
	//	Ticket ticket = _ticketOffice.getTicket();
	//	audience.getBag().setTicket(ticket);
	//}
	//else
	//{
	//	Ticket ticket = _ticketOffice.getTicket();
	//	audience.getBag().minusAmount(ticket.getFee);
	//	audience.getBag().setTicket(ticket);
	//}
	
	//	refac
	//_ticketOffice.plusAmount(audience.buy(_ticketOffice.getTicket()));
	_ticketOffice.sellTicketTo(audience);
}

long 
TicketSeller::get_amount()
{
	return _ticketOffice.get_amount();
}

size_t
TicketSeller::get_ticket_count()
{
	return _ticketOffice.get_ticket_count();
}