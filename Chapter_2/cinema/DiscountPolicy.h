#pragma once

#include <list>
#include "Money.h"
//#include "Movie.h"

class Screening;

// 추상클래스
typedef class IDiscountCondition
{
public:
	virtual bool isSatisfiedBy(Screening& screening) = 0;
	virtual ~IDiscountCondition() {};
} IDiscountCondition, *pIDiscountCondition;


typedef class DiscountPolicy
{
public:
	DiscountPolicy(std::list<pIDiscountCondition>& conditions);
	virtual ~DiscountPolicy();

protected:
	std::list<pIDiscountCondition> _conditions;

public:
	Money calculateDiscountAmount(Screening& screening);

protected:
	virtual Money getDiscountAmount(Screening& screening) = 0;
} DiscountPolicy, *pDiscountPolicy;


typedef class SequenceCondition : public IDiscountCondition
{
public:
	SequenceCondition(int sequence);
	virtual ~SequenceCondition();

private:
	int _sequence;
public:
	virtual bool isSatisfiedBy(Screening& screening);
} SequenceCondition, *pSeqeunceCondition;


enum DayOfWeek
{
	Sunday=0,
	Monday=1,
	Tuesday=2,
	Wednesday=3,
	Thursday=4,
	Friday=5,
	Saturday=6
};

typedef class PeriodCondition : public IDiscountCondition
{
public:
	PeriodCondition(DayOfWeek dayOfWeek, time_t startTime, time_t endTime);
	virtual ~PeriodCondition();

private:
	DayOfWeek _dayOfWeek;
	time_t _startTime;
	time_t _endTime;

public:
	virtual bool isSatisfiedBy(Screening& screening);
} PeriodCondition, *pPeriodCondition;


typedef class AmountDiscountPolicy : public DiscountPolicy
{
public:
	AmountDiscountPolicy(Money discountAmount, std::list<pIDiscountCondition> conditions);
	virtual ~AmountDiscountPolicy();

private:
	Money _discountAmount;

protected:
	virtual Money getDiscountAmount(Screening& screening);
} AmountDiscountPolicy, *pAmountDiscountPolicy;


typedef class PercentDiscountPolicy : public DiscountPolicy
{
public:
	PercentDiscountPolicy(double percent, std::list<pIDiscountCondition> conditions);
	virtual ~PercentDiscountPolicy();

private:
	double _percent;

protected:
	virtual Money getDiscountAmount(Screening& screening);
} PercentDiscountPolicy, *pPercentDiscountPolicy;