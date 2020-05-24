#pragma once

#include "Invitation.h"
#include "Ticket.h"

typedef class Bag
{
public:
	Bag(long amount);
	Bag(Invitation& invitation, long amount);
	virtual ~Bag();

private:
	long _amount;
	pInvitation _invitation;
	pTicket _ticket;

public:
	bool hasInvitation();
	bool hasTicket();

	// 관객의 금액 체크를 위한 함수
	long get_amount();

public:
	long hold(Ticket ticket);
//	refac
//public:
//	void setTicket(Ticket& ticket);
//	void minusAmount(long amount);
//	void plusAmount(long amount);

private:
	void setTicket(Ticket& ticket);
	void minusAmount(long amount);
	void plusAmount(long amount);
} *pBag;

