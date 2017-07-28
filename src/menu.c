#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/include.h"
#include "../include/tool.h"
#include "../include/teacher.h"
#include "../include/root.h"
#include "../include/student.h"

extern int teacher_id;

extern int student_id;

//主菜单
void main_menu()
{
		while(1)
		{
				system("clear");
				printf("***********************************************\n");
				printf("欢迎来到系统\n");
				printf("1.管理员登陆\n");
				printf("2.教师登陆\n");
				printf("3.学生登陆\n");
				printf("0.退出\n");
				printf("请输入你的选择：");
				char choose = '\0';
				scanf("%c",&choose);
				while(getchar()!='\n');
				switch(choose)
				{
						case '1':
								//管理员菜单
								root_register_menu();
								break;
						case '2':
								//教师菜单
								teacher_register_menu();
								break;
						case '3':
								//学生菜单
								student_register_menu();
								break;
						case '0':
								//退出
								exit(0);
						default:
								//错误输入
								printf("输入有误！请重新输入...\n"
										"按回车键继续...\n");
								while(getchar()!='\n');
				}
		}
}


//管理员登陆菜单
void root_register_menu()
{
		    system("clear");
			//管理员名称及密码
			char root_name[MAX_NAME_LEN] = "root";
			char root_passwd[MAX_PASSWD_LEN] = "123";

			char check_name[MAX_NAME_LEN];
			char check_passwd[MAX_PASSWD_LEN];
			printf("请输入管理员名称：\n");
			my_gets(check_name, MAX_NAME_LEN);
			printf("请输入管理员密码：\n");
			my_gets(check_passwd, MAX_PASSWD_LEN);
			if(strcmp(check_name, root_name) != 0 || strcmp(check_passwd, root_passwd) != 0)
			{
					printf("名称与密码不符！\n"
							"按回车键继续...\n");
					while(getchar()!='\n');
			}
			else
			{
					//管理员界面
					root_menu();
			}
}
	

void root_menu()
{
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("**********************\n");
				printf("管理员界面\n");
				printf("1.录入教师信息\n"
						"2.修改教师信息\n"
						"3.查看教师信息\n"
						"4.删除教师信息\n"
						"5.注销\n");
				printf("请输入你的选择\n");
				char choose = '\0';
				scanf("%c",&choose);
				while(getchar()!='\n');
				switch(choose)
				{
						case '1':
								//录入教师信息
								input_teacher_info();
								break;
						case '2':
								//修改教师信息
								change_teacher_info();
								break;
						case '3':
								//查看教师信息
								print_teacher_info();
								break;
						case '4':
								//删除教师信息
								delete_teacher_info();
								break;
						case '5':
								//注销登陆（返回上一菜单）
								flag = 0;
								break;
						default:
								//错误输入
								printf("输入有误！请重新输入...\n"
										"按回车键继续...\n");
								while(getchar()!='\n');

				}

		}
}


//教师登陆菜单
void teacher_register_menu()
{
		    system("clear");
			teacher_t *l = read_teacher_file();
			char check_passwd[MAX_PASSWD_LEN];
			printf("请输入教师帐号：\n");
			scanf("%d",&teacher_id);
			while(getchar()!='\n');
			printf("请输入密码：\n");
			my_gets(check_passwd, MAX_PASSWD_LEN);
			if(l->next == NULL)
			{
					printf("没有任何教师记录\n"
							"按回车键继续...\n");
					while(getchar()!='\n');
					return ;
			}
			while(l->next != NULL)
			{
					if(l->next->data.id == teacher_id)
					{
							break;
					}
					l = l->next;
			}
			if(l->next == NULL)
			{
					printf("输入有误！\n"
							"按任意键继续...\n");
					while(getchar()!='\n');
					return ;
			}
			if(strcmp(check_passwd, l->next->data.passwd) == 0)
			{
					//教师界面
					teacher_menu();
			}
			else
			{
					printf("名称与密码不符！\n"
							"按回车键继续..\n");
					while(getchar()!='\n');
			}
}




void teacher_menu()
{
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("**********************\n");
				printf("教师界面\n");
				printf("1.录入学生信息\n"
						"2.查看学生信息\n"
						"3.修改学生信息\n"
						"4.删除学生信息\n"
						"5.查看排名\n"
						"6.修改自己的登陆密码\n"
						"7.辞职\n"
						"8.注销\n");
				printf("请输入你的选择\n");
				char choose = '\0';
				scanf("%c",&choose);
				while(getchar()!='\n');
				switch(choose)
				{
						case '1':
								//录入学生信息
								input_student_info();
								break;
						case '2':
								//查看学生信息
								print_student_info();
								break;
						case '3':
								//更改学生信息
						    	change_student_info(NULL);
								break;
						case '4':
								//删除学生信息
								delete_student_info(NULL);
								break;
						case '5':
								//查看排名
								print_student_info_by_ranking();
								break;
						case '6':
								//修改自己的登陆密码
								change_teacher_passwd();
								break;
						case '7':
								//辞职
								printf("resign\n");
								break;
						case '8':
								//注销登陆（返回上一菜单）
								flag = 0;
								break;
						default:
								//错误输入
								printf("输入有误！请重新输入...\n"
										"按回车键继续...\n");
								while(getchar()!='\n');

				}

		}
}




//学生登陆菜单
void student_register_menu()
{
		    system("clear");
			student_t *l = read_student_file();
			char check_passwd[MAX_PASSWD_LEN];
			printf("请输入学生帐号：\n");
			scanf("%d",&student_id);
			while(getchar()!='\n');
			printf("请输入密码：\n");
			my_gets(check_passwd, MAX_PASSWD_LEN);
			if(l->next == NULL)
			{
					printf("没有任何学生记录\n"
							"按回车键继续...\n");
					while(getchar()!='\n');
					return ;
			}
			while(l->next != NULL)
			{
					if(l->next->data.id == student_id)
					{
							break;
					}
					l = l->next;
			}
			if(l->next == NULL)
			{
					printf("输入有误！\n"
							"按任意键继续...\n");
					while(getchar()!='\n');
					return ;
			}
			if(strcmp(check_passwd, l->next->data.passwd) == 0)
			{
					//学生界面
					student_menu();
			}
			else
			{
					printf("名称与密码不符！\n"
							"按回车键继续..\n");
					while(getchar()!='\n');
			}
}






void student_menu()
{
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("**********************\n");
				printf("学生界面\n");
				printf("1.查看自己信息\n"
						"2.修改密码\n"
						"3.给老师留言\n"
						"4.注销\n");
				printf("请输入你的选择\n");
				char choose = '\0';
				scanf("%c",&choose);
				while(getchar()!='\n');
				switch(choose)
				{
						case '1':
								//查看自己信息
								print_own_info();
								break;
						case '2':
								//修改密码
								change_student_passwd();
								break;
						case '3':
								//给老师留言
								printf("leave_info_to_teacher\n");
								break;
						case '4':
								//注销登陆（返回上一菜单）
								flag = 0;
								break;
						default:
								//错误输入
								printf("输入有误！请重新输入...\n"
										"按回车键继续...\n");
								while(getchar()!='\n');

				}

		}
}



