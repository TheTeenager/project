#include <stdio.h>


void write_student_info(student_t *l)
{
	if(NULL == l)
	{
		printf("没有信息保存\n");
		return ;
	}	
	FILE *fp;
	fp = fopen("student.txt","w");
	while(l->next != NULL)
	{
	    fwrite(l->next, sizeof(student_t), 1, fp);
		l = l->next;
	}
	fclose(fp);	
	return ;	
}


student_t * read_file()
{
	FILE *fp = fopen("student.txt","r");
	student_t *temp = (student_t *)malloc(sizeof(student_t));
	student_t *l = (student_t *)malloc(sizeof(student_t));
	l->next = NULL;
	while(fread(temp, sizeof(student_t), 1, fp)>0)
	{
		temp->next = l->next;
		l->next = temp;
		temp = NULL;
		temp = (student_t *)malloc(sizeof(student_t));
	}
	free(temp),temp=NULL;
	fclose(fp);
	return l;
		
}

void addstudent()
{
	student_t *l = readfile();
	student_t *temp = (student_t *)malloc(sizeof(student_t));
	if(temp == NULL)
	{
		printf("fail\n");
		return ;
	}
	temp->next = NULL;
	printf("input student id:");
	scanf("%d",&temp->data.id);
	while(getchar()!='\n');
	printf("input student name:");
	scanf("%s",temp->data.name);
	while(getchar()!='\n');
	printf("input student pwd:");
	scanf("%s",temp->data.pwd);
	while(getchar()!='\n');
	printf("input student math score:");
	scanf("%f",&temp->data.math);
	while(getchar()!='\n');
	printf("input student chinese score:");
	scanf("%f",&temp->data.chinese);
	while(getchar()!='\n');
	
	if(l->next != NULL)
	{
		temp->next=l->next;
	    l->next=temp;
	}
	else
	{
		l->next=temp;
	}
	write_file(l);
	return ;
}


void show()
{
	student_t *l=readfile();
	if(l == NULL)
	{
		printf("no message\n");
		return ;
	}
	while(l->next != NULL)
	{
		printf("%d,%s,%s,%.2f,%.2f\n",l->next->data.id,l->next->data.name,l->next->data.pwd,l->next->data.math,l->next->data.chinese);
		l = l->next;
	}
	printf("\n");
	return ;
}

void sort()
{
	student_t *l = readfile();
	if(l == NULL)
	{
		printf("no message\n");
		return ;
	}
	student_t *p1 = l->next;
	student_t *low;
	student_t *p2;
	
	student_t *temp=(student_t *)malloc(sizeof(student_t));
	temp->next = NULL;
	
	while(p1 != NULL)
	{
		low=p1;
		p2=p1->next;
		while(p2 != NULL)
		{
			if(low->data.math > p2->data.math)
			{
				low = p2;
				p2 = p2->next;
			}
			else
			{
				p2 = p2->next;
			}
		}
		if(low != p1)
		{
			temp->data = low->data;
			low->data = p1->data;
			p1->data = temp->data;
		}	
		p1 = p1->next;
	}
	
	while(l->next != NULL)
	{
		printf("%d,%s,%s,%.2f,%.2f\n",l->next->data.id,l->next->data.name,l->next->data.pwd,l->next->data.math,l->next->data.chinese);
		l = l->next;
	}
	
}


