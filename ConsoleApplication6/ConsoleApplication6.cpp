#include <iostream>
#include "BinaryTransform.h"
#include "dups.h"
#include <Windows.h>
#include "ListNode.h"
/*
Задание выполнил Скорых Михаил Андреевич
Дата выполнения 04.07.2022
Примерное количество времени, затраченного на выполнение: 4.5 часа
*/

int main()
{

	SetConsoleOutputCP(1251);

	int number;
	std::cout << "Введите число:";
	std::cin >> number;
	transb(number);


	char data[] = "AAA BBB AAA";
	std::cout << "Строка до очистки: " << data << std::endl;
	RemoveDups(data);
	printf("Строка после очистки: %s\n", data);
	

	
	ListNode* first = new ListNode;
	ListNode* second = new ListNode;
	ListNode* third = new ListNode;
	ListNode* fourth = new ListNode;

	first->data = "Первый";
	first->next = second;

	second->data = "Второй";
	second->prev = first;
	second->next = third;

	third->data = "Третий";
	third->prev = second;
	third->next = fourth;

	fourth->data = "Четвёртый";
	fourth->prev = third;
	fourth->next = nullptr;

	first->rand = third;
	second->rand = nullptr;
	third->rand = second;
	fourth->rand = first;

	List list(first, fourth);

	FILE* wFile = new FILE();
	list.Serialize(wFile);

	FILE* rFile = new FILE();
	list.Deserialize(rFile);

}

