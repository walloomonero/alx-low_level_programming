#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - a function that deletes a hash table.
 * @ht:  is the hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *node, *temp_free;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
			temp_free = node;
			node = node->next;
			if (temp_free->key)
				free(temp_free->key);
			if (temp_free->value)
				free(temp_free->value);
			free(temp_free);
			}
		}
	}
	free(ht->array);
	free(ht);
}
