#include<iostream>
#include<iomanip>
#include<memory.h>
#include<cmath>
using namespace std;
#define MAX 50//��������������
#define f(x) (x*exp(x)-1)//���巽��
void main()
{
	void mabisec(double a, double b, double e);
	double a, b, e;
	int i = 1;
	cout << "��������������ֵ��" << endl;
	cin >> a;
	cout << "������������Ҷ�ֵ��" << endl;
	cin >> b;
	cout << "�����뾫�ȣ�" << endl;
	cin >> e;
	mabisec(a, b, e);
	system("pause");
	return;
}
void mabisec(double a, double b, double e)
{
	int i = 1;
	double p, h;
	cout << "i\t a(i)\t\t\t b(i)\t\t\t  p(i)\t\t\t  f(p(i))\t\t  h(i)" << endl;
	while (i <= MAX)
	{
		p = (a + b) / 2.0;
		h = fabs((b - a) / 2.0);
		cout << fixed << setprecision(2) << i << "\t" << fixed << setprecision(6) << a << "\t\t" << b << "\t\t" << p << "\t\t" << f(p) << "\t\t" << h << endl;
		if (fabs(f(p)) == 0 || h < e)
		{
			cout << "��������Ϊ:" << i << endl;
			cout << "The Root=" << p << "\t" << "f(" << p << ")=" << f(p) << endl;
			system("pause");
			exit(0);
		}
		else
		{
			if (f(a)*f(p)>0)
				a = p;
			else if (f(b)*f(p) > 0)
				b = p;
			i++;
		}
	}
	return;
}