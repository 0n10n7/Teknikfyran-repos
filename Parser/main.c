#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>

#define NUM_ENTRIES 352

typedef struct Relationship
{
    int characterIndex;
    int weight;
} Relationship;

typedef struct Character
{
    Relationship relationships[50];
    int relationCount;
} Character;

//Old and broken
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

//funktion för qsort
int StringCompare(const void *a,const void *b) {
    return (strcmp((char *)a,(char *)b));
}
int RelationshipCompare(const void *a,const void *b){
    Relationship *ra= (Relationship*)a;
    Relationship *rb= (Relationship*)b;
    if(ra->weight>rb->weight){
        return -1;
    }
    else if(ra->weight==rb->weight){
        return 0;
    }
    else if(ra->weight<rb->weight){
        return 1;
    }
}


int main(){
    printf("START\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    char characters[NUM_ENTRIES][20] = { 0 };
    Character structCharacters[NUM_ENTRIES] = { 0 };
    int currentCharacterIndex = -1;
    
    char source[20] = { 0 };
    char target[20] = { 0 };
    char weightString[3]= { 0 };
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
            weightString[index]='\0';
            printf("\n");//Debugging
            //Matar in all data som samlats från raden till korrekt plats

            //Lägger till source till karaktär arrayn om den inte finns där en
            if(-1==SearchArray(source,characters)){
                currentCharacterIndex++;
                structCharacters[currentCharacterIndex]=character;
                memcpy(characters[currentCharacterIndex],source,strlen(source)+1);
            }
            //Om targetet inte finns i karaktär arrayn så läges den till
            if(-1==SearchArray(target,characters)){
                currentCharacterIndex++;
                Character Target;
                memcpy(characters[currentCharacterIndex],target,strlen(target)+1);
                structCharacters[currentCharacterIndex]=Target;
            }
            int indexSource = SearchArray(source,characters);
            int indexTarget = SearchArray(target,characters);
            int weight;
            sscanf(weightString,"%d",&weight);

            //lägger till relationshipet för source
            relationship.characterIndex=indexTarget;
            relationship.weight=weight;
            structCharacters[indexSource].relationships[structCharacters[indexSource].relationCount]=relationship;
            structCharacters[indexSource].relationCount++;

            //lägger till relationshipet för target
            relationship.characterIndex=indexSource;
            relationship.weight=weight;
            structCharacters[indexTarget].relationships[structCharacters[indexTarget].relationCount]=relationship;
            structCharacters[indexTarget].relationCount++;

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

    //Output
    while(true){
        fflush(stdin);
        char whatToDo;
        char sortedCharacters[NUM_ENTRIES][20];
        memcpy(sortedCharacters,characters,NUM_ENTRIES*20);
        puts("\n 'l' to list alphabetically, 'r' to show relations 'q' to exit");
        scanf("%c",&whatToDo);
        if(whatToDo=='l'){
            qsort(sortedCharacters,NUM_ENTRIES,20,StringCompare);
            for (int i = 0; i < NUM_ENTRIES; i++)
                {
                    // if(sortedCharacters[i][0]=='\0'){
                    //     break;
                    // }
                    printf("%s\n",sortedCharacters[i]);
                }
        }
        if(whatToDo=='r'){
            
            char prompt[20];
            puts("Which character (Capital first letter) ");
            scanf("%s",prompt);
            int promptIndex = SearchArray(prompt,characters);
            if(-1!=SearchArray(prompt,characters)){
                qsort(structCharacters[promptIndex].relationships,structCharacters[promptIndex].relationCount,sizeof(Relationship),RelationshipCompare);
                printf("%s Is related to:\n",characters[promptIndex]);
                for (int i = 0; i < structCharacters[promptIndex].relationCount; i++)
                {
                    printf("%s %d\n",characters[structCharacters[promptIndex].relationships[i].characterIndex],structCharacters[promptIndex].relationships[i].weight);
                }
            }
            
        }
        if(whatToDo=='q'){
            puts("Exiting");
            return 0;
        }   
    }
}