#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>

#define NUM_ENTRIES 14855


int main(){
    char words[NUM_ENTRIES][6] = { 0 };
    char word[5];
    int line = 0;

    FILE* fptr = fopen("thrones.csv", "r");
    while (fscanf(fptr, "%s", word) != EOF) {
        memcpy(words[line], word, 5);
        words[line][5] = '\0';
        line++;
    }
    

    
    fclose(fptr);
    return 0;
}