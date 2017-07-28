#include "../include/link_list.h"
#include <stdlib.h>
#include <stdio.h>

// 创建空的带头结点的单链表
link_list_t create_empty_link_list(void)
{
	// 为头结点分配空间
	link_list_t l = (link_list_t)malloc(sizeof(link_node_t));

	// 进行空的单链表的初始化
	l->next = NULL;

	// 返回头指针
	return l;
}

// 判断单链表是否为空，为空，返回1；否则，0
int is_link_list_empty(link_list_t l)
{
	// 判断头结点的指针域是否为NULL
	return l->next == NULL;
}

// 求单链表的表长，成功，返回长度(>=0)；失败，返回-1
int length_of_link_list(link_list_t l)
{
	if(l == NULL)
		return -1;

	int len = 0;

	// 第一种写法
	while(l->next != NULL)
	{
		// 当前结点存在，长度+1
		len++;

		// 移动指针指向下一个元素
		l = l->next;
	}
#if 0
	// 第二种写法
	l = l->next;
	while(l != NULL)
	{
		len++;
		l = l->next;
	}
#endif
	return len;
}

// 遍历打印单链表数据信息
void print_link_list_data_info(link_list_t l)
{
	if(l == NULL)
		return;

	printf("link_list : ");
	while(l->next != NULL)
	{
		// 打印当前数据结点的信息
		print_data_info(l->next->data);

		l = l->next;
	}
	printf("\n");

	return;
}

// 打印输出指定类型的数据信息
static void print_data_info(datatype_t x)
{
	printf("%d ", x);
}

// 向单链表中的指定位置插入数据，成功，返回0;失败,-1
// 头结点的pos的值为0
// pos的有效值的范围[1,len+1]
int insert_into_link_list_by_postion(link_list_t l, int pos, datatype_t x)
{
	// 验证pos的有效性
	if(pos < 1 || pos > length_of_link_list(l)+1)
		return -1;

	// 移动指针到待插入结点的前一个结点位置
	int i = 0;
	link_node_t *p = NULL;
	for(i = 0; i < pos-1; i++)
		l = l->next;

	// 插入数据
	p = (link_node_t *)malloc(sizeof(link_node_t));
	p->data = x;

	p->next = l->next;
	l->next = p;

	return 0;
}

// 对指定的单链表按位置进行数据删除，成功，返回0；失败，-1；并通过参数将待删除的数据返回
// 头结点的pos的值为０
// pos的有效范围是[1,len]
int delete_from_link_list_by_postion(link_list_t l, int pos, datatype_t *ptr)
{
	// 判空
	if(is_link_list_empty(l))
		return -1;

	// 验证pos的有效性
	if(pos < 1 || pos > length_of_link_list(l))
		return -1;

	// 移动到待删除的结点的前一个结点的位置
	int i = 0;
	link_node_t *p = NULL;
	for(i = 0; i < pos-1; i++)
		l = l->next;

	// 删除结点
	p = l->next;
	l->next = p->next;

	// 根据需要返回删除的数据
	if(ptr != NULL)
		*ptr = p->data;

	free(p), p = NULL;

	return 0;
}

// 清空单链表
void clear_link_list(link_list_t l)
{
	link_node_t *p = NULL;

	while(l->next != NULL)
	{
		p = l->next;
		l->next = p->next;
		free(p);
	}
}

// 销毁单链表
void destroy_link_list(link_list_t l)
{
	clear_link_list(l);

	free(l);
}

// 单链表逆序
void reverse_link_list(link_list_t l)
{
	if(l == NULL || is_link_list_empty(l))
		return;

	// 1.将带头结点的单链表以头结点为界，断开为两条链表
	// 一条为待头结点的空的单链表，记为表１
	// 另一条为不带头结点的有数据的单链表，记为表２
	link_list_t l2 = l->next;
	l->next = NULL;
	link_node_t *p = NULL;

	// 2.循环从表２中取出其第一个元素
	// 以头插法插入到表１中
	// 直到将表２中的所有数据结点去下头插完成
	while(l2 != NULL)
	{
		// 2.1取出表２的首元素
		p = l2;
		l2 = l2->next;

		// 2.2将取出的p指向的结点头插入表１中
		p->next = l->next;
		l->next = p;
	}
}






