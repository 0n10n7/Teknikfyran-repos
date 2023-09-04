#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>

#define NUM_ENTRIES 352

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
int SearchArray(char goal[],char target[][20]){
    // printf("Comparing goal:%s target:%s\n",goal,target[i]);
    for(int i=0; i < NUM_ENTRIES; i++){
        if (0 == strcmp(goal, target[i])){
            return i; 
            
        }
    }
    return -1;
}

typedef struct Relationship
{
    char name[20];
    int weight;
}Relationship;

typedef struct Character
{
    char name[20];
    Relationship relationships[50];
    int relationCount;
}Character;


int main(){
    printf("START\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    char characters[NUM_ENTRIES][20] = { 0 };
    Character structCharacters[NUM_ENTRIES] = { 0 };
    int currentCharacterIndex = -1;
    
    char source[20] = { 0 };
    char target[20] = { 0 };
    char weightString[3]= { 0 };
    int weight = 0;
    char lineChar;
    int index = 0;
    int type = 0; //om type är 0 så är det source som arbetas med, 1 är target och 2 är weight
    puts("Entering While loop");//Debugging
    FILE* fptr = fopen("thrones.csv", "r");
    //Läser in filen rad för rad

    while (fscanf(fptr, "%c", &lineChar) != EOF) {
        // printf("%c",lineChar);//Debugging 
        Character character;
        character.relationCount = 0;
        Relationship relationship;

        if(lineChar=='\n'){
            printf("\n");//Debugging
            //Matar in all data som samlats från raden till korrekt plats

            //Lägger till source till karaktär arrayn om den inte finns där en
            if(-1==SearchArray(source,characters)){
                currentCharacterIndex++;
                memcpy(character.name,source,strlen(source)+1);
                structCharacters[currentCharacterIndex]=character;
                memcpy(characters[currentCharacterIndex],source,strlen(source)+1);
                printf("lägger till s:%s c:%s ca:%s\n",source,character.name,characters[currentCharacterIndex]);
                
            }
            //Om targetet inte finns i karaktär arrayn så läges den till
            if(-1==SearchArray(target,characters)){
                currentCharacterIndex++;
                Character Target;
                memcpy(Target.name,target,strlen(target)+1);
                memcpy(characters[currentCharacterIndex],target,strlen(target)+1);
                structCharacters[currentCharacterIndex]=Target;
                printf("lägger till t:%s c:%s ca:%s\n",target,Target.name,characters[currentCharacterIndex]);
            }
            strcpy(relationship.name,target);
            relationship.weight = ConvertStringToInt(weightString,strlen(weightString));
            
            //Gör loopen redo för nästa rad
            index=-1;
            type=0;
        }

        else if(lineChar==','){
            
            printf("%c",lineChar);//debugging
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
            index=-1;
            type++;
        }
        else if(type==0){//source
            source[index]=lineChar;
            printf("%c",source[index]);
        }
        else if (type==1)//target
        {
            target[index]=lineChar;
            printf("%c",target[index]);
        }
        else if (type==2)//weight
        {
            weightString[index]=lineChar;
            printf("%c",weightString[index]);
        }
        if(currentCharacterIndex==352){
            break;
        }
        index++;
    }
    fclose(fptr);

    puts("While loop finnished");
    for (int i = 0; i < NUM_ENTRIES; i++)
    {
        if(characters[i][0]=='\0'){
            break;
        }
        printf("%s\n",characters[i]);
    }
    while(true){
        char whatToDo;
        scanf("%c",&whatToDo);
        if(whatToDo=='l'){

        }
        if(whatToDo=='r'){

        }
        if(whatToDo=='q'){
            puts("Exiting");
            return 0;
        }   
    }
}