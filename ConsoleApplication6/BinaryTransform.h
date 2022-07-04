#pragma once

int transb(int number) {
	int binary = 0;
	int max = 0;
	while (pow(2,max) < number)
	{
		max++;
	}

	for (int i = max; i >= 0; i--)
	{
		if (number-pow(2,i)>=0)
		{
			number -= pow(2, i);
			binary *=10;
			binary++;
		}
		else {
			binary *= 10;
		}
	}
	return binary;
}