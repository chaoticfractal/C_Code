/********************************************************************************************************
This program uses least suqares methods to curve fit a line that approx. a liner
relation of temperature to distance on heated metal rod whos ends are kept fixed at constant temperatures
********************************************************************************************************/



#include <stdio.h>
#include <math.h>

#define data 9						   //number of data points

int main()
{
   int i;
   double s, sx, sy, sxx, sxy, delta, inter, slope;
   double x[data], y[data], d[data];

   for (i=0; i<data; i++) x[i]=i+1;		              

   y[0]=14.6; y[1]=18.5;  y[2]=36.6; y[3]=30.8;            //input data y  
   y[4]=59.2;  y[5]=60.1;   y[6]=62.2;  y[7]=79.4;         //y[9] set to 0.1
   y[8]=99.9;           

   for (i=0; i<data; i++) d[i]=.05;			   //d is input variance
  						
    
   s=sx=sy=sxx=sxy=0;				    	   //Resets the sums		

   for (i=0;i<data;i++)				           //calculating sums
    {
      s   +=         1 / (d[i]*d[i]);
      sx  +=      x[i] / (d[i]*d[i]);
      sy  +=      y[i] / (d[i]*d[i]); 
      sxx += x[i]*x[i] / (d[i]*d[i]); 
      sxy += x[i]*y[i] / (d[i]*d[i]);
    } 

   delta = s*sxx-sx*sx;
   slope=  (s*sxy-sx*sy) / delta;		   	   //calculats the slope, interpolation and delta
   inter=(sxx*sy-sx*sxy) / delta;

   double devi,f,var_sum,var, chi, chi_term;
   var_sum=0;


   for (i=0; i<=data; i++)
    {	
     f=slope*x[i]+inter;                                  //best fit line
     devi=(f-y[i])*(f-y[i]);                              //deviation of fit 
     var_sum=devi+var_sum;                                //Sum of deviation points 
    }

var=var_sum/data;
   for (i=0;i<data;++i)
    {
     f=slope*x[i]+inter; 				   //best fit line
     chi_term=(f-y[i])*(f-y[i])/var/var; 		   //term inside sum
     chi=chi+chi_term; 					   //Performs sum
    }


   printf("intercept=%f\t +/- %f\n", inter, sqrt(sxx/delta) );
   printf("slope=%f\t +/- %f\n", slope, sqrt(s/delta) );
   printf("correlation=%f\n", -sx/sqrt(sxx*s));
   printf("variance=%f\n",var);
   printf("chi-squared=%f\n",chi);

return 0;

}


