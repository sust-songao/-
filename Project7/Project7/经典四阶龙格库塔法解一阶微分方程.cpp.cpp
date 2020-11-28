#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
#define f1(x,y) (x+2*y)
#define f2(x,y) (3*x+2*y)
void main()
{
	void marunge4(double a, double b, double y[], int m, int n);
	int i, j, n = 100, m = 2;
	double t, a = 0.0, b = 0.2, h, y[10], y0[10];
	y0[1] = 6.0;//x的初值
	y0[2] = 4.0;//y的初值
	for (j = 1; j <= m; j++)
		y[j] = y0[j];
	marunge4(a, b, y, m, n);//调用龙格库塔函数
	system("pause");

}
void marunge4(double a, double b, double y[], int m, int n)
{
	int i, j;
	double t, h, k1[10], k2[10], k3[10], k4[10];
	h = (b - a) / n;
	t = a;
	cout << "t\tx\t\ty\t" << endl;
	cout << fixed << setprecision(2) << t << "\t" << fixed << setprecision(7) << y[1] << "\t" << y[2] << endl;
	//计算k1,k2,k3,k4
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j == 1)
				k1[j] = h*f1((y[j]), (y[j + 1]), (y[j + 2]), t);
			else if (j == 2)
				k1[j] = h*f2((y[j - 1]), (y[j]), (y[j + 1]), t);
		}
		for (j = 1; j <= m; j++)
		{
			if (j == 1)
				k2[j] = h*f1((y[j] + 0.5*k1[j]), (y[j + 1] + 0.5*k1[j + 1]), (y[j + 2] + 0.5*k1[j + 2]), (t + 0.5*h));
			else if (j == 2)
				k2[j] = h*f2((y[j - 1] + 0.5*k1[j - 1]), (y[j] + 0.5*k1[j]), (y[j + 1] + 0.5*k1[j + 1]), (t + 0.5*h));
		}
		for (j = 1; j <= m; j++)
		{
			if (j == 1)
				k3[j] = h*f1((y[j] + 0.5*k2[j]), (y[j + 1] + 0.5*k2[j + 1]), (y[j + 2] + 0.5*k2[j + 2]), (t + 0.5*h));
			else if (j == 2)
				k3[j] = h*f2((y[j - 1] + 0.5*k2[j - 1]), (y[j] + 0.5*k2[j]), (y[j + 1] + 0.5*k2[j + 1]), (t + 0.5*h));
		}
		for (j = 1; j <= m; j++)
		{
			if (j == 1)
				k4[j] = h*f1((y[j] + k3[j]), (y[j + 1] + k3[j + 1]), (y[j + 2] + k3[j + 2]), (t + h));
			else if (j == 2)
				k4[j] = h*f2((y[j - 1] + k3[j - 1]), (y[j] + k3[j]), (y[j + 1] + k3[j + 1]), (t + h));
		}
		for (j = 1; j <= m; j++)
			y[j] = y[j] + ((k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j]) / 6.0);//更新y[j]的值
		t = a + i*h;
		if (i % 10 == 0)
			printf("%.2lf	%.7lf	%.7lf\n", t, y[1], y[2]);
	}
	return;
}