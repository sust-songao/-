#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
void main(\

{
	double malagr(double x[], double f[], double a, int n);
	double x[30], f[30], ff, a;
	int n, k;
	cout << "请输入已知点的个数n：" << endl;
	cin >> n;
	cout << "请输入需要插值的点a：" << endl;
	cin >> a;
	cout << "请输入x与f的值:" << endl;
	for (k = 0; k < n; k++)
	{
		cin >> x[k] >> f[k];
	}
	cout << endl;
	ff = malagr(x, f, a, n);
	cout << "The value of" << a << "=" << fixed << setprecision(4) << ff << endl;
	system("pause");
	return;
}
double malagr(double x[], double f[], double a, int n)
{
	int i, k;
	double l, ff = 0.0;
	for (k = 0; k < n; k++)
	{
		l = 1.0;
		for (i = 0; i < n; i++)
		{
			if (i != k)
			{
				l = l*(a - x[i]) / (x[k] - x[i]);
			}
		}
		ff = ff + l*f[k];
	}
	return ff;
}