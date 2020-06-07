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
	return _fee.minus(_discountPolicy->calculateDiscountAmount(screening));
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