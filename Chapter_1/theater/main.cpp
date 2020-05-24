#include "stdafx.h"
#include "Theater.h"
#include "TicketSeller.h"

#include <random>
#include <vector>
#include <queue>

int main()
{
	//
	// 1. Theater 생성하려면 TicketSeller 필요
	// 2. TicketSeller 생성하려면 TicketOffice 필요
	// 3. TicketOffice 생성하려면 amount와 std::list<Ticket> 필요
	//

	std::queue<Ticket> ticket_list;

	// Theater의 관람객 수만큼 Ticket을 발행해야한다.
	int audience_count = 10;
	
	for (int i = 0; i < audience_count; ++i)
	{
		//long ticket_fee = 1000;
		//ticket.push(Ticket(ticket_fee));
		ticket_list.push(Ticket(1000));
	}

	// #3 ticketOffice 생성
	long ticketoffice_amount = 10000000;
	TicketOffice office(ticketoffice_amount, std::move(ticket_list));

	// #2 TicketSeller 생성
	TicketSeller ticketSeller(office);

	// #1 Theater 생성
	Theater theater(ticketSeller);

	printf("==================================\n");
	printf("Theater amount: %ld\n", theater.get_amount());
	printf("ticket count: %zd\n", theater.get_ticket_count());

	//
	// 4. 관람객을 생성하려면 Bag 필요
	//	  관람객을 audience_count 만큼 생성하고 초대장을 절반만 부여한다.
	//
	
	//	관람객의 amount을 난수로 생성 (1000~20000)
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<long> dis(1000, 20000);

	//	일단 관람객의 절반의 수만큼만 초대장을 생성
	std::vector<Audience> audience_list;
	int invitation_count = audience_count / 2;
	for (int i = 0; i < audience_count; ++i)
	{
		if (invitation_count <= 0)
		{
			Bag bag(dis(gen));
			audience_list.push_back(Audience(bag));
		}
		else
		{
			invitation_count--;
			Invitation invitation(20200524);
			Bag bag(invitation, dis(gen));
			audience_list.push_back(Audience(bag));
		}
	}

	// 관람객 입장
	for (int i = 0; i < audience_count; ++i)
	{
		printf("==================================\n");
		printf("inviation [%d] \n", i);
		printf("amount: %ld\n", audience_list.at(i).get_amount());
		printf(audience_list.at(i).has_invitation() ? "invitation: true\n\n" : "invitation: false\n\n");
		
		theater.enter(audience_list.at(i));
		
		printf("after\n\n");
		printf("amount: %ld\n", audience_list.at(i).get_amount());
		printf(audience_list.at(i).has_ticket() ? "Ticket: true\n" : "Ticket: false\n");
	}

	printf("==================================\n");
	printf("Theater amount: %ld\n", theater.get_amount());
	printf("ticket count: %zd\n", theater.get_ticket_count());
	printf("==================================\n");

	return 0;
}