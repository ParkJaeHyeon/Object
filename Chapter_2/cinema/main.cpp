#include "stdafx.h"
#include "Movie.h"

int main()
{
	Movie avatar(L"아바타", std::chrono::seconds(120), Money(10000));
	printf("아바타 영상의 가격: %llu", avatar.getFee().fee());
	return 0;
}