#include "search_algos.h"

/**
 * linear_skip - To Search for an algorithm in a sorted singly
 *               linked list of integers using linear skip.
 * @list: Pointer to the  head of the linked list to search.
 * @value: Value to search for.
 *
 * Return: If value is not present in list or if head is NULL,
 *         your function must return NULL, else
 *         a pointer to the first node where the value is located.
 *
 * Description: Every time you compare a value in the list
 *              to the value you are searching, you have to print this value.
 *              It uses the square root of the list size as the jump step.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *jump;

	if (list == NULL)
		return (NULL);

	for (node = jump = list; jump->next != NULL && jump->n < value;)
	{
		node = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}

