#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define F(x,y)  (x+y)
#define w(x)     (2*exp(x)-x-1)
void main()
{
	void meauler(double x, double y, double h, int n);
	int n;
	double t0, tn;
	double h = 0.1, y, x, y0 = 1, x0 = 0;
	y = y0;
	x = x0;
	cout << "请输入求解区间：" << endl;
	cin >> t0 >> tn;
	n = (tn - t0) / h;
	cout << "迭代次数为：" << n << endl;
	cout << "x\t\t" << "y(x)\t\t" << "w(x)\t\t" << "y(x)-w(x)" << endl;
	cout << fixed << setprecision(2) << x << "\t\t" << fixed << setprecision(4) << y << "\t\t" << w(x) << "\t\t" << fabs(y - w(x)) << "\t\t" << endl;
	meauler(x, y, h, n);
	system("pause");
	return;
}
void meauler(double x, double y, double h, int n)
{
	double x1, y1;
	int i;
	for (i = 1; i <= n; i++)
	{
		y1 = y + h*F(x, y);
		x1 = x;
		x = x + h;
		y = y + 0.5*h*(F(x1, y) + F(x, y1));
		if (i % 1 == 0);
		cout << fixed << setprecision(2) << x << "\t\t" << fixed << setprecision(4) << y << "\t\t" << w(x) << "\t\t" << fabs(y - w(x)) << "\t\t" << endl;
	}
	system("pause");
	return;
}