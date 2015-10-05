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
void assertSum(int* a, int* b, int size_a, int size_b, int* c)
{
	polynomial result = mySumandComp(a, size_a, b, size_b);

	bool right = true;
	if (size_a > size_b)
	{
		int size = size_a;
		for (int i = 0; i < size; i++)
		{
			if (result.sum[i] != c[i])
				right = false;
		}

		if (right)
			cout << "OK" << endl;
		else
			cout << "NE OK" << endl;
	}
	else
	{
		int size = size_a;
		for (int i = 0; i < size; i++)
		{
			if (result.sum[i] != c[i])
				right = false;
		}

		if (right)
			cout << "OK" << endl;
		else
			cout << "NE OK" << endl;
	}
}

void assertComp(int* a, int* b, int size_a, int size_b, int* d)
{
		polynomial result = mySumandComp(a, size_a, b, size_b);
		bool right = true;
			int size = size_a;
			for (int i = 0; i < size_a*size_b; i++)
			{
				if (result.comp[i] != d[i])
					right = false;
			}

			if (right)
				cout << "OK" << endl;
			else
				cout << "NE OK" << endl;
}


int main()
{
	int a[]{ 1,2,3 };
	int b[]{ 2,3 };
	int a1[]{ 1,4,6 };
	int b1[]{ 2,7,12,9 };
	int c[]{ 4,5,3 };
	int d[]{ 10,3 };
	int c1[]{ 4,15,6 };
	int d1[]{ 40,62,45,9 };
	assertSum(a, b, 3, 2, a1);
	assertComp(a, b, 3, 2, b1);
	assertSum(c, d, 3, 2, c1);
	assertComp(c, d, 3, 2, d1);
	return 0;
}
