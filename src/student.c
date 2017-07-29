#include <stdio.h>
#include <string.h>
#include "../include/include.h"
#include "../include/tool.h"
#include "../include/teacher.h"

//打印自己的信息
void print_own_info()
{
		student_t *l = read_student_file();
		while(l->next != NULL)
		{
				if(l->next->data.id == student_id)
				{
						break;
				}
				l = l->next;		
		}
		printf("\t\tid\t\t姓名\t\t数学\t\t语文\t\t总成绩\n");
		printf("\t\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", l->next->data.id, l->next->data.name, l->next->data.math, l->next->data.chinese, l->next->data.math + l->next->data.chinese);
		printf("按回车键继续...\n");
		while(getchar()!='\n');
}




//更改学生密码
void change_student_passwd()
{
		char check_passwd[MAX_PASSWD_LEN] = {'\0'};
		printf("请输入原来密码（初始密码为0）：");
		my_gets(check_passwd, MAX_PASSWD_LEN);
		student_t *l = read_student_file();
		student_t *head = l;
		while(l->next != NULL)
		{
				if(l->next->data.id == student_id)
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
							write_student_file(head);
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







