#include <stdio.h>

/*
1、int *p; 指向整型的指针变量
2、int **p；指向上方1中的指针变量的指针变量
3、int （*p）[10] 指向具有10个整型元素的一维数组的指针变量
4、int *p[13] 是一个有13个指向整型的指针变量构成的指针数组
5、int  *p（）是一个函数，其返回值是指向整型的指针类型。
6、int （*p）() 是一个函数指针变量，其可以指向一个返回值是整型且没有参数的函数。
*/
char *week_name(int  n)
{
    static char *name[]={
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

int main()
{
    //pointer
    int a=10;
    int* p = &a;
    int b[10]={0,1,2,3,4,5,6,7,8,9};
    int* q = &b[0];
    int (*r)[10] = &b;
    int **s = &p;
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d",*r[i]);
    //     //r++;
    // }
    printf("%p,%p,%p,%d\n", q, r, *s, **s);
    printf("%p,%p", ++q, ++r);

    int num = 1024;
    int* pi = &num;
    char* ps = (char*)"FishC";
    void* pv;

    pv = pi;
    printf("pi:%p, pv:%p\n", pi, pv);
    printf("pv:%d\n", *(int *)pv);

    pv = ps;
    printf("ps:%p, pv:%p\n", ps, pv);
    printf("pv:%c\n", *(char *)pv);
    printf("pv:%s\n", (char *)pv);
    return 0;
}