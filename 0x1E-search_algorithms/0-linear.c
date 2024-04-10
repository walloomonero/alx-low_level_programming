#include "search_algos.h"

/**
  * linear_search - To search for a value in an array
  *                 of integers using linear search.
  * @array: Pointer to first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, returns -1.
  *         else, returns first index where the value is located.
  *
  * Description: Every time it is compared in the array prints a value.
  */

int linear_search(int *array, size_t size, int value)
{
	size_t a;

	if (array == NULL)
		return (-1);

	for (a = 0; a < size; a++)
	{
		printf("Value checked array[%ld] = [%d]\n", a, array[a]);
		if (array[a] == value)
			return (a);
	}

	return (-1);
}

