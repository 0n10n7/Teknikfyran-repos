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
    //picks wordle word
    char wordleWord[6];
    memcpy(wordleWord, words[random], 5);
    printf("Random word at that index %s \n",wordleWord);

    //game loop
    bool gameOn = true;
    bool wrong = true;
    int round = 1;
    while(true == gameOn || round <7)
    {
        bool valid = false;
        char attempt[6];
        //input loop
        while (true!=valid)
        {   
            printf("round %d/6  :Please enter a guess ", round);
            scanf("%5s", attempt);
            fflush(stdin);
            printf("\nyou guessed %s", attempt);
            for(int i = 0; i <NUM_ENTRIES; i++){
                if(attempt==words[i]){
                    puts("Which is a valid guess:");
                    valid=true;
                }
            }
            if(valid != true){
                puts("which isn't a valid guess, try again.");
            }
        }
        
        // Wordle checker
        for(int i=0; i <5; i++){
            // checks which letters are right
            if(wordleWord[i]==attempt[i]){
                printf("\x1b[32;49m%c",wordleWord[i]);
            }
            // checks which letters are almost right
            for(int j = 0; j <5; j++){
                if(wordleWord[i]==attempt[i]){
                printf("\x1b[32;49m%c",wordleWord[i]);
            }
            }
            // handles completly wrong words
            if (wrong){
                printf("\x1b[0m");
            }
        }
        round ++;
    }
    fclose(fptr);
    return 0;
}