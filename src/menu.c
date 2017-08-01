#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
				printf("\n\n\n\n");
				printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
				printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n");
				printf("\t\t|                                                                |\n");
				printf("\t\t|                                                                |\n");
				printf("\t\t|\t\t\t\33[32m1.管理员登录\t\t\t\t\33[30m |\n");
				printf("\t\t|                                                                |\n");
				printf("\t\t|\t\t\t\33[36m2.教师用户登录 \t\t\t\t\33[30m |\n");
				printf("\t\t|                                                                |\n");
				printf("\t\t|\t\t\t\33[35m3.学生用户登录\t\t\t\t\33[30m |\n");
				printf("\t\t|                                                                |\n");
				printf("\t\t|\t\t\t\33[31m0.退出\33[0m\t\t\t\t\t\33[30m |\n");
				printf("\t\t|                                                                |\n");
				printf("\t\t——————————————————————————————————————————————————————————————————\n\n\n\n\n\n\33[0m");
				heart();
				printf("\33[33A\t请输入你的选择：\33[?25h");
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
								printf("\n\t\t输入有误！请重新输入 按回车键继续...");
								while(getchar()!='\n');
				}
		}
}


//管理员登录菜单
void root_register_menu()
{
		    system("clear");
			printf("\n\n\n\n");
			printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n\n");
			printf("\t\t\t\t\t\33[32m管理员登录界面\n\n\n\n\n\n\n\n\n\n\n\33[0m");
			heart();
			//管理员名称及密码
			char root_name[MAX_NAME_LEN] = "root";
			char root_passwd[MAX_PASSWD_LEN] = "123";
			char check_name[MAX_NAME_LEN] = {"\0"};
			char check_passwd[MAX_PASSWD_LEN] = {"\0"};
			char *p = check_passwd;
			printf("\33[37A\t请输入管理员名称：");
			my_gets(check_name, MAX_NAME_LEN);
			p = getpass("\n\t请输入管理员密码：");
			while(getchar()!='\n');
			if(strcmp(check_name, root_name) != 0 || strcmp(p, root_passwd) != 0)
			{
					printf("\n\t\t名称与密码不符！按回车键继续...");
					while(getchar()!='\n');
			}
			else
			{
					int flag = 0;
					teacher_t *l = read_teacher_file();
					while(l->next != NULL)
					{
						if(l->next->data.resign_r == 1)//有待处理信息
							{
								flag = 1;
								break;
							}
						l = l->next;
					}	
				if(0 == flag)
				{
					//管理员界面
					root_menu();
				}
				else
				{
					//辞职界面
					resign_menu();
				}
			}
}

//辞职界面
void resign_menu()
{
		teacher_t *l = read_teacher_file();
		teacher_t *head = l;
		while(l->next != NULL)
		{
				if(l->next->data.resign_r == 1)
					{
						break;
					}
				l = l->next;
		}	
		while(1)
		{
			system("clear");
			printf("\n\n\n\n");
			printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
			printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n\33[0m");
			char choose = '\0';
			printf("\33[31m\t\t\t\t\t辞职申请界面\n\n\n"
					"\t\t工号为\33[31m%d\33[34m的\33[31m%s\33[34m老师提出辞职申请...\n\n", l->next->data.id, l->next->data.name);
			printf("\n\t\t是否同意该申请\n\n");
			printf("\t\t\33[36m  1.同意  \33[35m2.驳回  \33[0m\n\n");
			printf("\t\t请输入你的选择");
			scanf("%c", &choose);
			while(getchar()!='\n');
			if ('1' == choose)
			{
					l->next->data.resign = 1;
					l->next->data.resign_r = 2;  //已同意该申请
					write_teacher_file(head);
					printf("\n\t\t已同意\33[31m%s\33[0m老师的申请！ ", l->next->data.name);
					printf("\t\t按回车键继续...");
					while(getchar()!='\n');
					break;
			}
			else if('2' == choose)
			{
					l->next->data.resign_r = 3;   //已拒绝该申请
					write_teacher_file(head);
					printf("\n\t\t已驳回\33[31m%s\33[0m老师的申请！ ", l->next->data.name);
					printf("\t\t按回车键继续...");
					while(getchar()!='\n');
					break;
			}
			else
			{
					printf("\n\t\t输入有误！请重新输入 按回车键继续...");
					while(getchar()!='\n');
					system("clear");
			}
		}
		root_menu();
}

	
//管理员菜单
void root_menu()
{
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("\n\n\n\n");
				printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
				printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n");
				printf("\33[32m\t\t\t\t\t管理员界面\n\n");
				printf("\33[36m\t\t\t\t1.录入教师信息\n\n"
						"\33[35m\t\t\t\t2.修改教师信息\n\n"
						"\33[34m\t\t\t\t3.查看教师信息\n\n"
						"\33[32m\t\t\t\t4.删除教师信息\n\n"
						"\33[31m\t\t\t\t5.注销\33[0m\n\n\n\n");
				printf("\t请输入你的选择：");
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
								delete_teacher_info(NULL);
								break;
						case '5':
								//注销登陆（返回上一菜单）
								flag = 0;
								break;
						default:
								//错误输入
								printf("\n\t\t输入有误！请重新输入 按回车键继续...");
								while(getchar()!='\n');

				}

		}
}


