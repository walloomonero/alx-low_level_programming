#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - a function that prints a hash table.
 * Description: print the key/value in the order that
 * they appear in the array of hash table
 *
 * @ht: is the hash table
 *
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	int comm_pri = 0;

	if (ht == NULL)

		return;  /* Don't print anything if the hash table is NULL */

	printf("{");

	for (i = 0; i < ht->size; ++i)
	{
		node = ht->array[i];
		while (node)
		{
			if (comm_pri)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			comm_pri = 1;
			node = node->next;
		}
	}
	printf("}\n");
}
