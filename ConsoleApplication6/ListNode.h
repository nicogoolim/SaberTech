#pragma once
#include <stdio.h>
#include <string>
#include <unordered_map>
// структуру ListNode модифицировать нельзя
struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand; // указатель на произвольный элемент данного списка, либо NULL
	std::string data;
};
class List {
public:
	void Serialize(FILE* file); // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
	void Deserialize(FILE* file); // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
	List(ListNode* head, ListNode* tail);
	List(int count);
private:
	ListNode* head;
	ListNode* tail;
	int count;
};