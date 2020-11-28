#include<iostream> 
#include<iomanip>
#include<cstring>
#define max 100
using namespace std;
double x[max];
double f[max][max];
int n;
void newton(double f[][max]);
int print();
int main()
{
	double ans, xi, t;
	cout << "输入需要插值的节点个数 : ";
	cin >> n;
	memset(f, 0, sizeof(f));
	cout << "请输入节点与节点值：" << endl;
	cout << "Xi : ";
	for (int i = 0; i < n; i++)
		cin >> x[i];
	cout << "Yi : ";
	for (int i = 0; i < n; i++)
		cin >> f[i][0];
	newton(f);
	print();
	system("pause");
}

int print()
{
	cout << "牛顿插值均差表 : " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(10) << f[i][j] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
void newton(double f[][max])
{
	int i, j;
	for (int i = 1; i < n; i++)
	for (int j = i; j < n; j++)
	{
		f[j][i] = (f[j - 1][i - 1] - f[j][i - 1]) / (x[j - i] - x[j]);
	}
	return;
}