/**********************************************************************************************************************
This is a program calculates the numerical integral of exp(-x) via Trapiziod, Simpson's and Bode's Rules of Integration
***********************************************************************************************************************/


# include <stdio.h>
# include <math.h>
             
float Trapz(int N); //Accepts the number of segments N as input, spits out the intergral of the fuction exp(-x) over N segments
float Simpson(int N);//Same thing except for simpsons rule
float Bode(int N);//same thing except for bode's rule
float Fi(int i,float h);// evaluates the function exp(-x) at the required values to perform integration


 int b=1; int a=0;// endpoint and starting point respectively for integration                                                                                                     
int main()
{
	int N=4; //Number of segments
	float c=0; float d=0; float e=0;
	int UP=4e4; //max number of segments
	FILE* fo;
	fo=fopen("single_percision.txt","w");
	for (N=4;N<=UP;N+=4)
	{
	c=Trapz(N);
	d=Simpson(N);
	e=Bode(N);
	//printf("%4d   %E    %E    %E\n",N,c,d,e);
	fprintf(fo,"%5d   %E    %E    %E\n",N,c,d,e);
	}
	fclose(fo);
	return 0;
}

//Trapiziod Rule

float Trapz(int N)
{
	float h; //length of segment
	int i=0; //loop index
	float f0; //value found in Numerical C recipes
	float f1;// same as above
	float trapz_ans=0; //answer of trapz integration for N segments
	h=(b-a)/((float)N); //length of integration segment
	for (i=0;i<=N-1;++i)
	{
		f0=Fi(i,h);
		f1=Fi(1+i,h);
		trapz_ans+=h*.5*(f0+f1);
	}
	return trapz_ans;
}

//Simpson's Rule
float Simpson(int N)
{
    float h; //length of segment
	int i=0;
	float f0=0;
	float f1=0;
	float f2=0;
	float simp_ans=0; //answer of simpson's integration for N segments
	h=(b-a)/((float)N);
	for (i=0;i<=N-2;i=i+2)
	{
		f0=Fi(i,h);
		f1=Fi(i+1,h);
		f2=Fi(i+2,h);
		simp_ans+=h/3*(f0+4*f1+f2);

	}
	return simp_ans;
}

//Bode's Rule
float Bode(int N)
{
    float h; //length of segment
	int i=0;
	float f0=0; float f1=0;float f2=0;float f3=0;float f4=0;
	float bode_ans=0; //answer of bodes's integration for N segments
	h=(b-a)/((float)N);
	for (i=0;i<=N-4;i=i+4)
	{
		f0=Fi(i,h);
		f1=Fi(i+1,h);
		f2=Fi(i+2,h);
		f3=Fi(i+3,h);
		f4=Fi(i+4,h);
		bode_ans+=h/45*(14*f0+64*f1+24*f2+64*f3+14*f4);
	}
	return bode_ans;
}

float Fi(int i,float h)
{
	return exp(-(float)a-(float)i*h);
}



