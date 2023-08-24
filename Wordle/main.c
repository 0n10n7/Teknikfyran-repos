#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>

#define NUM_ENTRIES 14855

//array comparitor stulen från emil
bool char_array_equals(char arr1[], char arr2[])
{
    for(int i = 0; i < 5; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }
    }
    return true;
}

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
    int round = 1;
    while(true == gameOn && round <7)
    {
        //gameOn is turned to false so that the game does not continue if nothing turns it back on again thereby acting as a win checker
        gameOn=false;
        bool wrong = true;
        bool valid = false;
        char attempt[6];
        //input loop
        while (true!=valid)
        {   
            printf("round %d/6  :Please enter guess ", round);
            scanf("%5s", attempt);
            attempt[5]='\0';
            fflush(stdin);
            printf("\nyou guessed %s\n", attempt);
            for(int i = 0; i <NUM_ENTRIES; i++){
                if(char_array_equals(attempt,words[i])){
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
            wrong=true;
            // checks which letters are right
            if(wordleWord[i]==attempt[i]){
                printf("\x1b[32;40;1m%c",wordleWord[i]);
                wrong=false;
            }
            // checks which letters are almost right
            else{
                for(int j = 0; j <5; j++){
                    if(wordleWord[i]==attempt[j] && wordleWord[i]!=attempt[i]){
                        printf("\x1b[33;40;1m%c",wordleWord[i]);
                        wrong=false;
                        gameOn=true;
                    }
                }
            }
            
            // handles completly wrong letters
            if (wrong){
                printf("\x1b[39;40;9;1m%c",attempt[i]);
                gameOn=true;
            }
        }
        printf("\x1b[0m\n");
        round ++;
    }
    if(round!=7){
        printf("\x1b[32;40;1;4mCongrats you won!!!\n");
    }
    else{
        printf("\x1b[31;40;1;4mGAME OVER\nBetter luck next time\n");
    }
    fclose(fptr);
    return 0;
}