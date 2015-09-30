#include <iostream>
#include <math.h>
using namespace std;
struct threeNumbers
{
	int n1, n2, n3;
};
void bubble_sort(int *array, int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int b = array[i];
				array[i] = array[i + 1];
				array[i + 1] = b;
			}
		}
	}
}
threeNumbers myMax3numbers(int* arrayofnumbers, int size)
{
	threeNumbers mymax3numbers;
	bubble_sort(arrayofnumbers, size);
	if (arrayofnumbers[0] * arrayofnumbers[1]>arrayofnumbers[size - 2] * arrayofnumbers[size - 3])
	{
		mymax3numbers.n1 = arrayofnumbers[size - 1];
		mymax3numbers.n2 = arrayofnumbers[0];
		mymax3numbers.n3 = arrayofnumbers[1];
	}
	else
	{
		mymax3numbers.n1 = arrayofnumbers[size - 1];
		mymax3numbers.n2 = arrayofnumbers[size - 2];
		mymax3numbers.n3 = arrayofnumbers[size - 3];
	}
	return mymax3numbers;
}
int main()
{
	return 0;
}