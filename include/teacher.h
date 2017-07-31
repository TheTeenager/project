#ifndef __TEACHER_H__
#define __TEACHER_H__

//根据职位输入学生信息
void input_student_info();

//写学生文档
void write_student_file(student_t *l);

//读学生文档
student_t * read_student_file();

//根据职位打印学生信息
void print_student_info(int subject);

//删除学生信息
void delete_student_info(student *l);

//更改学生信息
void change_student_info(int subject, student *l);

//排序学生部分信息 
void print_student_info_from_other(int kind);

//排序学生全部信息
void print_student_info_from_head(int select);

//教师更改密码
void change_teacher_passwd();

//辞职申请
void resign();

#endif 
