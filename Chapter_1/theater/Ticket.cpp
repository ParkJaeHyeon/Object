#include "Ticket.h"

Ticket::Ticket(long fee)
	:_fee(fee)
{
}

Ticket::~Ticket()
{
}

long 
Ticket::getFee()
{
	return _fee;
}
