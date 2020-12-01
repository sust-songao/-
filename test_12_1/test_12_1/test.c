//实现一个函数，可以左旋转字符串中的k个字符
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

void left_move(char arr[], int k)
{
	int i = 0;
	int len = strlen(arr);
	assert(k <= len);
	for (i = 0; i < k; i++)
	{
		char tmp = arr[0];
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
	}
		arr[len - 1] = tmp;
	}
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	
	return 0;
}