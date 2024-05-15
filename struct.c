#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    system("cls");
    struct myStruct
    {
        int age;
        char name;
    };
    struct myStruct s1[10];
    for (int i = 0; i < 10; i++)
    {
        s1[i].age = 1;
    }

    struct myStruct *ps1[10];
    for (int i = 0; i < 10; i++)
    {
        ps1[i] = &s1[i];
        printf("add %p   ::::::::::::: add p %p\n", &s1[i], ps1[i]);
    }
    printf("%d\n", s1[0].age);
    ps1[0]->age = 10;
    printf("%d\n", s1[0].age);
    return 0;
}