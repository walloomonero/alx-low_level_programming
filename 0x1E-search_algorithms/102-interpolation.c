#include "search_algos.h"

/**
  * interpolation_search - To search for a value in sorted array
  *                        of integers using interpolation search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, return -1.
  *         else, returns first index where the value is located.
  *
  * Description: Every time it is compared in the array, prints a value.
  */

int interpolation_search(int *array, size_t size, int value)
{
	size_t a, k, w;

	if (array == NULL)
		return (-1);

	for (k = 0, w = size - 1; w >= k;)
	{
		a = k + (((double)(w - k) / (array[w] - array[k])) * (value - array[k]));
		if (a < size)
			printf("Value checked array[%ld] = [%d]\n", a, array[a]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", a);
			break;
		}

		if (array[a] == value)
			return (a);
		if (array[a] > value)
			w = a - 1;
		else
			k = a + 1;
	}

	return (-1);
}

