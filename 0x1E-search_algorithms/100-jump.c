#include "search_algos.h"

/**
  * jump_search - To search for a value in sorted array
  *               of integers using jump search.
  * @array: Pointer to first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, return -1.
  *         else, returns first index where the value is located.
  *
  * Description: Every time it is compared in the array, prints a value.
  *              It uses the square root of the array size as the jump step.
  */

int jump_search(int *array, size_t size, int value)
{
	size_t a, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (a = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		a = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", a, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; a < jump && array[a] < value; a++)
		printf("Value checked array[%ld] = [%d]\n", a, array[a]);
	printf("Value checked array[%ld] = [%d]\n", a, array[a]);

	return (array[a] == value ? (int)a : -1);
}

