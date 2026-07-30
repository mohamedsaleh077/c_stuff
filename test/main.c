#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(0));
    int min = 0;
    int max = 3;
    int num = (rand() % (max - min + 1)) + min;

    char *arr[4] = { "hi", "hello", "bye", "why" };

    printf("%s", arr[num]);
    return 0;
}