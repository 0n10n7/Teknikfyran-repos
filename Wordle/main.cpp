#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ENTRIES 14855


int main(){
    char words[NUM_ENTRIES][6] = { 0 };
    char word[5];
    int line = 0;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));
    int random = (rand() % (NUM_ENTRIES +1)) ;

    FILE* fptr = fopen("valid-wordle-words.txt", "r");
    while (fscanf(fptr, "%s", word) != EOF) {
        memcpy(words[line], word, 5);
        words[line][5] = '\0';
        line++;
    }
    printf("Random word at that index %s \n",words[random]);


    bool gameOn = true;
    int round = 1;
    while(true == gameOn || round <6){
        char attempt[5];
        puts("Please enter an integer: ");
        scanf("%s", attempt);
        round ++;
    }
    fclose(fptr);
    return 0;
}