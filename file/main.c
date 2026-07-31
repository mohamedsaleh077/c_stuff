#include <stdio.h>
#include <string.h>
int main(){

    FILE *pFile = fopen("file.txt", "r");

    if(pFile == NULL){
        printf("error reading the file");
        return 1;
    }

    char buffer[1024] = {0};
    char split[6] = {0};
    // char pInput[1024] = {0};
    fgets(buffer, sizeof(buffer), pFile);
    // while(fgets(buffer, sizeof(buffer), pFile) != NULL){}
    // {
    //     printf("%s", buffer);
    // strncpy(pInput, buffer, 1024);
    // };
    // printf("%c", buffer[8]);
    for(int i = 0; i < 5; i++){
        split[i] = buffer[i + 3 - 1];
    }
    split[6] = '\0';
    printf("%s", split);
    fclose(pFile);
    return 0;
}