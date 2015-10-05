#include <cstdio>
#include <iostream>
using namespace std;

int** multiply(int** matrix1, int** matrix2, int a, int b, int c) 
{
	int** result = new int*[a];
	for (int i = 0; i < a; i++) 
	{
		result[i] = new int[b];
		for (int j = 0; j < b; j++) 
		{
			result[i][j] = 0;
			for (int k = 0; k < c; k++)
				result[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}
	return result;
}


int main()
{
	
}