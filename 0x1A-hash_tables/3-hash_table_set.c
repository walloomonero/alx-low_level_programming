#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
/**
 * hash_table_set - A function that adds an element to the hash table.
 * @ht: The hash table to add or update the key/value pair.
 * @key: The key - cannot be an empty string.
 * @value: The value associated with the key -
 * must be duplicated, can be an empty string.
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *previous_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	previous_node = ht->array[index];
	while (previous_node != NULL)
	{
		if (strcmp(previous_node->key, key) == 0)
		{
			free(previous_node->value);
			previous_node->value = strdup(value);
			if (previous_node->value == NULL)
				return (0);
			return (1);
		}
		previous_node = previous_node->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
