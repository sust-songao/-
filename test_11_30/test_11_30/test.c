////һ�����鴫��
//#include<stdio.h>
//void test(int arr[])
//{}
//void test1(int arr[10])
//{}
//void test4(int *arr)
//{}
//void test2(int *arr[20])
//{}
//void test3(int **arr[20])
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int *arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//	
//}
//һ��ָ�봫��
//#include<stdio.h>
//void print(int *p, int sz)
//{
//	int i = 0; 
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int *p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//һ��ָ��p��������
//	print(p, sz);
//	return 0;
//}
#include<stdio.h>
//int main()
//{
	int aa[2][5] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int *ptr1 = (int *)(&aa + 1);//�����������飬Խ�磬Ȼ���һ������1
//	int *ptr2 = (int *)(*(aa + 1));//������һ�У��ȵڶ�����Ԫ�أ��ٻ�һλ����6
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//print_arr(arr, 3, 5);
//
//��ҵ����
//A.void print_arr(int arr[][], int row, int col);
//B.void print_arr(int* arr, int row, int col);
//C.void print_arr(int(*arr)[5], int row, int col);
//D.void print_arr(int(*arr)[3], int row, int col);
	//int main()
	//{
	//	int a[5] = { 5, 4, 3, 2, 1 };
	//	int *ptr = (int *)(&a + 1);
	//	printf("%d,%d", *(a + 1), *(ptr - 1));
	//	return 0;
	//}