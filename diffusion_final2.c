#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PI 3.14159265358979323846
int  main( ) 
{
       int n=128,i,j,k,l,q,temp=0;
       float L=1.0, tot_step, t1,sum=0.0,abs_sum=0.0;
       double u[n], dudt[n], u_a[n],err[n],abs_err[n],avg_err=0.0,abs_avg_err=0.0;
       char file_index[5];    
       FILE * pFile;
       FILE * pFile_init;
       FILE * pFile_ana;
       double test,  constant=1.0, t_final=1.0, dt= 0.00001, x, dx,power, ic, u_f, ex;

       dx = (L/n);

       

      /*Initializing 0 to all nodal points */
 
        for (i=0;i<=n;i++)
            {
               u[i]=0.0;
               u_a[i]=0.0;
               dudt[i]=0.0;
               err[i]=0.0;
               abs_err[i]=0.0;
            }


       /*Initial Condition*/       

        for(i=0;i<=n;i++)
         {
           x=i*dx;
           ic=sin(2*PI*x);
           u[i]=ic;
         }
        pFile_init = fopen ("initial","w");                      /*Plotting the Initial Condition*/
        for(k=0;k<=n;k++)
              {
                      x=k*dx;
                      fprintf(pFile_init,"%f \t %lf \n",x,u[k]);
              }
        fclose(pFile_init);

        
       /*Boundary condition*/

        power=pow(dx,2); 
        tot_step=t_final/dt; 
        int time[4]={0,100,500,1000};                            /*Time steps for which plots are to be developed*/
	for(j=0;j<=tot_step;j=j+1)                               /*For each time step*/
          {
            u[0]=u[n];   	                                 /*BC:end points are identical*/
            for(k=0;k<=n;k++)
		{
                    if(k==0)
                       {
                          dudt[k] =constant*((u[1]-u[0])/power);
                       }
                    else if(k==n)
                       {   
                          dudt[k] =constant* ((u[n-1]-u[n])/power);
                       }
                    else
                       {
		           dudt[k]= constant*((u[k+1]-2*u[k]+u[k-1])/power);           /*Central Difference Numerical Scheme*/
                       }                     
		}

		for(k=0;k<=n;k++)
		       {
		         u[k]=u[k]+((dudt[k])*dt);                  /*Diffusion equation with explicit Euler(forward in time) with CD                                                                      scheme */ 
                       }
    
             t1=time[temp];
             if(j==t1)
               {   
                 char new_file[]="test";                      /*Writting file with required  parameters*/
                 sprintf(file_index,"%d",time[temp]);    
                 strcat(new_file,file_index);
                 pFile = fopen (new_file,"w");
                 for(k=0;k<=n;k++)                                 /*Through each nodal points*/
                    {
                      int mode=2;                                  /*Solving Analytical Equation*/
                      ex= -1*pow(mode,2)*pow(PI,2)*(t1*dt);
                      x=k*dx; 
                      u_a[k] = (sin(2*PI*x))*exp(ex);
                      err[k]=(u_a[k]-u[k]);                        /*Computing average error and absolute error*/
                      abs_err[k]=fabs(err[k]);
                      fprintf(pFile,"%f \t %lf \t %lf \t %lf \t %lf \n",x,u[k],u_a[k],err[k],abs_err[k]);
                    }
            
                 for(q=0;q<=n;q++)
                    {
                      sum=sum+err[q];
                      abs_sum=abs_sum+abs_err[q];
                     }
            
                 printf("\n sum is %f",sum);
                 avg_err=(sum/n);
                 abs_avg_err=abs_sum/n;
              printf("\n Average error and Absolute average error at time step %d \t is %lf \t %lf \n",time[temp],avg_err,abs_avg_err); 
                 temp=temp+1;
                 fclose(pFile);
               }
              
          }
              

    return 0;
           
}
	
      

