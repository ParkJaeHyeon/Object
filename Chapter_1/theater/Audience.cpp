#include "Audience.h"

Audience::Audience(Bag& bag)
	: _bag(bag)
{
}

Audience::~Audience()
{
}

//	refac
//Bag&
//Audience::getBag()
//{
//	return _bag;
//}

long
Audience::buy(Ticket ticket)
{
	//	refac
	//if (_bag.hasInvitation())
	//{
	//	_bag.setTicket(ticket);
	//	return 0L;
	//}
	//else
	//{
	//	_bag.setTicket(ticket);
	//	_bag.minusAmount(ticket.getFee());
	//	return ticket.getFee();
	//}
	return _bag.hold(ticket);
}

long
Audience::get_amount()
{
	return _bag.get_amount();
}

bool
Audience::has_invitation()
{
	return _bag.hasInvitation();
}

bool
Audience::has_ticket()
{
	return _bag.hasTicket();
}