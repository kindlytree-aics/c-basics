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

    // 数据结构（尤其是栈）应该尽可能地在自然边界上对齐。
    //原因在于，为了访问未对齐的内存，处理器需要作两次内存访问；
    //而对齐的内存访问仅需要一次访问。
    //结构体的内存对齐是拿空间来换取时间的做法
    //既然这样，那在设计结构体的时候，我们既要满足对齐，又要节省空间，
    //如何做到：让占用空间小的成员尽量集中在一起
    //#pragma pack(8)//设置默认对齐数为8
    //https://zhuanlan.zhihu.com/p/83449008
    typedef struct size1
    {
       //char n;
       //int age;
       //double score;
       int         a;//占用4字节，不用考虑填充
       char        b; //占用2字节，考虑下面是2字节，所以自己填充1个字节；
       short       c;  //占用2字节，考虑下面要8字节，所以填充6个字节
       double     e;  //占用8字节
       //总体未4+2+2+8=16；
       //to be update;
    }size1;

    Student student1, student2;
    size1 size_1;

    //struct结构内存对齐
    //struct
    //{
    //    int         a；//占用4字节，不用考虑填充
    //    char        b; //占用2字节，考虑下面是2字节，所以自己填充1个字节；
    //    short       c;  //占用2字节，考虑下面要8字节，所以填充6个字节
    //    double     e;  //占用8字节
    //}

    //student1.name[32] = "张三";
    //sprintf函数，将字符串打印到字符数组里
    sprintf(student1.name, "%s", "张三");
    student1.age = 19;
    student1.score = 90.5;

    printf("Memory size occupied by data : %d\n", sizeof(student1));
    printf("Memory size occupied by size_1 : %d\n", sizeof(size_1));

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