#include "array_recursive.h"
#include <stdlib.h>
#include <stdio.h>
int find_max_of_array(int a[], int n)
{
	find_max_of_array_recursive(a, n, a[n - 1]);
}

int find_max_of_array_recursive(int a[], int n, int temp)
{
	if (n == 0)
	{
		if (a[0] > temp)
		{
			return a[0];
		}
		else
			return temp;
	}
	else if (a[n] > temp)
	{
		temp = a[n];
		
	}
	return find_max_of_array_recursive(a, n - 1, temp);
}

int sum_of_array(int a[], int n)
{
	if (n <= 0)
		return 0;
	return sum_of_array(a, n - 1) + a[n];
}


