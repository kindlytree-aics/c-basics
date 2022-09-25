#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
一个由C/C++编译的程序占用的内存分为以下几个部分
1、栈区（stack）— 由编译器自动分配释放 ，存放函数的参数值，局部变量的值等。其
操作方式类似于数据结构中的栈。
2、堆区（heap） — 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回
收 。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表，呵呵。
3、全局区（静态区）（static）—，全局变量和静态变量的存储是放在一块的，初始化的
全局变量和静态变量在一块区域， 未初始化的全局变量和未初始化的静态变量在相邻的另
一块区域。 - 程序结束后由系统释放。
4、文字常量区 —常量字符串就是放在这里的。 程序结束后由系统释放
5、程序代码区—存放函数体的二进制代码。
*/

void stack_heap_global_const_demo()
{
    int b; //栈,stack,先入后出
    char s[] = "abc"; //栈
    char *p2; //栈
    char const *p3 = "123456"; //123456\0在常量区，p3在栈上。
    static int c =0; // 全局（静态）初始化区
    char* p1 = (char *)malloc(10);
    p2 = (char *)malloc(20);
    //分配得来得10和20字节的区域就在堆区。
    strcpy(p1, "123456\0"); //123456\0放在常量区，编译器可能会将它与p3所指向的"123456"优化成一个地方。
}

void const_demo()
{
    // char *p = "hello";     // 非const指针,
    //                     // 非const数据

    // const char *p = "hello";  // 非const指针,
    //                         // const数据

    // char * const p = "hello";   // const指针,
    //                             // 非const数据

    // const char * const p = "hello";  // const指针,
    //                                 // const数据

    int a = 5;
    const int *p =&a;
    //*p = 20;   //error  不可以通过修改所指向的变量的值

    int b =20;
    p = &b; //right  指针可以指向别的变量        

    int c = 5;
    int *const q = &a;
    *q = 20;     //right 可以修改所指向变量的值

    int d = 10;
    //q = &b;      //error 不可以指向别的变量                              
}

/*
1、int *p; 指向整型的指针变量
2、int **p；指向上方1中的指针变量的指针变量
3、int （*p）[10] 指向具有10个整型元素的一维数组的指针变量
4、int *p[13] 是一个有13个指向整型的指针变量构成的指针数组
5、int* p（）是一个函数，其返回值是指向整型的指针类型。
6、int （*p）(int a, int b) 是一个函数指针变量，其可以指向一个返回值是整型且没有参数的函数。
*/

char const *week_name(int  n)
{
    static char const *name[]={
    "Illegal day",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

    return (n < 1 || n > 7) ? name[0] : name[n];
}

void pointer_demo()
{
    char* p = "hello world others";
    printf("%s\n", p);
    printf("%p\n", p);
    printf("%c\n", *p);
    //printf("%s\n", *p);eror, s is memory address other than char;
    ++p;
    printf("%s\n", p);
    printf("%p\n", p);
    printf("%d\n", *p);
    printf("%p\n", *p);//*p is value, not address. 这句语法能过，但是执行的结果没有实际意义
    printf("%c\n", *p+1);
    printf("%c\n", *(p+1));
    //p[0] = 'H'; error;

    ///p[1]
    //p[0] = 'b';

    char test[] = "hello world\0 others ignored.";
    p = test;
    printf("%s\n", p);
    p[0] = 'H';
    printf("%s\n", p);

    int test_num[] = {1,2,3,4,5};
    int* q = test_num;
    printf("%d", *q);
    printf("%p", q);
    ++q;
    printf("%d", *q);
    printf("%p", q); 
    printf("%d", *q+1);
    //int* q = &test_num[0];
    for(int i =0; i < 5; i++)
    {
        printf("%d,", *q);
        q++;
    }
}

int main()
{
    //const_demo();
    //stack_heap_global_const_demo();
    pointer_demo();
    //pointer
    // int a=10;
    // int* p = &a;
    // int b[10]={0,1,2,3,4,5,6,7,8,9};
    // int* q = &b[0];
    // int (*r)[10] = &b;
    // int **s = &p;

    // printf("%p,%p,%p,%d\n", q, r, *s, **s);
    // printf("%p,%p", ++q, ++r);

    // int num = 1024;
    // int* pi = &num;
    // char* ps = (char*)"FishC";
    // void* pv;

    // pv = pi;
    // printf("pi:%p, pv:%p\n", pi, pv);
    // printf("pv:%d\n", *(int *)pv);

    // pv = ps;
    // printf("ps:%p, pv:%p\n", ps, pv);
    // printf("pv:%c\n", *(char *)pv);
    // printf("pv:%s\n", (char *)pv);
    // return 0;
}