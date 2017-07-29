#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/include.h"
#include "../include/root.h"

//输入教师信息并保存
void input_teacher_info()
{
	teacher_t *l = read_teacher_file();
	teacher_t *temp = (teacher_t *)malloc(sizeof(teacher_t));
	if(temp == NULL)
	{
		printf("开辟空间失败\n");
		return ;
	}
	temp->next = NULL;
	strncpy(temp->data.passwd, "123", MAX_PASSWD_LEN-1);  //教师默认密码123
	temp->data.resign = 0;  //默认教师未辞职
	printf("输入教师工号：");
	scanf("%d",&temp->data.id);
	while(getchar()!='\n');
	printf("输入教师姓名：");
	scanf("%s",temp->data.name);
	while(getchar()!='\n');
	printf("输入教师教学科目(0.班主任 1.数学教师 2.语文教师)：");
	scanf("%d", &temp->data.subject);
	while(getchar()!='\n');
	
	if(l->next != NULL)
	{
		temp->next = l->next;
	    l->next = temp;
	}
	else
	{
		l->next = temp;
	}
	write_teacher_file(l);
	printf("添加教师成功\n"
			"按回车键继续...\n");
	while(getchar()!='\n');
	return;
}


//写入教师文件
void write_teacher_file(teacher_t *l)
{
	if(NULL == l->next)
	{
		printf("没有信息保存\n");
		return ;
	}	
	FILE *fp;
	fp = fopen("teacher.txt", "w");
	while(l->next != NULL)
	{
	    fwrite(l->next, sizeof(teacher_t), 1, fp);
		l = l->next;
	}
	fclose(fp);	
	return ;	
}


//读取教师文件
teacher_t * read_teacher_file()
{
	FILE *fp = fopen("teacher.txt","r");
	teacher_t *temp = (teacher_t *)malloc(sizeof(teacher_t));
	teacher_t *l = (teacher_t *)malloc(sizeof(teacher_t));
	l->next = NULL;
	while(fread(temp, sizeof(teacher_t), 1, fp)>0)
	{
		temp->next = l->next;
		l->next = temp;
		temp = NULL;
		temp = (teacher_t *)malloc(sizeof(teacher_t));
	}
	free(temp),temp = NULL;
	fclose(fp);
	return l;
		
}


//打印教师信息
void print_teacher_info()
{
		teacher_t *l = read_teacher_file();
		if(l->next == NULL)
		{
				printf("没有教师信息\n"
						"按回车键继续...\n");
				while(getchar()!='\n');
				return ;
		}
		printf("\t\t注释：科目中 0.班主任，1.数学教师，2.语文教师\n"
						"\t\t教工号\t\t密码\t\t名字\t\t科目\t\t辞职否\n");
		while(l->next != NULL)
		{
				printf("\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n", l->next->data.id, l->next->data.passwd, l->next->data.name, l->next->data.subject, l->next->data.resign);
				l = l->next;
		}
		printf("\n");
		printf("按回车键继续...\n");
		while(getchar()!='\n');
}



void delete_teacher_info(teacher *ptr)
{

		teacher_t *l = read_teacher_file();
		if(l->next == NULL)
		{
				printf("没有教师信息\n"
						"按回车键继续...\n");
				while(getchar()!='\n');
				return ;
		}
		printf("请输入想要删除教师的工号：\n");
		int id = 0;
		scanf("%d",&id);
		while(getchar()!='\n');
		teacher_t *head = l;
		teacher_t *p = NULL;
		while(l->next != NULL)
		{
				if(l->next->data.id == id)
				{
						p = l->next;
						break;
				}
				l = l->next;
				
		}
		if(p == NULL)
		{
				printf("无此工号的老师\n");	
				printf("按回车键继续...\n");
				while(getchar()!='\n');
				return;
		}
		l->next = p->next;
		printf("删除成功!\n"
				"按回车键继续...\n");
		while(getchar()!='\n');
		if(ptr != NULL)
		{
				*ptr = p->data;
		}
		free(p), p = NULL;
		
   	    write_teacher_file(head);
}



void change_teacher_info(teacher *ptr)
{
		teacher_t *l = read_teacher_file();
		if(l->next == NULL)
		{
				printf("没有教师信息\n"
						"按回车键继续\n");
				while(getchar()!='\n');
				return ;
		}
		printf("请输入想要更改教师的工号\n");
		int id = 0;
		scanf("%d",&id);
		while(getchar()!='\n');
		teacher_t *head = l;  //记录头结点
		teacher_t *p = NULL;
		while(l->next != NULL)
		{
				if(l->next->data.id == id)
				{
						p = l->next;
						break;
				}
				l = l->next;
				
		}
		if(p == NULL)
		{
				printf("无此工号的老师\n"
						"按回车键继续...");
				while(getchar()!='\n');
				return;
		}
		teacher temp ;
		memset(&temp, 0, sizeof(temp));

		temp.id = id;
    	strncpy(temp.passwd,  l->next->data.passwd, MAX_PASSWD_LEN-1);
		printf("输入新的教师姓名：");
		scanf("%s",temp.name);
		while(getchar()!='\n');
		printf("输入新的教师教学科目(0.班主任 1.数学教师 2.语文教师)：");
		scanf("%d", &temp.subject);
		while(getchar()!='\n');
		printf("输入辞职是否成功（1.成功 0.失败）：");
		scanf("%d", &temp.resign);
		while(getchar()!='\n');

	  	l->next->data = temp;

		printf("修改成功!\n"
				"按回车键继续...\n");
		while(getchar()!='\n');
		if(ptr != NULL)
		{
				*ptr = p->data;
		}
		
   	    write_teacher_file(head);
}


