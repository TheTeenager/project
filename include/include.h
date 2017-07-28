#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#define MAX_NAME_LEN 20 //姓名最大长度
#define MAX_PASSWD_LEN 20 //密码最大长度

#define MAX_POSITION_LEN 20 //教师职位最大长度
#define MAX_SUBJECT_LEN 20 //教师科目最大长度
#define MAX_WORD_LEN 50 //教师留言最大长度
#define RESIGN_SUCCEED 1 //辞职成功
#define RESIGN_FAILED 0 //辞职失败

int teacher_id;
int student_id;


//教师类型定义
typedef struct teacher_tpye
{
		int id;
		char passwd[MAX_PASSWD_LEN];
		char name[MAX_NAME_LEN];
		char position[MAX_POSITION_LEN];
		char subject[MAX_SUBJECT_LEN];
		char word[MAX_WORD_LEN];
		int resign;

}teacher;
//教师链表结点
typedef struct teacher_link
{
		teacher data;
		struct teacher_link *next;
}teacher_t;

//学生类型定义
typedef struct student_type
{
		int id;
		char passwd[MAX_PASSWD_LEN];
		char name[MAX_NAME_LEN];
		float math;
		float chinese;
}student;
//学生链表结点
typedef struct student_link
{
		student data;
		struct student_link *next;
}student_t;













#endif
