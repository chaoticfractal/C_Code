/************************************************************************************************************
This program adds up 4 sums to show the accurancy of adding large sums on a computer
The last sums are actually the same sum but added two differnet ways one from the lowest index and one from the 
highest
The purpose of this program was to show the round off error that occurs when adding larges sums two differnet
way
*************************************************************************************************************/


//Homework 4 

#include<stdio.h>
#include<math.h> 


int choose; 

int main()
{ 
	printf("Please choose 1,2,3,4 or 5. 1 for Sum 1, 2 for Sum 2, 3 for Sum 3 4 for Up and 5 for Down.\n"); 
	scanf("%d", &choose); 


	if (choose==1)
	{
	 	float n, sum1;
		FILE* f0=NULL;
		f0=fopen("Homework4_0.txt", "w");	 	
		
		for (n=1; n<=1000000; n++)
		{
	        	sum1+=n/(n+1)*pow (-1, n);
			sum1+=(n+1)/(n+2)*pow (-1, n+1);
			fprintf(f0,"%e \n",sum1);
			n++;
		}
		fclose(f0);

	}
	if (choose==2)
	{
	       	float sum2,sum3,sums,n;
		FILE* f1=NULL;
		f1=fopen("Homework4_1.txt", "w");

	 	for (n=1; n<=1000000; n++)
	 	{
	       		sum2+=((2*n)-1)/(2*n);
			sum3+=(2*n)/((2*n)+1);
			sums=(-sum2+sum3);
	 		fprintf(f1,"%e \n",sums);
		}
		fclose(f1);

	}	
	if (choose==3)
	{
		float sum4,n;
		FILE* f2=NULL;
		f2=fopen("Homework4_2.txt", "w");	

		for (n=1; n<=1000000; n++) 
		{
			sum4+=1/((2*n)*((2*n)+1));
			fprintf(f2, "%e \n",sum4);
		}
		fclose(f2);

	}
	if (choose==4)
	{
		float sum5,n;	
		FILE* f3=NULL;
		f3=fopen("Homework4_up.txt", "w");		

		for (n=1; n<=1000000; n++)
		{
			sum5+=1/n;
			fprintf(f3, "%e \n", sum5);		
		}
		fclose(f3);

	}
	if (choose==5)
	{
		float sum6,n;
		FILE* f4=NULL;
		f4=fopen("Homework4_down.txt", "w");

		for(n=1000000; n>=1; n--)
		{
			sum6+=1/n;
			fprintf(f4, "%e \n", sum6);
		}
		fclose(f4);
	}

return 0;
}
