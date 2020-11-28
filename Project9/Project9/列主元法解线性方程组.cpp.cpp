#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
#define MAX 20
double* gaussh(int, double[][20], double[]);
void main()
{
	int i, j, n;
	double A[MAX][MAX], x[MAX];
	cout << "请输入方程的未知数个数：" << endl;
	cin >> n;
	cout << "请输入增广矩阵：" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			cin >> A[i][j];
		}
	}
	cout << endl;
	cout << "方程解为：" << endl;
	gaussh(n, A, x);
	for (i = 1; i <= n; i++)
		cout << "x[" << i << "]=" << fixed << setprecision(2) << x[i] << endl;
	system("pause");
	return;
}
double* gaussh(int n, double A[MAX][MAX], double x[])
{
	int i, j, k, m;
	double temp, p, sum, mx;
	for (i = 1; i <= n - 1; i++)
	{
		//选主元
		mx = fabs(A[i][i]);
		for (j = i + 1, k = i; j <= n; j++)
		if (fabs(A[j][i]) > mx)
		{
			k = j;
			mx = fabs(A[j][i]);
		}
		//交换当前行与主元行
		if (i < k)
		{
			for (m = 1; m <= n + 1; m++)
			{
				temp = A[i][m];
				A[i][m] = A[i + 1][m];
				A[i + 1][m] = temp;
			}
		}
		//消元过程
		for (j = i; j <= n - 1; j++)
		{
			p = A[j + 1][i] / A[i][i];
			for (k = i; k <= n + 1; k++)
				A[j + 1][k] = A[j + 1][k] - p*A[i][k];
		}
	}
	//回代过程
	x[n] = A[n][n + 1] / A[n][n];
	for (i = n - 1; i >= 1; i--)
	{
		sum = 0;
		for (j = i + 1; j <= n; j++)
			sum = sum + A[i][j] * x[j];
		x[i] = (A[i][n + 1] - sum) / A[i][i];
	}
	return x;
}