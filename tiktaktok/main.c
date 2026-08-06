#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef enum status { WIN, LOSE, DRAW } Status_t;

int genRand(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

void redner(char* grid, int* input){
    printf("\033[H\033[J");
    printf("Tik Tak Tok\n");
    printf(" %c | %c | %c \n",grid[0] ,grid[1] ,grid[2] );
    printf("———————————\n");
    printf(" %c | %c | %c \n",grid[3] ,grid[4] ,grid[5] );
    printf("———————————\n");
    printf(" %c | %c | %c \n",grid[6] ,grid[7] ,grid[8] );
    printf("where would you play? ");
    scanf("%1d", input);
    fflush(stdout);
}

void show_results(Status_t *player){
    switch(*player){
        case WIN:
            printf("\n You win!");
        case LOSE:
            printf("\n You Lose!");
        case DRAW:
            printf("\n Draw!")
    }
}

int main(){
    srand(time(0));

    bool running = true;
    Status_t player = DRAW;
    char grid[9] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };
    int input = 0;
    
    while(running){
        redner(grid, &input);
        grid[input - 1] = 'x';
    }

    return 0;
}