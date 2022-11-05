#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){
    
    /* Creating a 2D array of 10 rows and 50 columns. */
    char name[100][50];
    int i = 0;

    /* A for loop that is iterating through the array. */
    while(i<10)
        printf("Enter the name: ");
        gets(name[i]);
        i++;
    

    /* A loop that will run until i is less than 2. */
    for(int i = 0; i<10; i++)
        printf("%s\n",name[i]);
     
    
}
