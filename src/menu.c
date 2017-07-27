#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/include.h"
#include "../include/tool.h"

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
								printf("teacher login\n");
								break;
						case '3':
								//学生菜单
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
			root_t root ={"root","123"};

			char check_name[MAX_NAME_LEN];
			char check_passwd[MAX_PASSWD_LEN];
			printf("请输入管理员名称：\n");
			my_gets(check_name, MAX_NAME_LEN);
			printf("请输入管理员密码：\n");
			my_gets(check_passwd, MAX_PASSWD_LEN);
			if(strcmp(check_name, root.name) != 0 || strcmp(check_passwd, root.passwd) != 0)
			{
					printf("名称与密码不符！\n"
							"按回车键继续..\n");
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
				printf("1.教师信息录入\n"
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
								printf("input_teacher_info\n");
								break;
						case '2':
								//修改教师信息
								printf("change_teacher_info\n");
								break;
						case '3':
								//查看教师信息
								printf("print_teacher_info\n");
								break;
						case '4':
								//删除教师信息
								printf("delete_teacher_info\n");
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






















