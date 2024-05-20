#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct USER
    {
        int id;
        char firstName;
        struct USER *next;
    };
    struct USER *current = NULL;
    struct USER *previous = NULL;

    current = (struct USER *)malloc(sizeof(struct USER));
    current->id = 0;
    current->firstName = 'a';
    current->next = NULL;
    previous = current;

    current = (struct USER *)malloc(sizeof(struct USER));
    current->id = 1;
    current->firstName = 'b';
    previous->next = current;
    current->next = NULL;

    printf("%d", current[1].id);
    return 0;
}