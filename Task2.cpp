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
	if (arrayofnumbers[size - 1] > 0)
	{
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
	}
	else
	{
		mymax3numbers.n1 = arrayofnumbers[size - 1];
		mymax3numbers.n2 = arrayofnumbers[size - 2];
		mymax3numbers.n3 = arrayofnumbers[size - 3];
	}
	return mymax3numbers;
}
void assert( int size, int* arrayofnumbers, int* arr)
{ 
	threeNumbers result = myMax3numbers(arrayofnumbers, size);
	int ans[3]{ result.n1 , result.n2 , result.n3 };

	bubble_sort(ans, 3);
	bool right = true;
	for (int i = 0; i < 3; i++) {
		if (ans[i] != arr[i])
			right = false;
	}

	if (right)
		cout << "OK" << endl;
	else
		cout << "NE OK"<< endl;
	
}

int main()
{
	int arr1[]{ 1,2,3,4,5,6 }, ans1[]{ 4,5,6 };
	int arr2[]{ 2,4,1,5 }, ans2[]{ 2,4,5 };
	int arr3[]{ 1,1,1,2,-43,3,6,7,34,2 }, ans3[]{ 6,7,34 };
	int arr4[]{ -1,2,3,4,-5,-6,4 }, ans4[]{ -6, -5, 4 };
	assert(6, arr1, ans1);
	assert(4, arr2, ans2);
	assert(10, arr3, ans3);
	assert(7, arr4, ans4);
	return 0;
}
