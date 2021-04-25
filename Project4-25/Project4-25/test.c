#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW 4
#define COL 7

//实现一个函数，可以左旋字符串中的k个字符。
//void spin(char* arr, int n)
//{
//	int sz = strlen(arr);
//	while (n)
//	{
//		int i = 0;
//		char tmp = 0;
//		tmp = arr[0];
//		for (i = 0; i < sz - 1; i++)
//		{
//			arr[i] = arr[i + 1];
//		}
//		arr[sz - 1] = tmp;
//		n--;
//	}
//	return;
//}
//int main()
//{
//	char arr[20] = { 0 };
//	int num = 0;
//	printf("请输入字符串和要旋转的字符数：");
//	scanf("%s%d", &arr,&num);
//	spin(arr, num);
//	printf("旋转%d个字符后，字符串变成：%s\n", num, arr);
//	return 0;
//}

//qsort模拟实现
////冒泡模拟实现回调机制（升序）
////参数依次表示的意义：要排序的数组、数组内的元素个数、每个元素的字节数、比较方法（e1大于e2，返回正值；等于返回0；小于返回负值）
//void swap(char* arr1, char* arr2, int byte)
//{
//	int i = 0;
//	for (i = 0; i < byte; i++)
//	{
//		char tmp = *(arr1 + i);
//		*(arr1 + i) = *(arr2 + i);
//		*(arr2 + i) = tmp;
//	}
//	return;
//}
//void bubble_sort(void* arr, int sz, int byte, int (*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (cmp((char*)arr+j*byte, (char*)arr+(j + 1)*byte) > 0)    //难点，理解了这个就理解了这个函数了
//			{
//				swap((char*)arr + j * byte, (char*)arr + (j + 1) * byte, byte);
//			}
//		}
//	}
//	return;
//}
////下面比较一下整数数组，升序排列
//int int_cmp(const int* x, const int* y)
//{
//	return (*x - *y);    //加一个负号就是降序排列了，这里决定排序方式
//}
//int main()
//{
//	int arr[] = { 2,4,1,3,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	printf("排序前：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	bubble_sort(arr, sz, 4, int_cmp);
//	printf("\n");
//	printf("排序后：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}

//练习一个float型数组的qsort快排实现
//int float_cmp(const float* x, const float* y)
//{
//	float ret = *x - *y;
//	if (ret > (int)ret)
//	{
//		return (int)ret + 1;
//	}
//	return (int)ret;    
//}
//int main()
//{
//	float arr[] = { 1.2f,3.8f,4.5f,6.4f,5.4f };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	printf("排序前：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%.1f ", arr[i]);
//	}
//	qsort(arr, sz, 4, float_cmp);
//	printf("\n");
//	printf("排序后：");
//	for (i = 0; i < sz; i++)
//	{
//		if (i != sz - 1) 
//		{
//			printf("%.1f < ", arr[i]);
//		}
//		else
//		{
//			printf("%.1f", arr[i]);
//		}	
//	}
//	printf("\n");
//	return 0;
//}

//判断e2是不是e1旋转得到的，是返回1,不是返回0。循环旋转e1与e2作比较，e2只做输入不改变，定义为const
//int judge_spin(char* e1, const char* e2)
//{
//	int sz = strlen(e1);
//	int i = 0;
//	for (i = 0; i < sz; i++)    //可能旋转的元素个数
//	{
//		char tmp = e1[0];
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)
//		{
//			e1[j] = e1[j + 1];
//		}
//		e1[sz - 1] = tmp;
//		if (strcmp(e1, e2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char str1[100] = { 0 };
//	char str2[100] = { 0 };
//	printf("请输入要判断的字符串：\n");
//	scanf("%s%s", str1, str2);
//	int ret = judge_spin(str1, str2);
//	if (ret)
//	{
//		printf("旋转得到的。\n");
//	}
//	else
//	{
//		printf("不是旋转得到的。\n");
//	}
//	return 0;
//}

//杨氏矩阵:矩阵的每行从左到右是递增的，矩阵每列从上到下是递增的。请编写程序在杨氏矩阵中查找某个数字是否存在
//int num_search1(int arr[ROW][COL],int num)
//{
//	//元素不在矩阵范围
//	if (num < arr[0][0] || num > arr[ROW - 1][COL - 1])
//	{
//		return 0;
//	}
//	int i = 0;
//	int j = 0;
//	//从左上角最小的开始，不满足条件，每次往右1或下1
//	while (i < COL)
//	{
//		//下1
//		if (num > arr[i][j])
//		{
//			i++;
//		}
//		//下1大了，退回去右1
//		if (num < arr[i][j])
//		{
//			i--;
//			j++;
//		}
//		//找到最后一行，还是小了，往右找
//		if (i == ROW - 1)
//		{
//			j++;
//		}
//		if (arr[i][j] == num)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int num_search2(int arr[ROW][COL], int num)
//{
//	if (num > arr[ROW - 1][COL - 1] || num < arr[0][0])
//	{
//		return 0;
//	}
//	int i = 0;
//	int j = 0;
//	//从左上角最小的开始，不满足条件，每次往右1或下1
//	while (i < COL)
//	{
//		//右1
//		if (num > arr[i][j])
//		{
//			j++;
//		}
//		//右1大了，退回去下1
//		if (num < arr[i][j])
//		{
//			j--;
//			i++;
//		}
//		//找到最后一列，还是小了，往下找
//		if (j == COL - 1)
//		{
//			i++;
//		}
//		if (num == arr[i][j])
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[ROW][COL] = { {0,7,14,21,28,35,42},
//		                  {1,8,15,22,29,36,43},
//		                  {2,9,16,23,30,37,44},
//		                  {3,10,17,24,31,38,45} };
//	int input = 0;
//	printf("请输入要查找的值：");
//	scanf("%d", &input);
//	//int ret = num_search1(arr, input);
//	int ret = num_search2(arr, input);
//	if (ret)
//	{
//		printf("存在\n");
//	}
//	else
//	{
//		printf("不存在\n");
//	}
//	return 0;
//}