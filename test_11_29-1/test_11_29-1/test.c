//#include<stdio.h>
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "hello world";int
//	char *str3 = "hello world";
//	char *str4 = "hello world";
//	if (str1 == str2)//����ͬ�ַ�����ʼ���������飬�Ὺ�ٲ�ͬ���ڴ�顣
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)//ָ��ͬһ���ַ�����ָ��ͬһ���ڴ�
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}
//int* arr1[10];//����ָ������
//char *arr2[4];//һ���ַ�ָ������
//char **arr3[5]//�����ַ�ָ������
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr);
//	printf("arr=%p\n", arr);
//	printf("&arr=%p\n", &arr);
//	printf("arr+1=%p\n", arr + 1);//������Ԫ�ص�ַ��+1����һ��Ԫ��
//	printf("&arr+1=%p\n", &arr + 1);//�����ַ������������Ԫ�ص�ַ��+1������������
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