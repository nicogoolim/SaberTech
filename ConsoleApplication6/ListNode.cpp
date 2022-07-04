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
	while (cur!=nullptr)
	{
		mapList.emplace(cur, count);
		count++;
		cur = cur->next;
	}
	cur = head;
	while (cur != nullptr) {
		fwrite(&cur->data,sizeof(cur->data),1,file);
		//fprintf(file, cur->data.c_str());
		if (cur->rand!=nullptr)
		{
			fwrite(&mapList[cur->rand], sizeof(int), 1, file);
			//fprintf(file, "%d", mapList[cur->rand]);
		}
		else {
			int n = -1;
			fwrite(&n, sizeof(int), 1, file);
			//fprintf(file, "%d", -1);
		}
		cur = cur->next;
	}
	std::cout << "Сериализация выполнена" << std::endl;
}
void List::Deserialize(FILE* file) {
	std::vector<ListNode*> listNodes;
	std::vector<int> listRands;
	std::string c;
	int ic;
	for (int i = 0; i < count; i++)
	{
		//c=fgetc(file);
		//i = fgetc(file);
		fread(&c, sizeof(std::string), 1, file);
		fread(&ic, sizeof(int), 1, file);
		ListNode* l = new ListNode;
		l->data = c;
		listNodes.emplace_back(l);
		listRands.emplace_back(ic);
	}
	head = listNodes[0];
	tail = listNodes[listNodes.size() - 1];


	for (int i = 0; i < count; i++)
	{
		listNodes[i]->prev = i > 0 ? listNodes[i - 1] : nullptr;
		listNodes[i]->next = i < listNodes.size() - 1 ? listNodes[i + 1] : nullptr;
		listNodes[i]->rand = listRands[i] > 0 ? listNodes[listRands[i]] : nullptr;

	}
	std::cout << "Десериализация выполнена" << std::endl;
}