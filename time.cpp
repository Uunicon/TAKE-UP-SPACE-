#include<iostream> 
#include<time.h>
#include<cmath>
using namespace std;
clock_t start, stop;
double duration;
#define MAXN 101
#define MAXK 1e6
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main()
{
	int i;
	double a[MAXN];
	for (i = 0; i < MAXN; i++)a[i] = (double)i;

	start = clock();
	for(i=0;i<MAXK;i++)
	  f1(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK/MAXK;
	cout << "ticks1=" << (double)(stop - start) << endl;
	cout << "durations=" << duration << endl;

	start = clock();
	for (i = 0; i<MAXK; i++)
	  f2(MAXN - 1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start)) / CLK_TCK/MAXK;
	cout << "ticks1=" << (double)(stop - start) << endl;
	cout << "durations=" << duration << endl;

	return 0;
}

double f1(int n, double a[], double x)
{
	int i;
	double p = a[1];
	for (i = 1; i <= n; i++)
		p += (pow(x, i) / a[i]);
	return p;
}

double f2(int n, double a[], double x)
{
	int i;
	double p =1/a[n];
	for (i = 1; i <= n; i++)
		p = 1/a[n-1]+x*p;
	return p;
}
