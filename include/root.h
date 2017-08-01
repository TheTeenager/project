#ifndef __ROOT_H__
#define __ROOT_H__

//输入教师信息
void input_teacher_info();

//写入教师文件
void write_teacher_file(teacher_t *l);

//读取教师文件
teacher_t * read_teacher_file();

//打印教师信息
void print_teacher_info();

//更改教师信息
void change_teacher_info();

//删除教师信息
void delete_teacher_info();




#endif
