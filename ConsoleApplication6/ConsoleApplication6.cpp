#include <iostream>
#include "BinaryTransform.h"
#include "dups.h"
#include <Windows.h>
#include "ListNode.h"


int main()
{

	SetConsoleOutputCP(1251);

	int number;
	std::cout << "Введите число:";
	std::cin >> number;
	std::cout << "Число в двоичной системе: " << transb(number) << std::endl;


	char str[] = "AAA BBB AAA";
	std::cout << "Строка до очистки: " << str << std::endl;
	RemoveDups(str);
	std::cout << "Строка После очистки: " << str << std::endl;
	

	
	ListNode* first = new ListNode;
	ListNode* second = new ListNode;
	ListNode* third = new ListNode;

	first->data = "Первый";
	first->next = second;

	second->data = "Второй";
	second->prev = first;
	second->next = third;

	third->data = "Третий";
	third->prev = second;
	third->next = nullptr;

	first->rand = third;
	second->rand = nullptr;
	third->rand = second;

	List l(first, third);

	FILE* wFile;
	wFile = fopen("bin.bin", "wb");
	l.Serialize(wFile);
	fclose(wFile);

	FILE* rFile;
	rFile = fopen("bin.bin", "rb");
	l.Deserialize(rFile);
	fclose(rFile);
}

