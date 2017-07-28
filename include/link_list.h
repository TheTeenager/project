#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

// 定义单链表中数据节点数据域的抽象数据类型
// 实现单链表时，尽量与其具体类型无关
//　本代码以int类型作为测试数据类型
typedef int datatype_t;

// 定义单链表数据节点类型
// link_node_t		数据节点类型的别名(struct link_node)
// link_list_t		数据节点的指针类型别名，主要用于标示头指针的类型，用于唯一标识一条单链表，等价于(struct link_node *)或者(link_node_t *)
typedef struct link_node
{
	// 数据域：存放数据部分
	datatype_t data;
	// 指针域：存放后一个数据节点的地址值
	struct link_node *next;
}link_node_t, *link_list_t;

// 创建一个空的带头结点的单链表
link_list_t create_empty_link_list(void);

// 判断单链表是否为空，为空，返回1；否则，0
int is_link_list_empty(link_list_t l);

// 求单链表的毕表长，成功，返回长度(>=0)；失败，返回-1
int length_of_link_list(link_list_t l);

// 遍历打印单链表数据信息
void print_link_list_data_info(link_list_t l);

// 打印输出指定类型的数据结点信息
static void print_data_info(datatype_t x);

// 向单链表中的指定位置插入数据，成功，返回0;失败,-1
// 头结点的pos的值为0
// pos的有效值的范围[1,len+1]
int insert_into_link_list_by_postion(
	link_list_t l,
	int pos,
	datatype_t x
);

// 对指定的单链表按位置进行数据删除，成功，返回0；失败，-1；并通过参数将待删除的数据返回
// 头结点的pos的值为０
// pos的有效范围是[1,len]
int delete_from_link_list_by_postion(
	link_list_t l,
	int pos,
	datatype_t *ptr
);

// 清空单链表
void clear_link_list(link_list_t l);

// 销毁单链表
void destroy_link_list(link_list_t l);

// 单链表逆序
void reverse_link_list(link_list_t l);

#endif