//教师登录菜单
void teacher_register_menu()
{
		    system("clear");
			printf("\n\n\n\n");
			printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n\n");
			printf("\33[36m\t\t\t\t\t教师登录界面\33[0m\n\n\n\n\n\n\n\n\n\n\n");
			heart();
			teacher_t *l = read_teacher_file();
			char check_passwd[MAX_PASSWD_LEN];
			printf("\33[37A\t请输入教师帐号：");
			scanf("%d",&teacher_id);
			char *p = check_passwd;
			p = getpass("\n\t请输入密码：");
			while(getchar()!='\n');
			if(l->next == NULL)
			{
					printf("\n\t\t没有任何教师记录,按回车键继续...");
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
					printf("\n\t\t输入有误！按回车键继续...");
					while(getchar()!='\n');
					return ;
			}
			if(strcmp(p, l->next->data.passwd) == 0)
			{
					if(0 == l->next->data.resign_r)
					{
							if (l->next->data.subject == HEAD)
								{
										head_teacher_menu();  //班主任界面
								}
							else
								{
										other_teacher_menu();  //任课老师界面
								}
					}
					else
					{
							massage_menu();  //消息菜单
					}
			}
			else
			{
					printf("\n\t\t名称与密码不符！按回车键继续..");
					while(getchar()!='\n');
			}
}

//消息界面
void massage_menu()
{
		system("clear");
		printf("\n\n\n\n");
		printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
		printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n");
		printf("\33[36m\t\t\t\t\t消息界面\n\n\n");
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
		printf("\33[34m\t\t尊敬的\33[31m%s\33[34m老师：\n\n", l->next->data.name);
		switch(l->next->data.resign_r)
		{
				case 2:
					printf("\t\t    您好，非常感谢您这些年来对学校辛勤付出，您的辞职申请校方已经同意。\n\n"
						   "\t\t这將是您最后一次登陆教务，祝您在以后的生活中身体健康，工作顺利。\n\n"
						   "                                                        ————江苏大学教务处\n\n");
					break;
				case 3:
					printf("\t\t    您好，您的辞职申请校方已经收到，教务处经过慎重考虑，未能批准您的申请。\n\n"
						   "\t\t学生们希望继续得到您的教诲，祝您身体健康，工作顺利。\n\n"
						   "                                                            ————江苏大学教务处\n\n");
					l->next->data.resign_r = 0;
					write_teacher_file(head);
					break;
				case 1:
					printf("\t\t    您好，管理员繁忙，暂时未查看您的辞职申请，请耐心等待...\n\n");
					break;
		}
		printf("\n\t\t按回车键继续...\n\n\n\n\n\33[?25l\33[0m");
		three();
		while(getchar()!='\n');
		if(l->next->data.subject == HEAD)
		{
				head_teacher_menu();  //班主任界面
		}
		else
		{
				other_teacher_menu();  //任课老师界面
		}
}


