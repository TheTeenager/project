#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#define MAX_NAME_LEN 20
#define MAX_PASSWD_LEN 20

//管理员信息
typedef struct roottype
{
		char name[MAX_NAME_LEN];
		char passwd[MAX_PASSWD_LEN];
		
}root_t;


#endif
