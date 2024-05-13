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
        char name[50];
    };
    struct myStruct s1;
    s1.age = 10;
    struct myStruct *ps =&s1;
    strcpy(s1.name, "mostafa haydar");
    printf("my age is :%d\n", s1.age);
    printf("my name is :%s\n", s1.name);
    printf("the adresse of this pointer is:%p", &s1);
    printf("the adresse of this pointer is:%p", ps+1);
    return 0;
}