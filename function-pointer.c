
/*
一、指针函数与函数指针
指针函数，指的是返回值为指针的函数。eg：int *getmax（int a,int b） return p;

函数指针，指的是存放函数入口参数的指针变量。 eg： int (*p)(int a,int b) p=getmax;

int func(int x); // 声明一个函数 

int (*f) (int x); // 声明一个函数指针 

int *func（int a,int b）// 声明一个指针函数 

f=func; // 将func函数的首地址赋给指针f 

或者使用下面的方法将函数地址赋给函数指针：

f = &func;
*/

#include<stdio.h>

int get_substraction(int a ,int b)
{
    return a - b;
}

int get_multiplication(int a ,int b)
{
    return a *b;
}

int get_avg(int a ,int b)
{
    int avg = (a +b)/2;
    return avg;
}

int get_sum(int a , int b)
{
    return a+b;
}

//func_ptr即为函数指针变量
int (*func_ptr)(int a, int b);

//FUNC_PTR为函数指针类型，该类型为返回值为int型，参数为两个int型的函数指针
typedef int (*FUNC_PTR)(int a, int b);

int cal_func(int a, int b, char op)
{
    FUNC_PTR fp = NULL;
    switch(op)
    {
        case '+':
        {
            // fp = &get_sum;
            //func_ptr = get_sum
            fp = get_sum;
            break;
        }
        case '-':
        {
            fp =  get_substraction;
            //fp =  &get_substraction;
            break;
        }
        case '*':
        {
            //fp= &get_multiplication;
            fp= get_multiplication;
            break;

        }
    }
    if(fp != NULL)
    {
        return fp(a, b);
        //return (*fp)(a, b);
    }
    return -1;
}

int main()
{
    int a = 100, b=1000;
    printf("%d+%d=%d\n", a, b, cal_func(a, b, '+'));
    printf("%d-%d=%d\n", a, b, cal_func(a, b, '-'));
    printf("%d*%d=%d\n", a, b, cal_func(a, b, '*'));
}

