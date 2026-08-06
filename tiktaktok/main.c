#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum { WIN, LOSE, DRAW, PLAYING } Status_t;

void show_results(Status_t *player);

const int WINNING_STATUES[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // raws
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
    {0, 4, 8}, {2, 4, 6} // cross
};

int find_critical_move(char* grid, char c, bool is_winner){
    for(int i = 0; i < 9; i++){
        int count = 0;
        int empty = 9;
        for(int j = 0; j < 3; j++){
            int idx = WINNING_STATUES[i][j];
            if(grid[idx] == c){ count++; }
            else{empty = idx;}
        }
        if(is_winner){
            if(count == 3){ return -1;}
        }
        if(count == 2 && count != 9){ return count; }
    }
    return 9;
}

int corner_move(char* grid){
    for(int i = 0; i < 9; i++){
        if(i != 4){
            if(grid[i] != 'x' && grid[i] != 'o'){
                return i;
            }
        }
    }
    return 9;
}

void computer_play(char* grid){
    int move = 9;
    // best move for win
    move = find_critical_move(grid, 'x', false);

    // block the way for the player
    if(move == 9){ move = find_critical_move(grid, 'o', false); }

    // use cross if not used
    if(move == 9 && grid[4] != 'x' && grid[4] != 'o'){ move = 4; }

    // get corners
    if(move == 9){ move = corner_move(grid); }

    // do move
    if(move >= 0 && move < 9){ grid[move] = 'x'; }
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

Status_t player_win(char* grid){
    int status = find_critical_move(grid, 'o', true);
    if(status == -1){ return WIN; }
    for(int i = 0; i < 9; i++){
        if(grid[i] != 'x' && grid[i] != 'o'){
            return PLAYING;
        }
    }
    return DRAW;
}

void show_results(Status_t *player){
    switch(*player){
        case WIN:
            printf("\n You win!");
            break;
        case LOSE:
            printf("\n You Lose!");
            break;
        case DRAW:
            printf("\n Draw!");
            break;
    }
}

void user_input_and_validate(char* grid, int* input){
    while(true){
        if(grid[*input] != 'o' && grid[*input] != 'x'){
            grid[*input] = 'o';
            break;
        }else{
            redner(grid, input);
        }
    }
}

int main(){
    bool running = true;
    Status_t player = DRAW;

    char grid[9] = {
        '0', '1', '2',
        '3', '4', '5',
        '6', '7', '8'
    };
    int input = 0;
    
    while(running){
        redner(grid, &input);
        user_input_and_validate(grid, &input);
        player = player_win(grid);
        if(player == PLAYING){
            computer_play(grid);
        }else{
            show_results(&player);
        }
    }

    return 0;
}