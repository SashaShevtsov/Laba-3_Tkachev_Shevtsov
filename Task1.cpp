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
void assert(int** matrix1, int** matrix2, int a, int b, int c, int** resmatrix)
{
	int** firstmatrix = multiply(matrix1, matrix2, a, b, c);
	bool isTrue = true;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (firstmatrix[i][j] != resmatrix[i][j])
				isTrue = false;
		}
	}
	if (isTrue)
		cout << "OK" << endl;
	else
		cout << "False" << endl;
}
void tests()
{
	int** matrix1 = new int*[4];
	for (int i = 0; i < 4; i++)
		matrix1[i] = new int[2];
	matrix1[0][0] = 6;
	matrix1[0][1] = 7;
	matrix1[1][0] = 5;
	matrix1[1][1] = 0;
	matrix1[2][0] = -1;
	matrix1[2][1] = 2;
	matrix1[3][0] = 6;
	matrix1[3][1] = 3;
	int** matrix2 = new int*[2];
	for (int i = 0; i < 2; i++)
		matrix2[i] = new int[3];
	matrix2[0][0] = 5;
	matrix2[0][1] = 4;
	matrix2[0][2] = 3;
	matrix2[1][0] = 2;
	matrix2[1][1] = 3;
	matrix2[1][2] = 6;
	int** resmatrix1 = new int*[4];
	for (int i = 0; i < 4; i++)
		resmatrix1[i] = new int[3];
	resmatrix1[0][0] = 44;
	resmatrix1[0][1] = 45;
	resmatrix1[0][2] = 60;
	resmatrix1[1][0] = 25;
	resmatrix1[1][1] = 20;
	resmatrix1[1][2] = 15;
	resmatrix1[2][0] = -1;
	resmatrix1[2][1] = 2;
	resmatrix1[2][2] = 9;
	resmatrix1[3][0] = 36;
	resmatrix1[3][1] = 33;
	resmatrix1[3][2] = 36;
	assert(matrix1, matrix2, 4, 3, 2, resmatrix1);
	int** matrix3 = new int*[2];
	for (int i = 0; i < 3; i++)
		matrix3[i] = new int[3];
	matrix3[0][0] = 5;
	matrix3[0][1] = 8;
	matrix3[0][2] = -3;
	matrix3[1][0] = 6;
	matrix3[1][1] = -2;
	matrix3[1][2] = 0;
	int** matrix4 = new int*[3];
	for (int i = 0; i < 3; i++)
		matrix4[i] = new int[2];
	matrix4[0][0] = 7;
	matrix4[0][1] = 1;
	matrix4[1][0] = -4;
	matrix4[1][1] = 6;
	matrix4[2][0] = 5;
	matrix4[2][1] = 6;
	int** resmatrix2 = new int*[2];
	for (int i = 0; i < 2; i++)
		resmatrix2[i] = new int[2];
	resmatrix2[0][0] = -12;
	resmatrix2[0][1] = 35;
	resmatrix2[1][0] = 50;
	resmatrix2[1][1] = -6;
	assert(matrix3, matrix4, 2, 2, 3, resmatrix2);
	int** matrix5 = new int*[3];
	for (int i = 0; i < 3; i++)
		matrix5[i] = new int[3];
	matrix5[0][0] = 5;
	matrix5[0][1] = 1;
	matrix5[0][2] = 5;
	matrix5[1][0] = 1;
	matrix5[1][1] = 5;
	matrix5[1][2] = 1;
	matrix5[2][0] = 5;
	matrix5[2][1] = 1;
	matrix5[2][2] = 5;
	int** matrix6 = new int*[3];
	for (int i = 0; i < 3; i++)
		matrix6[i] = new int[3];
	matrix6[0][0] = 3;
	matrix6[0][1] = 2;
	matrix6[0][2] = 3;
	matrix6[1][0] = 2;
	matrix6[1][1] = 3;
	matrix6[1][2] = 2;
	matrix6[2][0] = 3;
	matrix6[2][1] = 2;
	matrix6[2][2] = 3;
	int** resmatrix3 = new int*[3];
	for (int i = 0; i < 3; i++)
		resmatrix3[i] = new int[3];
	resmatrix3[0][0] = 32;
	resmatrix3[0][1] = 23;
	resmatrix3[0][2] = 32;
	resmatrix3[1][0] = 16;
	resmatrix3[1][1] = 19;
	resmatrix3[1][2] = 16;
	resmatrix3[2][0] = 32;
	resmatrix3[2][1] = 23;
	resmatrix3[2][2] = 32;
	assert(matrix5, matrix6, 3, 3, 3, resmatrix3);
}
int main()
{
	tests();
	return 0;
}