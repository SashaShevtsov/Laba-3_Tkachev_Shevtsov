#include <iostream>
#include <math.h>
using namespace std;
struct polynomial
{
	int sum[100];
	int comp[100];
};
polynomial mySumandComp(int* a, int size_a, int* b, int size_b)
{
	polynomial resPolynom;
	if (size_a >= size_b)
	{
		int i;
		for (i = size_a - 1; i > (size_a - size_b - 1); i--)
			resPolynom.sum[i] = a[i] + b[i - size_a + size_b];
		for (i = size_a - size_b - 1; i > -1; i--)
			resPolynom.sum[i] = a[i];
	}
	else
	{
		int i;
		for (i = size_b - 1; i > (size_b - size_a - 1); i--)
			resPolynom.sum[i] = b[i] + a[i - size_b + size_a];
		for (i = size_b - size_a - 1; i > -1; i--)
			resPolynom.sum[i] = b[i];
	}
	int size_comp = size_a + size_b - 1;
	for (int ix = 0; ix < size_comp; ix++)
		resPolynom.comp[ix] = 0;
	for (int deg = size_comp - 1; deg > -1; deg--)
	{
		for (int i = 0; i < size_a; i++)
		{
			for (int j = 0; j < size_b; j++)
			{
				if ((size_a - 1 - i) + (size_b - 1 - j) == deg)
					resPolynom.comp[size_comp - 1 - deg] += a[i] * b[j];
			}
		}
	}
	return resPolynom;
}
int main()
{
	return 0;
}