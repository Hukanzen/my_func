#include<stdio.h>
#include<stdlib.h>

#include"my_func.h"

#define N 10

int main(void)
{
	int *x;
	int err;
	int p_size=N;
	x=(int *)calloc(p_size,sizeof(int));

	printf("=== a_reset ===\n");
	err=a_reset(x,p_size,0);

	err=a_show(x,p_size);

	printf("=== a_random ===\n");
	err=a_random(x,p_size,0,99);
	err=a_show(x,p_size);

	printf("=== a_max ===\n");
	int max=a_max(x,p_size);
	printf("max:%d\n",max);

	printf("=== a_min ===\n");
	int min=a_min(x,p_size);
	printf("min:%d\n",min);

	printf("=== a_show ===\n");
	err=a_show(x,p_size);
	
	free(x);

	return 0;
}
