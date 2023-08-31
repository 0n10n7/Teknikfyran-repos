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
int SearchArray(char goal[],char target[][20]){//fel fixa
    int i=0;
    for(int i; i < NUM_ENTRIES; i++){
        if (0 == strcmp(goal, target[i])){
            return i; 
        }
    }
    return -1;
}

typedef struct Relationship
{
    char* name;
    int weight;
}Relationship;

typedef struct Character
{
    char name[20];
    Relationship relationships[50];
}Character;


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
        Character character;
        Relationship relationship;
        index++;
        if(lineChar=='\0'){
            //Matar in all data som samlats från raden till korrekt plats

            //Lägger till source till karaktär arrayn om den inte finns där en
            if(-1==SearchArray(source,characters)){
                memcpy(character.name,source,strlen(source)+1);
                memcpy(characters[currentCharacterIndex],source,strlen(source)+1);
                currentCharacterIndex++;
            }
            //Om targetet inte finns i karaktär arrayn så läges den till
            if(-1==SearchArray(target,characters)){
                memcpy(character.name,target,strlen(target)+1);
                memcpy(characters[currentCharacterIndex],target,strlen(target)+1);
                currentCharacterIndex++;
            }

            memcpy(relationship.name,target,strlen(target)+1);
            
            relationship.weight = ConvertStringToInt(weightString,strlen(weightString));
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