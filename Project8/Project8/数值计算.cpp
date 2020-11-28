#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	double* newton(double x0, double y0, double e, double A[]);
	double x0, y0, A[2], e;
	cout << "请输入迭代初值：" << endl;
	cout << "x0=";
	cin >> x0;
	cout << "y0=";
	cin >> y0;
	cout << "请输入结果所需达到精度：" << endl;
	cin >> e;
	newton(x0, y0, e, A);
	cout << "线性方程组的解为：" << endl;
	cout << fixed << setprecision(7) << "x=" << A[0] << "\ty=" << A[1] << endl;
	system("pause");
	return 0;
}
double* newton(double x0, double y0, double e, double A[])
{
	int i;
	double x1, x2, x3, x4, hls, t;
	double a[2][2], b[2], c[2], d[2];
	x1 = x0;
	x2 = y0;
	a[0][0] = -2 * y0 - 1;//伴随矩阵
	a[0][1] = -2 * x0;
	a[1][0] = -2 * y0;
	a[1][1] = 2 * x0 - 1;
	hls = a[0][0] * a[1][1] - a[0][1] * a[1][0];//求伴随矩阵的行列式
	for (i = 0; i<20; i++)//求逆及运算
	{
		b[0] = x0*x0 + y0 * y0 - x0;
		b[1] = x0*x0 - y0*y0 - y0;
		c[0] = (a[0][0] * b[0] + a[0][1] * b[1]) / hls;
		c[1] = (a[1][0] * b[0] + a[1][1] * b[1]) / hls;
		d[0] = x0 - c[0];
		d[1] = y0 - c[1];
		x3 = fabs(d[0] - x0);
		x4 = fabs(d[1] - y0);
		if (x3>x4)
			t = x3;
		else
			t = x4;
		if (t < e)
		{
			x0 = d[0];
			y0 = d[1];
		}
		else
		{
			A[0] = d[0];
			A[1] = d[1];
			break;
		}
	}
	return A;
}


