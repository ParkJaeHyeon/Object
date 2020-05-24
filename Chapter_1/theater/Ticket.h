#pragma once

typedef class Ticket
{
public:
	Ticket();
	virtual ~Ticket();

private:
	long _fee;

public:
	long getFee();
} *pTicket;

