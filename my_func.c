#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"my_func.h"

int a_reset(int *x,int size,int num)
{
	int i;
	for(i=0;i<size;i++){
		x[i]=num;
	}

	return 0;
}


int a_random(int *x,int size,int min,int max)
{
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<size;i++){
		x[i]=rand()%max+min;
	}

	return 0;
}

int a_max(int *x,int size)
{
	int i;
	int max=x[0];
	for(i=1;i<size;i++){
		if(max<x[i]) max=x[i];
	}

	return max;
}

int a_min(int *x,int size)
{
	int i;
	int min=x[0];
	for(i=1;i<size;i++){
		if(min>x[i]) min=x[i];
	}

	return min;
}

int a_ssort(int *x,int size,int sk)
{
	int i,j;
}

int swap(int *a,int *b)
{
	/* ok ?*/
	int tmp;	

	tmp=*a;
	*a=*b;
	*b=tmp;

	return 0;
}

int a_show(int *x,int size)
{
	int i;
	for(i=0;i<size;i++) printf("%d\n",x[i]);

	return 0;
}
