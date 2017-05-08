/****************************************************************************************
This program calculates the power series of e^x with a relative error
smaller than a predetermined tolerance
It uses a system function call in Unix to time how long the program works
The "bad" algorithim is where the previous term is not used and recreated
The unix system call was used to time the difference in the calculations
****************************************************************************************/

#include<stdio.h>
#include<math.h> 
#include<time.h>


#define min 1E-10                      	    /* limit for accuracy */
#define max 100                            /* maximum for x */
#define step 0.1                          /* interval */

int choose;
float error;
clock_t start, end;
double elapsed; 


int main()
{
 printf("Please 1 or 2. 1 for good algorithim and 2 for bad algorithim\n");
 scanf("%d", &choose);
  if (choose==1)
   {
    double x, sum, element;				 
    int n;					 
    FILE* fo=NULL;
    fo=fopen("Homework3.txt", "w");
    start=clock();  			
     for (x=0.0; x<=max; x+=step)
      {
       sum = element = 1.;   //Reset Variable                
       n = 0;                 
        for (n=0; n<=11000000; n++) //This is so we can get the program to run for at least 30 secs.
	 {                                    
          n++; 
          element *= -x/n;   //Calculates next element       
          sum += element;
      	 }
     error=fabs(sum-exp(-x))/exp(-x);
     end=clock();
     elapsed = ((double) (end - start));
     fprintf(fo, " x= %f sum= %e error= %e elapsed= %e \n", x,sum,error,elapsed);
      }
   }
		 		 
  if (choose==2) 
   { 
    double sum1, x1, up, down; 				 
    int i,j,k;
    printf ("%d", choose);
    FILE* fo_1=NULL;
    fo_1=fopen("Homework3_Bad.txt", "w");	
    start=clock();
     for (x1=0.0; x1<=max; x1+=step)		 
      {
       sum1 = 1;				 
       i = 0;
      	for (k=0; k<=2000; k++) //This is the same case here.                                
      	 {				
          i++;
          up = down = 1;                  
      	   for(j=1; j<=i; j++)
      	    {
             up *= -x1;                  
             down *= j;                  
            }
      	sum1 += up/down;
      	 }
     error=fabs((sum1-exp(-x1))/exp(-x1));
     end=clock();
     elapsed = ((double) (end - start));      		
     fprintf(fo_1, "x= %f  sum= %e  error= %e elapsed= %e \n", x1, sum1, error, elapsed);   
      }
   }				 

return 0;

}	 
	




