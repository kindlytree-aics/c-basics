#include <stdio.h>

int main()
{
    //结构体定义
    typedef struct student
    {
        char name[32];
        int age;
        float score;
    }Student;

    Student student1, student2;

    //student1.name[32] = "张三";
    //sprintf函数，将字符串打印到字符数组里
    sprintf(student1.name, "%s", "张三");
    student1.age = 19;
    student1.score = 90.5;

    printf("Memory size occupied by data : %d\n", sizeof(student1));

    // printf("%s,%d,%f\n", student1.name, student1.age, student1.score);
    //联合体定义
    typedef union data
    {
        int i ;
        float f;
        char str[20]; 
    }Data;

    Data data1;
    printf("Memory size occupied by data : %d\n", sizeof(data1));
    data1.i = 10;
    printf("data1.i:%d\n", data1.i);
    data1.f = 100.5;
    printf("data1.f:%f\n", data1.f);
    sprintf(data1.str, "%s", "hello world");
    printf("data1.str:%s\n", data1.str);
    return 0;
}