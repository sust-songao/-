
#include<stdio.h>
#include<assert.h>
#include<string.h>

//ÄæÐò×Ö·û´®
void revrese(char*left, char*right)
{
	char tmp = 0;
	assert(right != NULL);
	assert(left != NULL);
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k)
{
	int i = 0;
	int len = strlen(arr);
	revrese(arr, arr + k - 1);
	revrese(arr + k, arr + len - 1);
	revrese(arr, arr + len - 1);
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf_s("%d", &k);
	printf("%s\n", arr);
	left_move(arr, k);
	printf("%s\n", arr);
	return 0;
}