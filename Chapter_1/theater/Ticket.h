#pragma once

typedef class Ticket
{
public:
	Ticket(long fee);
	virtual ~Ticket();

private:
	long _fee;

public:
	long getFee();
} *pTicket;

