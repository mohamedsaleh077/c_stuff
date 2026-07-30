#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void input(char *buffer, int tries){
    printf("Guess the word (hearts: %d): \n", 6 - tries);
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

bool wordCheck(char *inputWord, char *chosenWord){
    if(strcmp(inputWord ,chosenWord) == 0){
        return true;
    }
    return false;
}

bool checkChar(char c, char *input){
    for(int i = 0; i < 6; i++){
        if(c == input[i]){
            return true;
        }
    }
    return false;
}

bool checkCharPlace(char c, char input_c){
    if(c == input_c){
        return true;
    }
    return false;
}

void resultProcess(char *word, char *input, char *result){
    int cursor = 0;
    for(int i = 0; i < 5; i++){
        if(checkChar(input[i], word)){
            if(checkCharPlace(input[i], word[i])){
                result[cursor] = '[';
                cursor++;
                result[cursor]= input[i];
                cursor++;
                result[cursor] = ']';
                cursor++;
            }else{
                result[cursor] = '(';
                cursor++;
                result[cursor] = input[i];
                cursor++;
                result[cursor] = ')';
                cursor++;
            }
        }else{
                result[cursor] = ' ';
                cursor++;
                result[cursor] = input[i];
                cursor++;
                result[cursor] = ' ';
                cursor++;
        }
    }
}

int genRand(int min, int max){
    srand(time(0));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main(){
    printf("M[O][R][D](E)[L]!\n");
    printf("\nGuess a word from 5 chars in lower case!\n");
    printf("[A] right char in right place\n");
    printf("(A) right char in wrong place\n");
    printf("A wrong char in wrong place\n");
    
    char *words[] = {
        "apple", "beach", "clock", "drive", "earth",
        "flame", "giant", "house", "image", "juice",
        "knife", "lemon", "music", "night", "ocean",
        "paper", "queen", "river", "smile", "tiger",
        "table", "fable", "cable", "label", "green",
        "great", "width", "depth", "trade", "break",
        "grade", "might", "sneak", "snack", "north",
        "south", "earth", "bring", "dying", "sling",
        "sharp", "shark", "start", "sheet", "smart",
        "royal", "loyal", "piped", "hight", "minus",
        "lorry", "truck", "death", "train", "grain",
        "later", "trust", "brust", "space", "right",
        "wrong", "guess", "dress", "place", "linux",
        "close", "pause", "block", "brick", "build",
        "heart", "brain", "brown", "drown", "black"
    };

    int rnum = genRand(0,74);
    char *s = words[rnum];
    // printf("%d", rnum);
    // printf("%s", words[rnum]);
    char *word = s;
    char buffer[50];
    char result[20];
    int tries = 6;
    int tried = 0;

    while(tried != tries){
        input(buffer, tried);
        if(strlen(buffer) != 5){
            printf("no more or less than 5 chars, try again!\n");
        }else if(wordCheck(buffer, word)){
            printf("You guessed it right!\n");
            tried = 6;
        }else{
            resultProcess(word, buffer, result);
            printf("%s\n", result);
            tried++;
        }
    }
    
    printf("\nthe word is: %s ", word);
    printf("Game Over!\n");
    return 0;
}