#include "search_algos.h"

/**
  * binary_search - search for a value in sorted array
  *                 of integers using binary search.
  * @array: Pointer to first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, return -1.
  *         else, returns index where the value is located.
  *
  * Description: After each change, prints the [sub]array being searched.
  */

int binary_search(int *array, size_t size, int value)
{
	size_t a, left, right;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (a = left; a < right; a++)
			printf("%d, ", array[a]);
		printf("%d\n", array[a]);

		a = left + (right - left) / 2;
		if (array[a] == value)
			return (a);
		if (array[a] > value)
			right = a - 1;
		else
			left = a + 1;
	}

	return (-1);
}

