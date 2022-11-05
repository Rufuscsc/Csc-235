#include <stdio.h>
#include <math.h>


int main()
{
  
/* Declaring the variables that will be used in the program. */
double a,b,c,d,r,i, root1,root2;



    /* Asking the user to enter a value. */
    printf("Enter a value for a: ");
    scanf("%lf",&a);

    printf("Enter a value for b: ");
    scanf("%lf",&b);

    printf("Enter a value for c: ");
    scanf("%lf",&c);

    /* Calculating the discriminant. */
    d = b*b-(4.*a*c);

    printf("\nThe discriminant is: %.2lf\n", d);


   /* Checking if the discriminant is greater than 0. */
   if(d>0){
    root1 = (-b + sqrt(d) ) / (2.*a);
    root1 = (-b + sqrt(d) ) / (2.*a);
    printf("\n X1 is %.2lf ",root1);
    printf("\n X2 is %.2lf ",root2);
    printf("\n ");

   }

   /**
    * It checks if the value of d is equal to 0.
    */
   else if (d==0){

    /* Assigning the value of root1 to root2. */
    root1 = root2 = -b/(2*a);
    printf("The roots are equal: %lf", root1);
   }

   /**
    * it checks if the value of d is less than 0
    */
   else if (d<0){
    
    /* Calculating the real part of the roots. */
    r=-b/(2*a);

    /* Calculating the imaginary part of the roots. */
    i = sqrt(-d)/ (2*a);
    printf("x1 = %.2lf+%.2lf i and x2 = %.2f-%.2fi \n", r, i, r, i);
   }

    return 0;

}