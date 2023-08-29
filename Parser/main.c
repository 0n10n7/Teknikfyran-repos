#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>

#define NUM_ENTRIES 353

int ConvertStringToInt(char string[],int length){
    int returnVal=0;
    for (int i = length;i>0;i--){
        int multiplier = 1;
        for (int j = 0; j<i;j++){
            multiplier*=10;
        }
        returnVal+=string[i]*multiplier;
    }
    return returnVal;
}

int main(){
    char characters[NUM_ENTRIES][20] = { 0 };

    

    char lineContent[5];
    int lineNumber = 0;

    FILE* fptr = fopen("thrones.csv", "r");
    //Läser in filen rad för rad
    while (fscanf(fptr, "%s", lineContent) != EOF) {
        int index=0;
        char source[20] = { 0 };
        char target[20] = { 0 };
        char weight [3];
        for(int i = 0; i<3;i++){
            char currentChar = lineContent[index];
            while (currentChar != ',' || currentChar !='\0')
            {
                if(i==0){ //source
                    source[index]=currentChar;
                }
                else if(i == 1){ //target
                    target[index]=currentChar;
                }
                else if(i == 2){ //weight

                }
                index++;
            }
            index++;
        }
        memcpy(characters[lineNumber], lineContent, 5);
        characters[lineNumber][5] = '\0'; //positionen måste ändras
        lineNumber++;
    }
    

    
    fclose(fptr);
    return 0;
}