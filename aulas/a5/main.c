#include <stdio.h>
#include <stdlib.h>

typedef struct list List;

struct list {
    int value;
    List *next;
};

List *list_create(int value)
{
    List *list = (List *)malloc(sizeof(List));
    list->value = value;
    list->next = NULL;

    return list;
}

List *list_insert(List *list, int value)
{
    List *new = (List *)malloc(sizeof(List));
    new->value = value;
    new->next = list;

    return new;
}

List *list_end(List *list)
{
    List *node = list;

    if (node == NULL)
    {
        return NULL;
    }

    while (node->next)
    {
        node = node->next;
    }

    return node;
}

int list_length(List *list)
{
    int length = 0;

    for (List *node = list; node != NULL; node = node->next)
    {
        length++;
    }

    return length;
}

List *list_concat(List *list_a, List *list_b)
{
    if (list_a == NULL)
    {
        return list_b;
    }

    List *end = list_end(list_a);
    end->next = list_b;

    return list_a;
}

int list_greather_than(List *start, int n)
{
    int count = 0;

    for (List *list = start; list != NULL; list = list->next)
    {
        if (list->value > n)
        {
            count++;
        }
    }

    return count;
}

int main() {
    List *list_a = list_create(10);
    list_a = list_insert(list_a, 5);
    list_a = list_insert(list_a, 3);

    List *list_b = list_create(2);
    list_b = list_insert(list_b, 12);

    printf("Length: %d\n", list_length(list_a));
    printf("Greather than 4: %d\n", list_greather_than(list_a, 4));

    List *concat = list_concat(list_a, list_b);
    printf("Concat Length: %d\n", list_length(concat));
}
