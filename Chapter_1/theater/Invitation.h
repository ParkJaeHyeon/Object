#pragma once

typedef class Invitation
{
public:
	Invitation(long long  when);
	virtual ~Invitation();
	
private:
	long long _when;
} *pInvitation;