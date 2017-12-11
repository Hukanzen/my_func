
#include <stdio.h>
#include <stdlib.h>
#include "./Multiprece.h"

// int ck_size(int *ar,int size)
// {
// 	return (sizeof(ar) / sizeof(int)) != size ? TRUE : FALSE;
// }

int reset_size(int *ar, int size,int v)
{
	int i = 0;
	for (i = 0; i < size;i++){
		ar[i] = v;
	}
}

int show_arr(const char *str, int *ar, int size)
{
	int i;
	printf("%s ", str);
	for (i = 0; i < size;i++) printf("%d", ar[i]);
	printf("\n");

	return 0;
}

int print_arr(const char *str, int *ar, int size)
{
	int i;
	for (i = 0; i < size; i++){
		printf("%s %d\n",str, ar[i]);
	}
}

void swap_arr(int *ar,int *tar,int size)
{
	int i;

	for (i = 0; i < size; i++)	{
		tar[i] = ar[size - i - 1];
	}

}

int add(int *ar, int *ar1, int *ar2, int size)
{
	int *tar,*tar1,*tar2;

	tar = calloc(size + 1, sizeof(int));
	tar1 = calloc(size, sizeof(int));
	tar2 = calloc(size, sizeof(int));
	
	/* 入れ換える */
	swap_arr(ar1, tar1, size);
	swap_arr(ar2,tar2, size);

	// print_arr("ar1 ", ar1, size);
	// print_arr("ar2 ", ar2, size);
 
	/* 繰り上がり用 */
	int *buf;
	buf = calloc(size+1, sizeof(int));
	buf[0] = 0;

	int i;
	for (i = 0 ; i < size; i++){
		int sum;
		sum = buf[i]+tar1[i] + tar2[i];
		
		tar[i] = sum%10;
		buf[i+1] = sum / 10;
	}
	tar[size] = buf[size];

	free(buf);
	
	/* 和 */
	swap_arr(tar,ar,size+1);

	return 0;
}

int sub(int *ar, int *ar1, int *ar2, int size)
{
	int *tar, *tar1, *tar2;

	tar = calloc(size + 1, sizeof(int));
	tar1 = calloc(size, sizeof(int));
	tar2 = calloc(size, sizeof(int));

	/* 入れ換える */
	swap_arr(ar1, tar1, size);
	swap_arr(ar2, tar2, size);

	// print_arr("ar1 ", ar1, size);
	// print_arr("ar2 ", ar2, size);

	/* 繰り上がり用 */
	int *buf;
	buf = calloc(size + 1, sizeof(int));
	buf[0] = 0;

	int i;
	for (i = 0; i < size; i++){
		tar1[i] -= buf[i];
		tar[i] = tar1[i] - tar2[i];
		if(tar[i]<0){
			tar[i] = 10+ tar[i];
			buf[i + 1] = 1;
		}else{
			buf[i] = 0;
		}
	}
	tar[size] = buf[size];

	free(buf);

	/* 差 */
	swap_arr(tar, ar, size + 1);

	return 0;
}