//班主任界面
void head_teacher_menu()
{
		teacher_t *l = read_teacher_file();
		while(l->next != NULL)
		{
				if(l->next->data.id == teacher_id)
				{
						break;
				}
				l = l->next;
		}
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("\n\n\n\n");
				printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
				printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n");
				printf("\33[36m\t\t\t\t\t班主任界面\n\n");
				printf("\33[34m\t\t\t\t欢迎班主任：\33[31m%s\33[34m的登录使用！\n\n", l->next->data.name);
				printf("\33[35m\t\t\t\t1.录入学生信息\n\n"
						"\33[32m\t\t\t\t2.查看学生信息\n\n"
						"\33[36m\t\t\t\t3.修改学生信息\n\n"
						"\33[34m\t\t\t\t4.删除学生信息\n\n"
						"\33[35m\t\t\t\t5.查看信息按id升序\n\n"
						"\33[36m\t\t\t\t6.查看信息按总分升序\n\n"
						"\33[32m\t\t\t\t7.修改自己的登陆密码\n\n"
						"\33[34m\t\t\t\t8.辞职\n\n"
						"\33[31m\t\t\t\t9.注销\n\n\n"
				        "\33[35m\t\t\t\tw.查看学生留言\33[0m\n\n\n");
				printf("\t请输入你的选择：");
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
								print_student_info(l->next->data.subject);
								break;
						case '3':
								//更改学生信息
						    	change_student_info(l->next->data.subject, NULL);
								break;
						case '4':
								//删除学生信息
								delete_student_info(NULL);
								break;
						case '5':
								//查看信息按id升序
								print_student_info_from_head(1);
								break;
						case '6':
								//查看信息按总成绩升序
								print_student_info_from_head(0);
								break;
						case '7':
								//修改自己的登陆密码
								change_teacher_passwd();
								break;
						case '8':
								//辞职
								resign();
								break;
						case '9':
								//注销登陆（返回上一菜单）
								flag = 0;
								if(l->next->data.resign_r == 2)
								{
										myexit(); //删除自己
								}
								break;
						case 'w':
								//查看学生留言
								printf("\t\t学生对你说：\33[31m%s\n\33[0m", l->next->data.word);
								printf("按回车键继续...");
								while(getchar()!='\n');
								break;
						default:
								//错误输入
								printf("\t\t输入有误！请重新输入  按回车键继续...");
								while(getchar()!='\n');

				}

		}
}

