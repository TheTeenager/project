#include <stdio.h>

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
void heart()
{
		 int i,j,n,a,m;
		 a = 94;
	     n = (a+1)/2;
		 m = 3*n/4;
	     for(i=m/2;i<n/2;i++)
	  	 {
			  	for(j=0;j<n/2-i;j++)
 			     printf("  ");
		      	for(j=0;j<2*i-n/2;j++)
  	 			 printf("\33[31m\33[1m**\33[0m");
			    for(j=0;j<2*(n/2-i)-1;j++)
			   	 printf("  ");
			     printf(" ");
			    for(j=0;j<2*i-n/2;j++)
	      		 printf("\33[31m\33[1m**\33[0m");
	    		 printf("\n");
		 }
	     for(i=n/2;i>0;i--)
		 {
			    if(i==n/2)
			     {
					    printf(" ");
					    for(j=0;j<4*i-3;j++)
					      printf("\33[31m\33[1m*\33[0m");
					      printf("\n");
				 }
			     else
			     {  
				      for(j=0;j<n/2-i;j++)
					    printf("  ");
				      for(j=0;j<4*i-1;j++)
					    printf("\33[31m\33[1m*\33[0m");
					    printf("\n");
			     }
		 }
		 if(n%2==0)
		 {
			   for(j=0;j<n-1;j++)
				 printf(" ");
				 printf("\33[31m\33[1m*\33[0m\n");
		 }
		 else
		 {
			    for(j=0;j<n-2;j++)
			     printf(" ");
				 printf("\33[31m\33[1m*\33[0m\n");
		 }
}



//菱形 n调大小

void ling()
{
		int i,j,k;
		int m = 0, n = 0;
		n = 20;

		m=2*n+1;

		for(i=0;i<m;i++)
		{
				if(i<n)
				{
					for(j=n-i;j>1;j--)
					{		
							printf(" ");
					}

					for(k=0;k<(2*i+1);k++)
					{
							printf("*");
					}
				}
				else
				{
					for(j=0;j<i-n;j++)
					{
							printf(" ");
					}

					for(k=(2*(m-i)-3);k>0;k--)
					{
							printf("*");
					}
				}
						
		printf("\n");
		}
}



//三角形  n调大小
void  three()
{
		int i,j,k;
		int n;

	
		n = 25;
		for(i=0;i<n;i++)
		{
				for(j=n-i;j>1;j--)
				{
						
						printf(" ");
				}
				
				for(k=0;k<(2*i+1);k++)
				{
						printf("*");
				} 
				printf("\n");
		}
}


