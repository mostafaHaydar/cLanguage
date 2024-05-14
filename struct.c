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
    s1[0].age=10;
    s1[0].name='c';
    s1[1].age=NULL;
    s1[1].name=NULL;
    printf("%d", s1[0].age);
    printf("%d", s1[1].age);
    return 0;
}