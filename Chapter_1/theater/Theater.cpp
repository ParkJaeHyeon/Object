#include "Theater.h"

Theater::Theater(TicketSeller& ticketseller)
	: _ticketseller(ticketseller)
{
}

Theater::~Theater()
{

}

void
Theater::enter(Audience& audience)
{
	//	refac
	//if (audience.getBag().hasInvitation())
	//{
	//	Ticket ticket = _ticketseller.getTicketOffice().getTicket();
	//	audience.getBag().setTicket(ticket);
	//}
	//else
	//{
	//	Ticket ticket = _ticketseller.getTicketOffice().getTicket();
	//	audience.getBag().minusAmount(ticket.getFee());
	//	_ticketseller.getTicketOffice().plusAmount(ticket.getFee());
	//	audience.getBag().setTicket(ticket);
	//}
	_ticketseller.sellTo(audience);
}

long
Theater::get_amount()
{
	//	refac
	//return _ticketseller.getTicketOffice().get_amount();

	return _ticketseller.get_amount();
}

size_t
Theater::get_ticket_count()
{
	//	refac
	//return _ticketseller.getTicketOffice().get_ticket_count();

	return _ticketseller.get_ticket_count();
}