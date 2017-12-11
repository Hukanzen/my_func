#include <stdio.h>
#include "./Multiprece.h"

#define SIZE 5

int main(void)
{
	int i;
	int ar[SIZE + 1];
	int ar1[SIZE];
	int ar2[SIZE];

	int k = 0;
	for (k = 0; k < 4; k++)
	{
		for (i = 0; i < SIZE; i++)
		{
			if (k == 0)
			{
				ar1[i] = SIZE - i - 1;
				ar2[i] = i;
		
			}
			else if (k == 1)
			{

				ar1[i] = i;
				ar2[i] = SIZE - i - 1;
			}
			else if (k == 2)
			{
				ar1[i] = 5;
				ar2[i] = 3;
			}
			else if(k==3){
				ar1[i] = 3;
				ar2[i] = 5;
			}
		}

		//printf("add = %d\n",add(ar, ar1, ar2, SIZE));

		sub(ar, ar1, ar2, SIZE);

		show_arr("ar1 =  ", ar1, SIZE);
		show_arr("ar2 =  ", ar2, SIZE);
		show_arr("ar  = ", ar, SIZE + 1);
		
	}

	return 0;
}