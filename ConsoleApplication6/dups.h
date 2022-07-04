#pragma once
#include <string>
 
void RemoveDups(char* str) {
	int i = 0;
	int count = 1;
	while (i < strlen(str) - 1)
	{
		if (str[i] == str[i + count])
		{
			str[i + count] = ' ';
			count++;
		}
		else
		{
			i += count;
			count = 1;
		}

	}
}