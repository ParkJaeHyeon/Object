#pragma once

#include <iostream>
#include <chrono>

#include "Money.h"
#include "Customer.h"

class Reservation;
class Screening;

typedef class Movie
{
public:
	Movie(std::wstring title, std::chrono::seconds runningTime, Money fee);

	virtual ~Movie();

private:
	std::wstring _title;
	std::chrono::seconds _runningTime;
	Money _fee;

public:
	Money getFee();
	Money calculateMovieFee(Screening& screennig);
} Moive, *pMoive;


typedef class Screening
{
public:
	Screening(Movie movie, int sequence, time_t whenScreened);
	virtual ~Screening();

private:
	Movie _movie;
	int _sequence;
	time_t _whenScreened;

public:
	time_t getStartTime();
	bool isSequence(int sequence);
	Money getMoiveFee();
	Reservation reserve(Customer customer, int audienceCount);

private:
	Money calculateFee(int audienceCount);
} Screening, *pScreening;

typedef class Reservation
{
public:
	Reservation(Customer customer, Screening& screening, Money fee, int audienceCount);

	virtual ~Reservation();
private:
	Customer _customer;
	Screening _screening;
	Money _fee;
	int audienceCount;
} Reservation, *pReservation;