#include "stdafx.h"
#include "DiscountPolicy.h"

// 구현부에서는 선언을 해도 상관이 없는것같다..
#include "Movie.h"

//
// DiscountPolicy Class
//
DiscountPolicy::DiscountPolicy(std::list<pIDiscountCondition>& conditions)
	:_conditions(conditions)
{
}

DiscountPolicy::~DiscountPolicy()
{

}

Money
DiscountPolicy::calculateDiscountAmount(Screening& screening)
{
	for(auto each : _conditions)
	{
		if(each->isSatisfiedBy(screening))
		{
			return getDiscountAmount(screening);
		}
	}

	return Money(0);
}

//
// SeqeunceCondition Class
//

SequenceCondition::SequenceCondition(int sequence)
	:_sequence(sequence)
{
	
}

SequenceCondition::~SequenceCondition()
{

}

bool
SequenceCondition::isSatisfiedBy(Screening& screening)
{
	return screening.isSequence(_sequence);
}

//
// PeriodCondition Class
//

PeriodCondition::PeriodCondition(DayOfWeek dayOfWeek, time_t startTime, time_t endTime)
	:_dayOfWeek(dayOfWeek), _startTime(startTime), _endTime(endTime)
{

}

PeriodCondition::~PeriodCondition()
{

}

bool
PeriodCondition::isSatisfiedBy(Screening& screening)
{
	time_t time = screening.getStartTime();
	struct tm t = {0};
	localtime_s(&t, &time);

	if (t.tm_wday == _dayOfWeek &&
		_startTime <= screening.getStartTime() &&
		_endTime >= screening.getStartTime())
	{
		return true;
	}

	return false;
}


//
// AmountDiscountPolicy
//

AmountDiscountPolicy::AmountDiscountPolicy(Money discountAmount, std::list<pIDiscountCondition> conditions)
	:_discountAmount(discountAmount), DiscountPolicy(conditions)
{
	
}

AmountDiscountPolicy::~AmountDiscountPolicy()
{

}

Money
AmountDiscountPolicy::getDiscountAmount(Screening& screening)
{
	return _discountAmount;
}

//
// PercentDiscountPolicy
//

PercentDiscountPolicy::PercentDiscountPolicy(double percent, std::list<pIDiscountCondition> conditions)
	: _percent(percent), DiscountPolicy(conditions)
{

}

PercentDiscountPolicy::~PercentDiscountPolicy()
{

}

Money
PercentDiscountPolicy::getDiscountAmount(Screening& screening)
{
	return screening.getMoiveFee().times(_percent);
}