#include "stdafx.h"
#include "Movie.h"

int main()
{
	time_t see_movie_time;
	struct tm t = { 0 };
	localtime_s(&t, &see_movie_time);

	//
	// �ƹ�Ÿ ��ȭ ���� ����
	// ��ȭ ���� (2, 10) �� ��� 800��(����) ����
	std::list<pIDiscountCondition> avata_condition;
	SequenceCondition Se_A(2);
	SequenceCondition Se_B(10);
	avata_condition.push_back(&Se_A);
	avata_condition.push_back(&Se_B);

	AmountDiscountPolicy avata_policy(Money(800), avata_condition);

	Movie avatar(L"�ƹ�Ÿ",
				 std::chrono::seconds(120),
				 Money(10000),
				 &avata_policy);
	printf("�ƹ�Ÿ ������ ����: %llu��\n\n", avatar.getFee().fee());

	// ���� x
	Screening no_discount_avatar(avatar, 1, see_movie_time);
	Customer customer_1;
	Reservation reservation_1 = no_discount_avatar.reserve(customer_1, 2);
	printf("Customer_1 ���� ����: %llu��\n", reservation_1.getFee().fee());


	// ���� o
	Screening discount_avatar(avatar, 2, see_movie_time);
	Customer customer_2;
	Reservation reservation_2 = discount_avatar.reserve(customer_2, 4);
	printf("Customer_2 ���� ����: %llu��\n\n", reservation_2.getFee().fee());

	//
	// Ÿ��Ÿ�� ��ȭ ���� ����
	// ��ȭ ���� (5, 7) �� ���
	std::list<pIDiscountCondition> titanic_condition;
	SequenceCondition Se_C(5);
	SequenceCondition Se_D(7);
	titanic_condition.push_back(&Se_C);
	titanic_condition.push_back(&Se_D);

	PercentDiscountPolicy titanic_policy(0.1, titanic_condition);

	Movie titanic(L"Ÿ��Ÿ��",
				  std::chrono::seconds(150),
				  Money(12000),
				  &titanic_policy);
	printf("Ÿ��Ÿ�� ������ ����: %llu��\n\n", titanic.getFee().fee());

	// ���� x
	Screening no_discount_titanic(titanic, 3, see_movie_time);
	Customer customer_3;
	Reservation reservation_3 = no_discount_titanic.reserve(customer_3, 1);
	printf("Customer_3 ���� ����: %llu��\n", reservation_3.getFee().fee());

	// ���� o
	Screening discount_titanic(titanic, 7, see_movie_time);
	Customer customer_4;
	Reservation reservation_4 = discount_titanic.reserve(customer_4, 3);
	printf("Customer_4 ���� ����: %llu��\n\n", reservation_4.getFee().fee());


	//
	// ��Ÿ���� ��ȭ ���� ����
	// ��Ÿ����� ������ ����.
	
	NoneDiscountPolicy starwars_policy;

	Movie starwars(L"��Ÿ����",
				   std::chrono::seconds(90),
				   Money(9000),
				   &starwars_policy);
	printf("��Ÿ���� ������ ����: %llu��\n\n", starwars.getFee().fee());

	Screening starwars_screening(starwars, 4, see_movie_time);
	Customer customer_5;
	Reservation reservation_5 = starwars_screening.reserve(customer_5, 4);
	printf("Customer_5 ���� ����: %llu��\n\n", reservation_5.getFee().fee());

	return 0;
}