#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/include.h"
#include "../include/teacher.h"
#include "../include/tool.h"
#include "../include/root.h"

//输入学生信息并保存
void input_student_info()
{
	student_t *l = read_student_file();
	student_t *temp = (student_t *)malloc(sizeof(student_t));
	if(temp == NULL)
	{
		printf("开辟空间失败\n");
		return ;
	}
	temp->next = NULL;
	strncpy(temp->data.passwd, "0", MAX_PASSWD_LEN-1);  //学生的初始密码为0
	printf("输入学生id：");
	scanf("%d",&temp->data.id);
	while(getchar()!='\n');
	printf("输入学生姓名：");
	scanf("%s",temp->data.name);
	while(getchar()!='\n');
	printf("输入数学成绩：");
	scanf("%f",&temp->data.math);
	while(getchar()!='\n');
	printf("输入语文成绩：");
	scanf("%f",&temp->data.chinese);
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
	write_student_file(l);
	printf("添加学生成功\n"
			"按回车键继续...\n");
	while(getchar()!='\n');
	return;
}


//写入学生文件
void write_student_file(student_t *l)
{
	if(NULL == l->next)
	{
		printf("没有信息保存\n");
		return ;
	}	
	FILE *fp;
	fp = fopen("student.txt", "w");
	while(l->next != NULL)
	{
	    fwrite(l->next, sizeof(student_t), 1, fp);
		l = l->next;
	}
	fclose(fp);	
	return ;	
}


//读取学生文件
student_t * read_student_file()
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
	free(temp),temp = NULL;
	fclose(fp);
	return l;
		
}

