#include "ListNode.h"
#include <iostream>
List::List(ListNode* head, ListNode* tail) {
	this->head = head;
	this->tail = tail;
}

List::List(int count) {
	this->count = count;
}

void List::Serialize(FILE* file) {
	std::unordered_map<ListNode*, int> mapList;
	ListNode* cur = head;
	count = 0;
	file = fopen("bin.bin", "wb");
	while (cur!=nullptr)
	{
		mapList.emplace(cur, count);
		count++;
		cur = cur->next;
	}
	cur = head;
	while (cur != nullptr) {
		fwrite(&cur->data,sizeof(cur->data),1,file);
		if (cur->rand!=nullptr) 
		{
			fwrite(&mapList[cur->rand], sizeof(int), 1, file);
		}
		else {
			int n = -1;
			fwrite(&n, sizeof(int), 1, file);
		}
		cur = cur->next;
	}
	fclose(file);
	std::cout << "Сериализация выполнена" << std::endl;
}

void List::Deserialize(FILE* file) {
	std::vector<ListNode*> listNodes;
	std::vector<int> listRands;
	std::string strData;
	file = fopen("bin.bin", "rb");
	int indRand;
	for (int i = 0; i < count; i++)
	{
		fread(&strData, sizeof(std::string), 1, file);
		fread(&indRand, sizeof(int), 1, file);
		ListNode* curNode = new ListNode;
		curNode->data = strData;
		listNodes.emplace_back(curNode);
		listRands.emplace_back(indRand);
	}
	head = listNodes[0];
	tail = listNodes[listNodes.size() - 1];


	for (int i = 0; i < count; i++)
	{
		listNodes[i]->prev = i > 0 ? listNodes[i - 1] : nullptr; // check for the first node, if not -> set prev address, else nullptr
		listNodes[i]->next = i < listNodes.size() - 1 ? listNodes[i + 1] : nullptr; // same check for the last node
		listNodes[i]->rand = listRands[i] >= 0 ? listNodes[listRands[i]] : nullptr; // check if node should has rand address
	}
	fclose(file);
	std::cout << "Десериализация выполнена" << std::endl;
}