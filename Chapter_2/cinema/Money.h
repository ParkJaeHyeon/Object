#pragma once

#include <stdint.h>

class Money
{
public:
	Money(uint64_t amount);
	virtual ~Money();

private:
	uint64_t _amount;

public:
	Money wons(long amount);
	Money wons(double amount);
	Money plus(Money amount);
	Money minus(Money amount);
	Money times(double percent);
	bool isLessThen(Money other);
	bool isGreaterThanOrEqual(Money other);

public:
	uint64_t fee();
};
