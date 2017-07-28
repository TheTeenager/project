#ifndef __TEACHER_H__
#define __TEACHER_H__

//输入学生信息
void input_student_info();

//写学生文档
void write_student_file(student_t *l);

//读学生文档
student_t * read_student_file();

//打印学生信息
void print_student_info();

//删除学生信息
void delete_student_info(student *l);

//更改学生信息
void change_student_info(student *l);

//按数学成绩排序
void print_student_info_by_ranking();

//教师更改密码
void change_teacher_passwd();



#endif 
