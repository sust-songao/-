//#include<stdio.h>
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "hello world";int
//	char *str3 = "hello world";
//	char *str4 = "hello world";
//	if (str1 == str2)//用相同字符串初始化两个数组，会开辟不同的内存块。
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)//指向同一串字符串，指向同一块内存
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}
//int* arr1[10];//整型指针数组
//char *arr2[4];//一级字符指针数组
//char **arr3[5]//二级字符指针数组
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr);
//	printf("arr=%p\n", arr);
//	printf("&arr=%p\n", &arr);
//	printf("arr+1=%p\n", arr + 1);//数组首元素地址，+1跳过一个元素
//	printf("&arr+1=%p\n", &arr + 1);//数组地址并不是数组首元素地址，+1跳过整个数组
//	return 0;
//}
//#include<stdio.h>
//void print_arr1(int arr[3][5], int row, int col)
//{
//	int i = 0;
//	int j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
////void print_arr2(int(*arr)[5], int row, int col)
//void print_arr2(int*arr[5], int row, int col)
//{
//	int i = 0;
//	int j;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//		}
//	}
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	print_arr1(arr, 3, 5);
//	print_arr2(arr, 3, 5);
//	return 0;
//}