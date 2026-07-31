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
    result[cursor] = '\0';
}

int genRand(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

char* loadWords(){
    FILE *pFile = fopen("words.txt", "r");
    if(pFile == NULL){
        printf("error reading the file\n");
    }
    
    fseek(pFile, 0, SEEK_END); // seek to end of file
    int fileSize = ftell(pFile); // get current file pointer
    fseek(pFile, 0, SEEK_SET); // seek back to beginning of file

    char *buffer = malloc(fileSize + 1);

    size_t bytesRead = fread(buffer, 1, fileSize, pFile);
    buffer[bytesRead] = '\0';

    fclose(pFile);

    return buffer;
}

void saveScore(int score){
    FILE *pFile = fopen("score.txt", "w");
    if(pFile == NULL){
        printf("error saving your score\n");
    }
    fprintf(pFile, "%d", score);
    fclose(pFile);
}

void readScore(char *score){
    FILE *pFile = fopen("score.txt", "r");
    if(pFile == NULL){
        printf("no saved score!\n");
    }
    fgets(score, 2, pFile);
    fclose(pFile);
}

int main(){
    srand(time(0));

    printf("M[O][R][D](E)[L]!\n");
    char score[2] = {0};
    readScore(score);

    printf("Highest Score: %s", score);
    printf("\nGuess a word from 5 chars in UPPER case!\n");
    printf("[A] right char in right place\n");
    printf("(A) right char in wrong place\n");
    printf("A wrong char in wrong place\n");
    
    char *words = loadWords();;
    printf("Loading words list from words.txt ...\n");
    // printf("%s", words);
    int rnum = genRand(0,512);
    char word[6] = {0};

    for(int i = 0; i < 5; i++){
        word[i] = words[(rnum*5) + i];
        // printf("%d%c\n", i, words[(rnum*5) + i]);
    }
    word[5] = '\0';
    printf("%s", word);

    printf("Ready!\n");
    char buffer[50];
    char result[20];
    int tries = 6;
    int tried = 0;

    while(tried != tries){
        input(buffer, tried);
        if(strlen(buffer) != 5){
            printf("no more or less than 5 chars, try again!\n");
        }else if(wordCheck(buffer, word)){
            printf("You guessed it right!,\n");
            printf("Your Score is: %d", tries - tried);
            saveScore(tries - tried);
            tried = 6;
        }else{
            resultProcess(word, buffer, result);
            printf("%s\n", result);
            tried++;
        }
    }
    printf("\nthe word is: %s ", word);
    printf("Game Over!\n");

    free(words);
    words = NULL;
    return 0;
}