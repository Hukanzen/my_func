#ifndef __MULTIPRECE_H__
#define __MULTIPRECE_H__

#define TRUE 1
#define FALSE 0

//int ck_size(int *ar, int size);
int reset_arr(int *ar, int size,int v);
int show_arr(const char *str, int *ar, int size);
int print_arr(const char *str, int *ar, int size);
void swap_arr(int *ar, int *tar, int size);
int add(int *ar,  int *ar1,  int *ar2,  int size);
int sub(int *ar, int *ar1, int *ar2, int size);

#endif