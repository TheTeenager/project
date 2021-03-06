#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/include.h"
#include "../include/teacher.h"
#include "../include/tool.h"
#include "../include/root.h"

//输入学生信息并保存
void input_student_info()
{
	student_t *l = read_student_file();
	student_t *head = l;
	student_t *temp = (student_t *)malloc(sizeof(student_t));
	if(temp == NULL)
	{
		printf("\n\t开辟空间失败\n");
		return ;
	}
	temp->next = NULL;
	strncpy(temp->data.passwd, "0", MAX_PASSWD_LEN-1);  //学生的初始密码为0
	printf("\n\t输入学生id：");
	scanf("%d",&temp->data.id);
	while(getchar()!='\n');
	while(l->next != NULL)
	{
			if(l->next->data.id == temp->data.id)
			{
					printf("\n\t创建失败！此id属于%s同学\n", l->next->data.name);
					printf("\n\t按回车键继续...");
					while(getchar()!='\n');
					return ;
			}
			l = l->next;
	}
	printf("\n\t输入学生姓名：");
	scanf("%s",temp->data.name);
	while(getchar()!='\n');
	printf("\n\t输入数学成绩：");
	scanf("%f",&temp->data.math);
	while(getchar()!='\n');
	printf("\n\t输入语文成绩：");
	scanf("%f",&temp->data.chinese);
	while(getchar()!='\n');
	
	if(head->next != NULL)
	{
		temp->next = head->next;
	    head->next = temp;
	}
	else
	{
		head->next = temp;
	}
	write_student_file(head);
	printf("\n\t添加学生成功  按回车键继续...");
	while(getchar()!='\n');
	return;
}