//删除自己
void myexit()
{
		teacher_t *l = read_teacher_file();
		teacher_t *head = l;
		teacher_t *p = NULL;
		while(l->next != NULL)
		{
				if(l->next->data.id == teacher_id)
				{
						p = l->next;
						break;
				}
				l = l->next;
		}
		system("clear");
		printf("\n\n\n\n");
		printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
		printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\33[0m\n");
		printf("\33[34m\t\t\t\t\t消息界面\n\n\n");
		printf("\t\t尊敬的\33[31m%s\33[34m老师：\n\n", l->next->data.name);
		printf("\t\t    您好，这是最后一次登陆江苏大学教务系统，对您的离职我们非常痛心。\n\n"
			   "\t\t望您以后身体健康，工作顺利。\n\n"
			   "\t\t                                                  ————江苏大学教务处\n\n");
		printf("\t按回车键继续...\33[0m");
		while(getchar()!='\n');
		l->next = p->next;
		free(p), p = NULL;
		write_teacher_file(head);
}		


//任课老师界面
void other_teacher_menu()
{
		teacher_t *l = read_teacher_file();
		while(l->next != NULL)
		{
				if(l->next->data.id == teacher_id)
				{
						break;
				}
				l = l->next;
		}
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("\n\n\n\n");
				printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
				printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n");
				printf("\33[36m\t\t\t\t\t任课教师界面\n\n");
				printf("\33[34m\t\t\t\t欢迎任课教师：\33[31m%s\33[34m的登录使用！\n\n", l->next->data.name);
				printf("\33[35m\t\t\t\t1.录入学生信息\n\n"
						"\33[32m\t\t\t\t2.修改学生科目信息\n\n"
						"\33[34m\t\t\t\t3.查看学生科目成绩排名\n\n"
						"\33[36m\t\t\t\t4.修改自己的登陆密码\n\n"
						"\33[35m\t\t\t\t5.辞职\n\n"
						"\33[31m\t\t\t\t6.注销\n\n\n"
						"\33[36m\t\t\t\tw.查看学生留言\33[0m\n\n");
				printf("\t\t请输入你的选择\n");
				char choose = '\0';
				scanf("%c",&choose);
				while(getchar()!='\n');
				switch(choose)
				{
						case '1':
								//查看学生信息
								print_student_info(l->next->data.subject);
								break;
						case '2':
								//更改学生科目信息
						    	change_student_info(l->next->data.subject, NULL);
								break;
						case '3':
								//查看数学成绩排名
								print_student_info_from_other(l->next->data.subject);
								break;
						case '4':
								//修改自己的登陆密码
								change_teacher_passwd();
								break;
						case '5':
								//辞职
								resign();
								break;
						case '6':
								//注销登陆（返回上一菜单）
								flag = 0;
								break;
						case 'w':
								//查看学生留言
								printf("\n\t\t学生对你说：%s", l->next->data.word);
								printf("  按回车键继续...");
								while(getchar()!='\n');
								break;
						default:
								//错误输入
								printf("\n\t\t输入有误！请重新输入  按回车键继续...");
								while(getchar()!='\n');
				}

		}
}


//学生登录菜单
void student_register_menu()
{
		    system("clear");
			printf("\n\n\n\n");
			printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n\n");
			printf("\33[35m\t\t\t\t\t学生登录界面\n\n\n\n\n\n\n\n\n\n\n\33[0m");
			heart();
			student_t *l = read_student_file();
			char check_passwd[MAX_PASSWD_LEN];
			printf("\33[37A\t请输入学生帐号：");
			scanf("%d",&student_id);
			while(getchar()!='\n');
			char *p = check_passwd;
			p = getpass("\n\t请输入密码：");
			while(getchar()!='\n');
			if(l->next == NULL)
			{
					printf("\n\t\t没有任何学生记录  按回车键继续...\n");
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
					printf("\n\t\t输入有误！按任意键继续...");
					while(getchar()!='\n');
					return ;
			}
			if(strcmp(p, l->next->data.passwd) == 0)
			{
					//学生界面
					student_menu();
			}
			else
			{
					printf("\n\t\t名称与密码不符！按回车键继续..");
					while(getchar()!='\n');
			}
}


//学生菜单
void student_menu()
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
		int flag = 1;
		while(flag)
		{
				system("clear");
				printf("\n\n\n\n");
				printf("\33[34m\t\t\t\t欢迎来到江苏大学教务系统！\n");
				printf("\33[30m\t\t——————————————————————————————————————————————————————————————————\n");
				printf("\33[35m\t\t\t\t\t学生界面\n\n");
				printf("\33[34m\t\t\t\t欢迎\33[31m%s\33[34m同学的登录使用！\n\n", l->next->data.name);
				printf("\33[36m\t\t\t\t1.查看自己的信息\n\n"
						"\33[34m\t\t\t\t2.修改密码\n\n"
						"\33[32m\t\t\t\t3.给老师留言\n\n"
						"\33[31m\t\t\t\t4.注销\33[0m\n\n\n\n");
				printf("\t\t请输入你的选择：");
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
								leave_info_to_teacher();
								break;
						case '4':
								//注销登陆（返回上一菜单）
								flag = 0;
								break;
						default:
								//错误输入
								printf("\n\t\t输入有误！请重新输入  按回车键继续...");
								while(getchar()!='\n');

				}

		}
}