//打印学生信息
void print_student_info(int subject)  //参数为教师职位
{
		student_t *l = read_student_file();
		if(l->next == NULL)
		{
				printf("没有学生信息\n"
						"按回车键继续...\n");
				while(getchar()!='\n');
				return ;
		}
		if(subject == HEAD)
		{
			printf("\t\tid\t\t密码\t\t名字\t\t数学\t\t语文\t\t总成绩\n");
			while(l->next != NULL)
			{
					printf("\t\t%d\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", l->next->data.id, l->next->data.passwd, l->next->data.name, l->next->data.math, l->next->data.chinese, l->next->data.math + l->next->data.chinese);
					l = l->next;
			}
			printf("\n");
			printf("按回车键继续...\n");
			while(getchar()!='\n');
		}
		else if(subject == MATH)
		{
			printf("\t\tid\t\t名字\t\t数学\n");
			while(l->next != NULL)
			{
					printf("\t\t%d\t\t%s\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.math);
					l = l->next;
			}
			printf("\n");
			printf("按回车键继续...\n");
			while(getchar()!='\n');
		}
		else
		{
			printf("\t\tid\t\t名字\t\t语文\n");
			while(l->next != NULL)
			{
					printf("\t\t%d\t\t%s\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.chinese);
					l = l->next;
			}
			printf("\n");
			printf("按回车键继续...\n");
			while(getchar()!='\n');
		}
}



//删除学生信息
void delete_student_info(student *ptr)
{
		student_t *l = read_student_file();
		if(l->next == NULL)
		{
				printf("没有学生信息\n"
						"按回车键继续...\n");
				while(getchar()!='\n');
				return ;
		}
		printf("请输入想要删除学生的id：\n");
		int id = 0;
		scanf("%d",&id);
		while(getchar()!='\n');
		student_t *head = l;
		student_t *p = NULL;
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
				printf("无此id学生\n");	
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
		
   	    write_student_file(head);
}


//按职位更改学生信息
void change_student_info(int subject, student *ptr)
{
		student_t *l = read_student_file();
		if(l->next == NULL)
		{
				printf("没有学生信息\n"
						"按回车键继续...\n");
				while(getchar()!='\n');
				return ;
		}
		printf("请输入想要更改学生的id\n");
		int id = 0;
		scanf("%d",&id);
		while(getchar()!='\n');
		student_t *head = l;  //记录头结点
		while(l->next != NULL)
		{
				if(l->next->data.id == id)
				{	
						break;
				}
				l = l->next;
				
		}
		if(l->next == NULL)
		{
				printf("无此id学生\n"
						"按回车键继续...");
				while(getchar()!='\n');
				return;
		}
		student temp ;
		memset(&temp, 0, sizeof(temp));

		temp.id = id;
	    strncpy(temp.passwd, l->next->data.passwd, MAX_PASSWD_LEN-1); 
		if(subject == HEAD)
		{
				printf("输入id为：%d的学生姓名：", id);
				scanf("%s",temp.name);
				while(getchar()!='\n');
				printf("输入新的数学成绩：");
				scanf("%f",&temp.math);
				while(getchar()!='\n');
				printf("输入新的语文成绩：");
				scanf("%f",&temp.chinese);
				while(getchar()!='\n');
		}
		else if(subject == MATH)
		{
	   		    strncpy(temp.name, l->next->data.name, MAX_NAME_LEN-1); 
				temp.chinese = l->next->data.chinese;
				printf("输入%s新的数学成绩：", l->next->data.name);
				scanf("%f",&temp.math);
				while(getchar()!='\n');
		}
		else
		{
	   		    strncpy(temp.name, l->next->data.name, MAX_NAME_LEN-1); 
				temp.chinese = l->next->data.math;
				printf("输入%s新的语文成绩：", l->next->data.name);
				scanf("%f",&temp.chinese);
				while(getchar()!='\n');
		}

	  	l->next->data = temp;

		printf("修改成功!\n"
				"按回车键继续...\n");
		while(getchar()!='\n');
		if(ptr != NULL)
		{
				*ptr = l->next->data;
		}
		
   	    write_student_file(head);
}

//任课老师排序学生信息 0：数学 1:语文
void print_student_info_from_other(int kind)
{
	student_t *l = read_student_file();
	if(l->next == NULL)
	{
		printf("没有任何信息\n"
				"按回车键继续...\n");
		while(getchar()!='\n');
		return ;
	}
	student_t *p1 = l->next;
	student_t *low = memset(&low, 0, sizeof(low));
	student_t *p2 = memset(&low, 0, sizeof(low));
	student_t *temp=(student_t *)malloc(sizeof(student_t));
	temp->next = NULL;
	
	while(p1 != NULL)
	{
		low = p1;
		p2 = p1->next;
		while(p2 != NULL)
		{
			if(MATH == kind)
			{
					if(low->data.math  > p2->data.math )
					{
						low = p2;
						p2 = p2->next;
					}
					else
					{
						p2 = p2->next;
					}
			}
			else if(CHINESE == kind)
			{
					if(low->data.chinese > p2->data.chinese)
					{
							low = p2;
							p2 = p2->next;
					}
					else
					{
							p2 = p2->next;
					}
			}
			else
			{
					if(low->data.id > p2->data.id)
					{
						low = p2;
						p2 = p2->next;
					}
					else
					{
						p2 = p2->next;
					}
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
	if(MATH == kind)
	{
	    printf("\t\tid\t\t名字\t\t数学\n");
		while(l->next != NULL)
		{
				printf("\t\t%d\t\t%s\t\t%.2f\t\t\n", l->next->data.id, l->next->data.name, l->next->data.math);
					l = l->next;
		}
	}
	if(CHINESE == kind)
	{
	    printf("\t\tid\t\t名字\t\t语文\n");
		while(l->next != NULL)
		{
				printf("\t\t%d\t\t%s\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.chinese);
					l = l->next;
		}
	}
	printf("\n");
	printf("按回车键继续...\n");
	while(getchar()!='\n');
}

//打印学生全部信息 0:按总分排名  其他:按id排名
void print_student_info_from_head(int select)
{
	student_t *l = read_student_file();
	if(l->next == NULL)
	{
		printf("没有任何信息\n"
				"按回车键继续...\n");
		while(getchar()!='\n');
		return ;
	}
	student_t *p1 = l->next;
	student_t *low = memset(&low, 0, sizeof(low));
	student_t *p2 = memset(&low, 0, sizeof(low));
	
	student_t *temp=(student_t *)malloc(sizeof(student_t));
	temp->next = NULL;
	
	while(p1 != NULL)
	{
		low = p1;
		p2 = p1->next;
		while(p2 != NULL)
		{
			if(0 == select)
			{
					if(low->data.math + low->data.chinese > p2->data.math + p2->data.chinese)
					{
						low = p2;
						p2 = p2->next;
					}
					else
					{
						p2 = p2->next;
					}
			}
			else
			{
					if(low->data.id > p2->data.id)
					{
						low = p2;
						p2 = p2->next;
					}
					else
					{
						p2 = p2->next;
					}
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
	    printf("\t\tid\t\t密码\t\t名字\t\t数学\t\t语文\t\t总成绩\n");
		while(l->next != NULL)
		{
					printf("\t\t%d\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", l->next->data.id, l->next->data.passwd, l->next->data.name, l->next->data.math, l->next->data.chinese, l->next->data.math + l->next->data.chinese);
				l = l->next;
		}
		printf("\n");
		printf("按回车键继续...\n");
		while(getchar()!='\n');
}

void change_teacher_passwd()
{
		char check_passwd[MAX_PASSWD_LEN] = {'\0'};
		printf("请输入原来密码（初始密码为123）：");
		my_gets(check_passwd, MAX_PASSWD_LEN);
		teacher_t *l = read_teacher_file();
		teacher_t *head = l;
		while(l->next != NULL)
		{
				if(l->next->data.id == teacher_id)
				{
						break;
				}
				l = l->next;		
		}
		if(strcmp(check_passwd, l->next->data.passwd) != 0)
		{
				printf("密码输入有误！\n"
						"按回车键继续...\n");
				while(getchar()!='\n');
		}
		else
		{
				while(1)
				{
					char re_passwd1[MAX_PASSWD_LEN];
					char re_passwd2[MAX_PASSWD_LEN];

					printf("请输入新密码：");
					my_gets(re_passwd1, MAX_PASSWD_LEN);
					printf("请再次输入：");
					my_gets(re_passwd2, MAX_PASSWD_LEN);
					if(strcmp(re_passwd1, re_passwd2) == 0)
					{
							strncpy(l->next->data.passwd, re_passwd1, MAX_PASSWD_LEN);
							write_teacher_file(head);
							printf("密码修改成功!\n"
									"按回车键继续...\n");
							while(getchar()!='\n');
							break;
					}
					else
					{
							printf("两次密码不一致请重新输入~\n"
										"按回车键继续...\n");
							while(getchar()!='\n');
					}
				}
		}
}





