#include "search_algos.h"

/**
  * advanced_binary_recursive - To search recursively for a value in a sorted
  *                             array of integers using binary search.
  * @array: Pointer to the first element of [sub]array to search.
  * @left: Starting index of [sub]array to search.
  * @right: Ending index of [sub]array to search.
  * @value: value to search for.
  *
  * Return: If value is not present in array or if array is NULL, return -1
  *         else, the index where the value is located.
  *
  * Description: Every time you split the array,
  *              to print the new array (or subarray) you’re searching in.
  */

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t a;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (a = left; a < right; a++)
		printf("%d, ", array[a]);
	printf("%d\n", array[a]);

	a = left + (right - left) / 2;
	if (array[a] == value && (a == left || array[a - 1] != value))
		return (a);
	if (array[a] >= value)
		return (advanced_binary_recursive(array, left, a, value));
	return (advanced_binary_recursive(array, a + 1, right, value));
}

/**
  * advanced_binary - T search for a value in sorted array
  *                   of integers using advanced binary search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, return -1.
  *         Otherwise, first index where the value is located.
  *
  * Description: To Print the [sub]array being searched after each change.
  */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

