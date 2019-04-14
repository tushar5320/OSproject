
/* ROUND ROBIN SCHEDULING ALGORITHM */


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main()
{
 int ts,pid[10],need[10],waiting_time[10],turnaround_time[10],i,j,n,n1;
 int bt[10],flag[10],total_turnaround_time=0,total_waiting_time=0;
 float average_waiting_time,average_turnaround_time;


 printf("\t\t ROUND ROBIN SCHEDULING"); 
printf("\n\nEnter the number of Processors \n");
 
scanf("%d",&n);

 n1=n;
 
printf("\n Enter the Timeslice \n");
 
scanf("%d",&ts);
 for(i=1;i<=n;i++)

 {
   printf("\n Enter the process ID %d",i);
   
scanf("%d",&pid[i]);
   
printf("\n Enter the Burst Time for the process");
   
scanf("%d",&bt[i]);
   need[i]=bt[i];
 }

 for(i=1;i<=n;i++)
 
{
  flag[i]=1;
  waiting_time[i]=0;
 }
 
while(n!=0)

 {
   for(i=1;i<=n;i++)
   
{
     if(need[i]>=ts)
     
{
       for(j=1;j<=n;j++)
       
{
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  
waiting_time[j]+=ts;
       }
      



       
need[i]-=ts;
      
 if(need[i]==0)
      
 {
	 flag[i]=0;
	 n--;
       }
     }
     
else
    
 {
       for(j=1;j<=n;j++)
      
 {
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  
waiting_time[j]+=need[i];
       }
       
need[i]=0;
       
n--;
       
flag[i]=0;
  
 }
 }
}

for(i=1;i<=n1;i++)

{
  turnaround_time[i]=waiting_time[i]+bt[i]; 
  
total_waiting_time=total_waiting_time+waiting_time[i];
  
total_turnaround_time=total_turnaround_time+turnaround_time[i];

}
system("cls");

average_waiting_time=(float)total_waiting_time/n1;

average_turnaround_time=(float)total_turnaround_time/n1;


printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");

printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");

for(i=1;i<=n1;i++)
{
 printf("\n%8d \t  %4d \t \t %4d \t\t  %4d \t\t  %4d \n", i,pid[i],bt[i],waiting_time[i],turnaround_time[i]);
}


printf("\n The average Waiting Time =%f",average_waiting_time);

printf("\n The average Turn around Time =%f",average_turnaround_time);

}         
