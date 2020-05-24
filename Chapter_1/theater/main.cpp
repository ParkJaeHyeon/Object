#include "stdafx.h"
#include "Theater.h"
#include "TicketSeller.h"

#include <random>
#include <vector>
#include <queue>

int main()
{
	//
	// 1. Theater �����Ϸ��� TicketSeller �ʿ�
	// 2. TicketSeller �����Ϸ��� TicketOffice �ʿ�
	// 3. TicketOffice �����Ϸ��� amount�� std::list<Ticket> �ʿ�
	//

	std::queue<Ticket> ticket_list;

	// Theater�� ������ ����ŭ Ticket�� �����ؾ��Ѵ�.
	int audience_count = 10;
	
	for (int i = 0; i < audience_count; ++i)
	{
		//long ticket_fee = 1000;
		//ticket.push(Ticket(ticket_fee));
		ticket_list.push(Ticket(1000));
	}

	// #3 ticketOffice ����
	long ticketoffice_amount = 10000000;
	TicketOffice office(ticketoffice_amount, std::move(ticket_list));

	// #2 TicketSeller ����
	TicketSeller ticketSeller(office);

	// #1 Theater ����
	Theater theater(ticketSeller);

	printf("==================================\n");
	printf("Theater amount: %ld\n", theater.get_amount());
	printf("ticket count: %zd\n", theater.get_ticket_count());

	//
	// 4. �������� �����Ϸ��� Bag �ʿ�
	//	  �������� audience_count ��ŭ �����ϰ� �ʴ����� ���ݸ� �ο��Ѵ�.
	//
	
	//	�������� amount�� ������ ���� (1000~20000)
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<long> dis(1000, 20000);

	//	�ϴ� �������� ������ ����ŭ�� �ʴ����� ����
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

	// ������ ����
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