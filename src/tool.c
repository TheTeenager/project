#include <stdio.h>
#include <unistd.h>

//接收字符串
void my_gets(char * str, int size)
{
	int i = 0 ;
	for(i = 0 ; i < size -1 ; i++)
	{
		str[i] = getchar();
		if(str[i] == '\n')
		{
			break;
		}
	}
	str[i] = '\0';
	if(i == size -1){
		while(getchar() != '\n');
	}
}


//心型 a调大小
void heart(int size, int time)
{
		 int i,j,n,m;
	     n = (size+1)/2;
		 m = 3*n/4;
	     for(i=m/2;i<n/2;i++)
	  	 {
			  	for(j=0;j<n/2-i;j++)
				{
 			   		 printf("  ");
				}
		      	for(j=0;j<2*i-n/2;j++)
				{
  	 				printf("\33[31m\33[1m**\33[0m");
				}
			    for(j=0;j<2*(n/2-i)-1;j++)
				{
			   		printf("  ");
				}
			    printf(" ");
			    for(j=0;j<2*i-n/2;j++)
				{
	      			printf("\33[31m\33[1m**\33[0m");
				}
	    		printf("\n");
				usleep(time);
		 }
	     for(i=n/2;i>0;i--)
		 {
			    if(i==n/2)
			     {
					    printf(" ");
					    for(j=0;j<4*i-3;j++)
						{
					   		 printf("\33[31m\33[1m*\33[0m");
						}
					    printf("\n");
						usleep(time);
				 }
			     else
			     {  
				      for(j=0;j<n/2-i;j++)
					  {
					   	 printf("  ");
					  }
				      for(j=0;j<4*i-1;j++)
					  {
					   		 printf("\33[31m\33[1m*\33[0m");
					  }
					    printf("\n");
						usleep(time);
			     }
		 }
		 if(n%2==0)
		 {
			   for(j=0;j<n-1;j++)
			   {
					 printf(" ");
			   }
				 printf("\33[31m\33[1m*\33[0m\n");
				 usleep(time);
		 }
		 else
		 {
			    for(j=0;j<n-2;j++)
				{
			    	 printf(" ");
				}
				 printf("\33[31m\33[1m*\33[0m\n");
				 usleep(time);
		 }
}





void three(int size, int time)
{
		int i = 0;
		int j = 0;
		int k = 0;

		for(i=0;i<size;i++)
		{
				for(j=size-i;j>1;j--)
				{
						
						printf(" ");
				}
				
				for(k=0;k<(2*i+1);k++)
				{
						printf("\33[31m\33[1m*\33[0m");
						usleep(time);
				} 
				printf("\n");
		}
}








