#include "stdafx.h"
#include "Movie.h"

int main()
{
	time_t see_movie_time;
	struct tm t = { 0 };
	localtime_s(&t, &see_movie_time);

	//
	// 아바타 영화 할인 조건
	// 영화 순번 (2, 10) 일 경우 800원(가격) 할인
	std::list<pIDiscountCondition> avata_condition;
	SequenceCondition Se_A(2);
	SequenceCondition Se_B(10);
	avata_condition.push_back(&Se_A);
	avata_condition.push_back(&Se_B);

	AmountDiscountPolicy avata_policy(Money(800), avata_condition);

	Movie avatar(L"아바타",
				 std::chrono::seconds(120),
				 Money(10000),
				 &avata_policy);
	printf("아바타 영상의 가격: %llu원\n\n", avatar.getFee().fee());

	// 할인 x
	Screening no_discount_avatar(avatar, 1, see_movie_time);
	Customer customer_1;
	Reservation reservation_1 = no_discount_avatar.reserve(customer_1, 2);
	printf("Customer_1 예약 가격: %llu원\n", reservation_1.getFee().fee());


	// 할인 o
	Screening discount_avatar(avatar, 2, see_movie_time);
	Customer customer_2;
	Reservation reservation_2 = discount_avatar.reserve(customer_2, 4);
	printf("Customer_2 예약 가격: %llu원\n\n", reservation_2.getFee().fee());

	//
	// 타이타닉 영화 할인 조건
	// 영화 순번 (5, 7) 일 경우
	std::list<pIDiscountCondition> titanic_condition;
	SequenceCondition Se_C(5);
	SequenceCondition Se_D(7);
	titanic_condition.push_back(&Se_C);
	titanic_condition.push_back(&Se_D);

	PercentDiscountPolicy titanic_policy(0.1, titanic_condition);

	Movie titanic(L"타이타닉",
				  std::chrono::seconds(150),
				  Money(12000),
				  &titanic_policy);
	printf("타이타닉 영상의 가격: %llu원\n\n", titanic.getFee().fee());

	// 할인 x
	Screening no_discount_titanic(titanic, 3, see_movie_time);
	Customer customer_3;
	Reservation reservation_3 = no_discount_titanic.reserve(customer_3, 1);
	printf("Customer_3 예약 가격: %llu원\n", reservation_3.getFee().fee());

	// 할인 o
	Screening discount_titanic(titanic, 7, see_movie_time);
	Customer customer_4;
	Reservation reservation_4 = discount_titanic.reserve(customer_4, 3);
	printf("Customer_4 예약 가격: %llu원\n\n", reservation_4.getFee().fee());


	//
	// 스타워즈 영화 할인 조건
	// 스타워즈는 할인이 없다.
	
	NoneDiscountPolicy starwars_policy;

	Movie starwars(L"스타워즈",
				   std::chrono::seconds(90),
				   Money(9000),
				   &starwars_policy);
	printf("스타워즈 영상의 가격: %llu원\n\n", starwars.getFee().fee());

	Screening starwars_screening(starwars, 4, see_movie_time);
	Customer customer_5;
	Reservation reservation_5 = starwars_screening.reserve(customer_5, 4);
	printf("Customer_5 예약 가격: %llu원\n\n", reservation_5.getFee().fee());

	return 0;
}