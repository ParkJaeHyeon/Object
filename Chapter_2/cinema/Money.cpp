#include "stdafx.h"
#include "Money.h"

Money::Money(uint64_t amount)
	: _amount(amount)
{
}

Money::~Money()
{
}

Money
Money::wons(long amount)
{
	return Money((uint64_t)amount);
}

Money
Money::wons(double amount)
{
	return Money((uint64_t)amount);
}

Money
Money::plus(Money amount)
{
	return Money(_amount + amount._amount);
}

Money
Money::minus(Money amount)
{
	return Money(_amount - amount._amount);
}

Money
Money::times(double percent)
{
	return Money((uint64_t)(_amount * percent));
}

bool
Money::isLessThen(Money other)
{
	return _amount < other._amount ? true : false;
}

bool
Money::isGreaterThanOrEqual(Money other)
{
	return _amount >= other._amount ? true : false;
}