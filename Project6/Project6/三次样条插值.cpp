#include<iostream>
#include<iomanip>
#include<memory.h>
#include<math.h>
using namespace std;
const int max = 50;
double x[max], y[max], m[max], h[max];
#define  n 4
#define alpha0(x) (2*pow(x,3)-3*pow(x,2)+1)
#define alpha1(x) (-2*pow(x,3)+3*pow(x,2))
#define beta0(x) (pow(x,3)-2*pow(x,2)+x)
#define beta1(x) (pow(x,3)-pow(x,2))
int main()
{
	void machase(double lambda[], double mu[], double theta[]);
	void print(double a[], int t);
	int  i, t;
	double lambda[max], mu[max], theta[max], a[max];
	double *b[max];
	for (i = 0; i < n; i++)
	{
		cout << "第" << i + 1 << "个插值点:";
		cin >> x[i] >> y[i];
	}
	for (i = 0; i < n; i++)//求步长
		h[i] = x[i + 1] - x[i];
	float ff1, ff2;
	int j;
	cout << "输入边界条件Y0\' Y" << n - 1 << "\'\n";
	cin >> ff1 >> ff2;
	cout << "请输入需要计算的插值点个数：";
	cin >> t;
	cout << "请输入需要计算的插值点：" << endl;
	for (i = 0; i < t; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	for (i = 0; i < n - 2; i++)
	{
		lambda[i] = (h[i + 1] / (h[i] + h[i + 1]));
		mu[i] = 1 - lambda[i];
		theta[i] = (3 * lambda[i] * ((y[i + 1] - y[i]) / h[i])) + (3 * mu[i] * ((y[i + 2] - y[i + 1]) / h[i + 1]));
	}
	theta[0] = theta[0] - lambda[0] * ff1;
	theta[n - 3] = theta[n - 3] - lambda[n - 3] * ff2;
	//追赶法
	machase(lambda, mu, theta);
	m[0] = ff1;
	m[n - 1] = ff2;
	print(a, t);
	system("pause");
}
void print(double a[], int t)
{
	int i, j, k;
	double s[max];
	k = 1;
	for (i = 0; i < t; i++)
	{
		if (a[i] >= x[0] & a[i] <= x[1])
			j = 1;
		else if (a[i] >= x[1] & a[i] <= x[2])
			j = 2;
		else
			j = 3;
		s[i] = alpha0((a[i] - x[j - 1]) / h[j - 1])*y[j - 1] + alpha1((a[i] - x[j - 1]) / h[j - 1])*y[j] + h[j - 1] * m[j - 1] * beta0((a[i] - x[j - 1]) / h[j - 1]) + h[j - 1] * m[j] * beta1((a[i] - x[j - 1]) / h[j - 1]);
		cout << "S(" << fixed << setprecision(1) << a[i] << ")=" << fixed << setprecision(4) << s[i] << "\t\t";
		k = k + 1;
		if (k % 4 == 0)
			cout << endl;
	}
	cout << endl;
	system("pause");
	return;
}
void machase(double lambda[], double mu[], double theta[])
{
	double A[n - 2][n - 2];
	double b[n - 2];
	int i, j;
	memset(A, 0, sizeof(A));
	//计算三对角矩阵
	for (i = 0; i < n - 2; i++)
	{
		A[i][i] = 2;
		b[i] = theta[i];
	}
	for (i = 0; i < n - 3; i++)
	{
		A[i][i + 1] = mu[i];
		A[i + 1][i] = lambda[i];
	}
	//追
	for (i = 1; i < n - 2; i++)
	{
		A[i][i - 1] = A[i][i - 1] / A[i - 1][i - 1];
		A[i][i] = A[i][i] - A[i - 1][i] * A[i][i - 1];
		b[i] = b[i] - b[i - 1] * A[i][i - 1];
	}
	//赶
	b[n - 3] = b[n - 3] / A[n - 3][n - 3];
	for (i = n - 4; i >= 0; i--)
	{
		b[i] = (b[i] - A[i][i + 1] * b[i + 1]) / A[i][i];
	}
	for (i = 1; i <= n - 2; i++)
	{
		m[i] = b[i - 1];
	}
	return;
}