#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareable = 0;
int number_file;
int t = 0;
int lowest_value = 0;
char name_of_file[100][50];
int file_id[100];


void checkforcomporpatability(void);
/**
 * It checks for the compatibility of the files and sorts them in ascending order
 */
void checkforcomporpatability(void){
    for (int j = 0; j< number_file; j++) {
        for (int i = j + 1; i < number_file; i++) {
            compareable = strcmp(name_of_file[j], name_of_file[i]);
            if((strcmp(name_of_file[j], name_of_file[i]) == 0) &&  (file_id[j] > file_id[i])){
                
                lowest_value = file_id[i];
            }
            else if((strcmp(name_of_file[j], name_of_file[i]) != 0) && (file_id[j] > file_id[i])){
                t = file_id[j];
                file_id[j] = file_id[i];
                file_id[i] = t;
            }
        }
    }
}


int main(){
    int trials;
    
    /* Opening a file called duplicate.txt in the read mode. */
    FILE * file = fopen("/Users/rufus/Desktop/Duplicates/Duplicate files/Duplicate files/duplicate.txt", "r");

    while(fscanf(file, "%d", &trials) != EOF){
        printf("Numbers of trials: %d", trials);
        printf("\n\n");
        break;
    }

    /* A for loop that is used to iterate through the number of trials. */
    for (int i = 0; i< trials; i++) {

        /* Reading the number of files from the file. */
        fscanf(file, "%d",&number_file);
        printf("Number of files: %d", number_file);

        int j = 0;
       
        /* A while loop that is used to iterate through the number of files. */
        while (j<number_file) {
            fscanf(file,"%s %d", name_of_file[j], &file_id[j]);
            printf("\n%s %d", name_of_file[j], file_id[j]);
            j++;
        }
        printf("\n");
        printf("\n");
        /* Calling the function checkforcomporpatability() */
        checkforcomporpatability();
        for (int j = 0; j< number_file; j++) {
            if (compareable != 0){
                printf("%d ", file_id[j]);
            }
        }
        printf("\n");
        /* Checking if the files are the same. */
        if (compareable == 0){
            printf("%d\n", lowest_value);
        }
    }
    fclose(file);
}

