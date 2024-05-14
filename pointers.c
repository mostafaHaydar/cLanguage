#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char moi, char computer)
{

    if (moi == computer)
        return -1;

    if (moi == 'r' && computer == 'p')
    {
        return 0;
    }
    else if (moi == 'p' && computer == 'r')
    {
        return 1;
    }
    if (moi == 'r' && computer == 's')
    {
        return 0;
    }
    else if (moi == 's' && computer == 'r')
    {
        return 1;
    }
    if (moi == 'p' && computer == 's')
    {
        return 0;
    }
    else if (moi == 's' && computer == 'r')
    {
        return 1;
    }
}

int main()
{

    int r;
    int lower_limit = 1; // Define lower limit
    int upper_limit = 3; // Define upper limit
    char moi, computer, res;

    srand(time(NULL));

    r = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    switch (r)
    {
    case 1:
        computer = 'r';
        break;
    case 2:
        computer = 'p';
        break;
    case 3:
        computer = 's';
        break;
    default:
        printf("Error: Invalid random number generated.\n");
        return 1;
    }

    printf("\t \t \t \t ******** welcome to this game********** \t \n\n  ");
    printf("rules :\n");
    printf(" r : for rock \n p : for paper \n s : for scisors\n\n\n");

    printf("choisir un element : ");
    scanf("%c", &moi);

    res = game(moi, computer);
    
    if (res == -1)
    {
        printf("meme element ");
    }
    else if (res == 0)
    {
        printf("you won !!!!!!");
    }
    else
    {
        printf("you lose ");
    }
    printf("\t\t\t\tYOu choose : %c and Computer choose : %c\n", moi, computer);
    return 0;
}