//写入学生文件
void write_student_file(student_t *l)
{
	if(NULL == l)
	{
		printf("\n\t没有信息保存");
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
				printf("\n\t没有学生信息  按回车键继续...");
				while(getchar()!='\n');
				return ;
		}
		student_t *p1 = l->next;
		student_t *low = memset(&low, 0, sizeof(low));
		student_t *p2 = memset(&low, 0, sizeof(low));
		student_t *temp = (student_t *)malloc(sizeof(student_t));
		temp->next = NULL;
		while(p1 != NULL)
		{
				low = p1;
				p2 = p1->next;
				while(p2 != NULL)
				{
						if(strcmp(low->data.name, p2->data.name)>0)
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
		if(subject == HEAD)
		{
			printf("\n\t\tid\t\t密码\t\t名字\t\t数学\t\t语文\t\t总成绩\n\n");
			while(l->next != NULL)
			{
					printf("\t\t%d\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", l->next->data.id, l->next->data.passwd, l->next->data.name, l->next->data.math, l->next->data.chinese, l->next->data.math + l->next->data.chinese);
					l = l->next;
			}
			printf("\n");
			printf("\n\t按回车键继续...");
			while(getchar()!='\n');
		}
		else if(subject == MATH)
		{
			printf("\n\t\tid\t\t名字\t\t数学\n\n");
			while(l->next != NULL)
			{
					printf("\t\t%d\t\t%s\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.math);
					l = l->next;
			}
			printf("\n");
			printf("\n\t按回车键继续...");
			while(getchar()!='\n');
		}
		else
		{
			printf("\n\t\tid\t\t名字\t\t语文\n\n");
			while(l->next != NULL)
			{
					printf("\t\t%d\t\t%s\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.chinese);
					l = l->next;
			}
			printf("\n");
			printf("\n\t按回车键继续...");
			while(getchar()!='\n');
		}
}



//删除学生信息
void delete_student_info()
{
		student_t *l = read_student_file();
		if(l->next == NULL)
		{
				printf("\n\t\t没有学生信息  按回车键继续...");
				while(getchar()!='\n');
				return ;
		}
		printf("\n\t\t请输入想要删除学生的id：");
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
				printf("\n\t\t无此id学生  按回车键继续...");
				while(getchar()!='\n');
				return;
		}
		printf("\n\t你真的要删除%s同学的信息吗？", l->next->data.name);
		printf("\n\t1.确定  其他键.取消\n\t请输入你的选择：");
		char choose = '\0';
		scanf("%c", &choose);
		while(getchar()!='\n');
		if(choose != '1')
		{
				return ;
		}
		l->next = p->next;
		printf("\n\t\t删除成功! 按回车键继续...");
		while(getchar()!='\n');
		free(p), p = NULL;
		
   	    write_student_file(head);
}


//按职位更改学生信息
void change_student_info(int subject)
{
		student_t *l = read_student_file();
		if(l->next == NULL)
		{
				printf("\n\t\t没有学生信息  按回车键继续...");
				while(getchar()!='\n');
				return ;
		}
		printf("\n\t\t请输入想要更改学生的id：");
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
				printf("\n\t\t无此id学生 按回车键继续...");
				while(getchar()!='\n');
				return;
		}
		student temp ;
		memset(&temp, 0, sizeof(temp));

		temp.id = id;
	    strncpy(temp.passwd, l->next->data.passwd, MAX_PASSWD_LEN-1); 
		if(subject == HEAD)
		{
				printf("\n\t\t输入id为：%d的学生姓名：", id);
				scanf("%s",temp.name);
				while(getchar()!='\n');
				printf("\n\t\t输入新的数学成绩：");
				scanf("%f",&temp.math);
				while(getchar()!='\n');
				printf("\n\t\t输入新的语文成绩：");
				scanf("%f",&temp.chinese);
				while(getchar()!='\n');
		}
		else if(subject == MATH)
		{
	   		    strncpy(temp.name, l->next->data.name, MAX_NAME_LEN-1); 
				temp.chinese = l->next->data.chinese;
				printf("\n\t\t输入%s新的数学成绩：", l->next->data.name);
				scanf("%f",&temp.math);
				while(getchar()!='\n');
		}
		else
		{
	   		    strncpy(temp.name, l->next->data.name, MAX_NAME_LEN-1); 
				temp.chinese = l->next->data.math;
				printf("\n\t\t输入%s新的语文成绩：", l->next->data.name);
				scanf("%f",&temp.chinese);
				while(getchar()!='\n');
		}

	  	l->next->data = temp;

		printf("\n\t\t修改成功! 按回车键继续...");
		while(getchar()!='\n');
		
   	    write_student_file(head);
}

//任课老师排序学生信息 1：数学 2:语文
void print_student_info_from_other(int kind)
{
	student_t *l = read_student_file();
	if(l->next == NULL)
	{
		printf("\n\t\t没有任何信息 按回车键继续...\n");
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
	    printf("\n\t\tid\t\t名字\t\t数学\n");
		while(l->next != NULL)
		{
				printf("\t\t%d\t\t%s\t\t%.2f\t\t\n", l->next->data.id, l->next->data.name, l->next->data.math);
					l = l->next;
		}
	}
	if(CHINESE == kind)
	{
	    printf("\n\t\tid\t\t名字\t\t语文\n");
		while(l->next != NULL)
		{
				printf("\t\t%d\t\t%s\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.chinese);
					l = l->next;
		}
	}
	printf("\n");
	printf("\n\t\t按回车键继续...");
	while(getchar()!='\n');
}

//打印学生全部信息 0:按总分排名  其他:按id排名
void print_student_info_from_head(int select)
{
	student_t *l = read_student_file();
	if(l->next == NULL)
	{
		printf("\n\t\t没有任何信息  按回车键继续...");
		while(getchar()!='\n');
		return ;
	}
	student_t *p1 = l->next;
	student_t *low = memset(&low, 0, sizeof(low));
	student_t *p2 = memset(&low, 0, sizeof(low));
	
	student_t *temp = (student_t *)malloc(sizeof(student_t));
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
	    printf("\n\t\tid\t\t密码\t\t名字\t\t数学\t\t语文\t\t总成绩\n");
		while(l->next != NULL)
		{
					printf("\t\t%d\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", l->next->data.id, l->next->data.passwd, l->next->data.name, l->next->data.math, l->next->data.chinese, l->next->data.math + l->next->data.chinese);
				l = l->next;
		}
		printf("\n");
		printf("\n\t\t按回车键继续...");
		while(getchar()!='\n');
}


//老师改密码
void change_teacher_passwd()
{
		char check_passwd[MAX_PASSWD_LEN] = {'\0'};
		printf("\n\t\t请输入原来的密码（初始密码为123）:");
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
				printf("\n\t\t密码输入有误！按回车键继续...");
				while(getchar()!='\n');
				return ;
		}
		else
		{
					char re_passwd1[MAX_PASSWD_LEN] = {'\0'};
					char re_passwd2[MAX_PASSWD_LEN] = {'\0'};

					printf("\n\t\t请输入新密码：");
					my_gets(re_passwd1, MAX_PASSWD_LEN);
					printf("\n\t\t请再次输入：");
					my_gets(re_passwd2, MAX_PASSWD_LEN);
					if(strcmp(re_passwd1, re_passwd2) == 0)
					{
							strncpy(l->next->data.passwd, re_passwd1, MAX_PASSWD_LEN-1);
							write_teacher_file(head);
							printf("\n\t\t密码修改成功!  按回车键继续...\n");
							while(getchar()!='\n');
							return ;
					}
					else
					{
							printf("\n\t\t两次密码不一致请重新输入 按回车键继续...");
							while(getchar()!='\n');
							return ;
					}
		}
}

//辞职申请
void resign()
{
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
		char choose = '\0';
		printf("\n\t\t你真的要发辞职申请吗？\n\t\t1.确定\n\t\t其他键.取消");
		scanf("%c", &choose);
		while(getchar()!='\n');
		if('1' == choose)
		{
				l->next->data.resign_r = 1;
				write_teacher_file(head);
				printf("\n\t\t辞职请求已发送...请等待管理员审核"
						"\n\t\t按回车键继续...");
				while(getchar()!='\n');
		}
}





