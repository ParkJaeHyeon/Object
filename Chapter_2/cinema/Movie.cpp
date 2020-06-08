#include "stdafx.h"
#include "Movie.h"

//
// Movie Class
//
Movie::Movie(std::wstring title, std::chrono::seconds runningTime, Money fee, pDiscountPolicy discountPolicy)
	:_title(title), _runningTime(runningTime), _fee(fee), _discountPolicy(discountPolicy)
{

}

Movie::~Movie()
{

}

Money
Movie::getFee()
{
	return _fee;
}

Money
Movie::calculateMovieFee(Screening& screening)
{
	//
	// 할인 요금을 계산할 필요 없이 영화에 설정된 기본 금액을
	// 그대로 사용하면 되지만 할인 정책이 없는 경우 예외 케이스로
	// 지금까지의 일관성이 무너지게 된다는 것이다..
	// 기존 할인 정책의 경우에는 할인할 금액을 계산하는 책임은 DiscountPolicy의
	// 자식 클래스에 있었지만 할인 정책이 없는 경우 걸정하는 책임이 DiscountPolicy가
	// 아닌 Movie 쪽에 있기 때문에 아래의 코드가 아닌 NoneDiscountPolicy 클래스를 추가한다.
	// 
	//if (nullptr == _discountPolicy)
	//{
	//	return _fee;
	//}
	return _fee.minus(_discountPolicy->calculateDiscountAmount(screening));
}

void
Movie::changeDiscountPolicy(pDiscountPolicy discountPolicy)
{
	_discountPolicy = discountPolicy;
}

//
// Screening Class
//
Screening::Screening(Movie movie, int sequence, time_t whenScreened)
	:_movie(movie), _sequence(sequence), _whenScreened(whenScreened)
{

}

Screening::~Screening()
{

}

time_t
Screening::getStartTime()
{
	return _whenScreened;
}

bool
Screening::isSequence(int sequence)
{
	return _sequence == sequence ? true : false;
}

Money
Screening::getMoiveFee()
{
	return _movie.getFee();
}

Reservation
Screening::reserve(Customer customer, int audienceCount)
{
	return Reservation(customer, *this, calculateFee(audienceCount), audienceCount);
}

Money
Screening::calculateFee(int audienceCount)
{
	return _movie.calculateMovieFee(*this).times(audienceCount);
}

//
// Reservation Class
//
Reservation::Reservation(Customer customer, Screening& screening, Money fee, int audienceCount)
	:_customer(customer), _screening(screening), _fee(fee), audienceCount(audienceCount)
{

}

Reservation::~Reservation()
{

}

Money
Reservation::getFee()
{
	return Money(_fee);
}