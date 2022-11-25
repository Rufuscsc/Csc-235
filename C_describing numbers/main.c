#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Declaring a character array of size 100. */
char number_string[100];
char self_describing = 'T';


int number_array[100];
int count = 0;
int number_of_time;
int trial;

/**
 * The function checks if the number is self-describing by comparing the number of times a digit
 * appears in the number to the digit itself
 * 
 * @param trial the number of digits in the number
 */
void checkforselfdescribing(int trial){
    for (int m = 0; m< trial; m++) {
        for (int i = 0; i< trial; i++) {
            if (number_array[i] == m) count++;
        }
        if(count == number_array[m]){
            self_describing = 'T';
        }
        else{
            self_describing = 'F';
            printf("\n");
            printf("%s   Not self-describing\n", number_string);
            break;
        }
        count = 0;
        if (self_describing == 'T'){
            printf("\n");
            printf("%s   Self-describing\n", number_string);
            break;
        }
    }
}



int main(){
    
    /* Opening a file called self.in.txt in the directory and reading it. */
    FILE * file = fopen("/Users/rufus/Desktop/C project/C_describing_numbers/C_describing numbers/C_describing numbers/self.in.txt", "r");
    
     /* Reading the first line of the file and assigning it to the variable number_of_time. */
     if(fscanf(file, "%d", &number_of_time) != EOF) {
        printf("Enter the number of trials: %d\n", number_of_time);
    }

    /* A for loop that iterates through the number of times the user wants to check if a number is
    self-describing. */
    for (int i = 0; i < number_of_time; i++) {
            fscanf(file, "%s", number_string);
            printf("\nEnter number:  %s\n", number_string);
            printf("\n");
            trial = strlen(number_string);
        
        /* Iterating through the number of digits in the number. */
        for (int j = 0; j < trial; j++) {
            number_array[j] = number_string[j] - '0';
        }
        
        /* Prints out the numbers of a particular number in the array of numbers. */
        for (int j = 0; j < trial; j++) {
            printf("There are %d  %ds in the number \n", number_array[j],j);
        }
        
        
        /* Calling the function checkforselfdescribing and passing the variable trial as an argument. */
        checkforselfdescribing(trial);
        
    }
    fclose(file);
}
