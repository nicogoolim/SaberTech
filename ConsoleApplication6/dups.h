#pragma once
#include <string>
 
void RemoveDups(char* str) {
	for (int i = 0; i < strlen(str)-1; i++)
	{
		if (*(str+i)==*(str+i+1))
		{
			for (int j = i+1; j < strlen(str); j++)
			{
				if (*(str + i) == *(str + j))
				{
					*(str + j) = ' ';
				}
				else {
					break;
				}
			}
		}
	}
}