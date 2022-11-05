#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){
    //defined my variables
    int N;
    int i = 1;

    /* Asking the user to enter the N number. */
    /* Printing the string "Hello World" to the screen. */
    printf("Enter the N number: ");
    scanf("%d",&N);

    /* Checking if the value of i is less than or equal to the value of N. */
    while(i<=N){
        printf("%d\n",i);
        i++;
    }
    
    
    
}

