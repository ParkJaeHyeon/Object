#include "stdafx.h"
#include "Movie.h"

int main()
{
	Movie avatar(L"�ƹ�Ÿ", std::chrono::seconds(120), Money(10000));
	printf("�ƹ�Ÿ ������ ����: %llu", avatar.getFee().fee());
	return 0;
}