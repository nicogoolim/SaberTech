#pragma once
#include <stdio.h>
#include <string>
#include <unordered_map>
// ��������� ListNode �������������� ������
struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand; // ��������� �� ������������ ������� ������� ������, ���� NULL
	std::string data;
};
class List {
public:
	void Serialize(FILE* file); // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
	void Deserialize(FILE* file); // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))
	List(ListNode* head, ListNode* tail);
	List(int count);
private:
	ListNode* head;
	ListNode* tail;
	int count;
};