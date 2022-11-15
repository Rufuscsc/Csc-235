#include <stdio.h>
#include <string.h>

/**
 * This function takes in a string of characters and returns the number of steps taken before the first
 * step down
 * 
 * @param walks This is the array of characters that the user inputs.
 * 
 * @return the number of steps taken before the first time the character 'D' or 'd' is encountered.
 */
int steppwork(char walks[100]){
    int walk = 0;
    
   
    int n = strlen(walks);
  
    /* This is a for loop that is used to check for u or d. */
    for (int i = 0; i < n; i++)
    {
       
        if (walks[i] == 'U' || walks[i] == 'u'){
        
            walk = i + 1;
        }
       
        else if (walks[i] == 'D' || walks[i] == 'd')
        {
            break;
        }
      
        else{
            printf("\nInvaid input\n\n");
            break;
        }
    }
    return walk;
}


/**
 * This function takes a string as an argument and returns the string with all the lowercase letters
 * replaced with uppercase letters
 * 
 * @param upcase This is the string that we want to convert to uppercase.
 * 
 * @return the value of the string upcase.
 */
char capital(char upcase[100]){

    int n = strlen(upcase);

    /* This is a for loop that is used to check if the  line as u or d store it. */
    for (int i = 0; i < n; i++)
    {
        
        if (upcase[i] == 'U' || upcase[i] == 'u')
        {
             upcase[i]= 'U';
        }
        
      
        else if (upcase[i] == 'D' || upcase[i] == 'd')
        {
            upcase[i] = 'D';
        }
    }
    return printf("\n%s",upcase);
}



/**
 * The function takes in a string of U's and D's and returns the number of steps the child can take
 * before falling
 */
int main(){

    char steps[100][100];
    int name[100];
    int trial;
    
    /* This is opening a file called Adam.in.txt and writing to it. */
    FILE * inputfile = fopen("/Users/rufus/Desktop/Adam project/adam project/adamproject/Adam.in.txt","w");
    /* This is opening a file called Adam.in.txt and reading from it. */
    FILE *file = fopen("/Users/rufus/Desktop/Adam project/adam project/adam project/Adam.in.txt", "r");
    
    
    /* This is checking if the file is empty or not. */
    while(fscanf(file, "%d", &trial) != EOF){
        printf("Numbers of trials: %d", trial);
        printf("\n");
        printf("\nThe number of steps(U or D): \n");
        break;
    }
    
    /* This is checking if the file is empty or not. */
    if (fscanf(file, "%d", &trial) == EOF){
        printf("Numbers of trials: ");
        scanf("%d", &trial);
        printf("\nThe number of steps(U or D): \n");
        for(int i =0; i < trial; i++ ){
            scanf("%s", steps[i]);
            //fprintf(inputfile, "%s", steps[i]);
        }
    }
    //fprintf(inputfile, "%d", trial);
    fclose(inputfile);
    
    /* This is a for loop that is used to check for u or d.  */
    for (int i = 0; i< trial; i++) {
        fscanf(file, "%s", steps[i]);
        name[i] = steppwork(steps[i]);
    }

    fclose(file);
   
    /* This is a for loop that is used to change small letters to capital. */
    for (int i = 0; i < trial; i++)
    {
        printf("%c  %d", capital(steps[i]), name[i]);
    }
    
    
    printf("\n\n");
    
    
    /* This is a for loop that is used to print out the output. */
    for (int i = 0; i< trial; i++) {
        if (name[i] > 0)
        {
            printf("The child took %d steps\n", name[i]);
        }
        
        else if(name[i] <= 0){
            printf("The child could not take any step\n");
        }
        
    }
    printf("\n");
}

