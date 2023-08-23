#include <stdio.h>
#define NUM_ENTRIES 200


int main(){
    // Open a file in read mode
    int numbers[NUM_ENTRIES] = { 0 };
    
    FILE* fptr = fopen("a.txt", "r");
    int number = 0;
    int finished = 1;
    
    int line = 0;
    while (fscanf(fptr, "%d\n", &number) != EOF) {
        numbers[line] = number;
        line++;
    }
    int sum = 0;
    for (int i = 0; i < NUM_ENTRIES; i++) {
        sum += numbers[i];
    }
    int ans;
    int desiredOutcome;
    for (int i = 0; i < NUM_ENTRIES; i++) {
        desiredOutcome = 2020 - numbers[i];
        for (int j = i; j < NUM_ENTRIES; j++) {
            if(numbers[j]==desiredOutcome){
                ans = numbers[i]*numbers[j];
            }

    }

    }

    float average = sum / NUM_ENTRIES;
    printf("Sum: %d\tAverage: %2f\n", sum, average);
    printf("ans: %d", ans);
    fclose(fptr);
    return 0;
}
 

//returtyp namnetPåFunktionen (input om det finns){
//    
//}

//printf("");
//"text %s text",%s replcament
//%s, sträng
//%d eller %n, nummer
//puts är säkrare om man inte behöver formatering
