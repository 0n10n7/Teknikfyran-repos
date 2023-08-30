#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>

#define NUM_ENTRIES 353

//Kod som kanske inte längre behövs
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
bool SearchArray(char goal[],char target[]){
    int i=0;
    while(true){
        if(goal[i]=='\0'&&target[i]=='\0'){
            return true;
        }
        else if(goal[i]=='\0'||target[i]=='\0'){
            return false;
        }
        if(goal[i]!=target[i]){
            return false;
        }
        i++;
    }
}

typedef struct relationship
{
    char* name;
    int weight;
}relationship;

typedef struct character
{
    char* name;
    relationship relationships[50];
}character;


int main(){
    char characters[NUM_ENTRIES][20] = { 0 };
    int currentCharacterIndex = 0;
    
    char source[20] = { 0 };
    char target[20] = { 0 };
    char weightString[3]= { 0 };
    int weight = 0;
    char lineChar = ' ';
    int lineNumber = 0;
    int index = 0;
    int type = 0; //om type är 0 så är det source som arbetas med, 1 är target och 2 är weight

    FILE* fptr = fopen("thrones.csv", "r");
    //Läser in filen rad för rad
    while (fscanf(fptr, "%c", lineChar) != EOF) {
        index++;
        if(lineChar=='\0'){
            //Gör loopen redo för nästa rad
            lineNumber++;
            type=0;
            for (int i = 0; i < 20; i++)
            {
                source[i]=0;
                target[i]=0;
            }
            for (int i = 0; i<3;i++){
                weightString[i]=0;
            }
            
        }
        else if(lineChar==','){

            if(type==0){//source
                source[index]='\0';
            }
            else if (type==1)//target
            {
                target[index]='\0';
            }
            else if (type==2)//
            {
                weightString[index]='\0';
            }
            type++;
        }
        if(type==0){//source
            source[index]=lineChar;
        }
        else if (type==1)//target
        {
            target[index]=lineChar;
        }
        else if (type==2)//
        {
            source[index]=lineChar;
        }
        
        characters[lineNumber][5] = '\0'; //positionen måste ändras

        for(int i = 0; i<20; i++){
            source[i]=0;
            target[i]=0;
        }
        lineNumber++;
    }
    

    
    fclose(fptr);
    return 0;
}