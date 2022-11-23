#include <vector>
#include<iostream>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int* p = &a[2];
    //int b = *p++;
    //int c = --*p++;
    //int c = --(*(++p));
    //int c = --(*(p++));
    int d = --*++p;
    int e = --*++p;
    //int c = --(*p);
    //int d = --(*(p++));
    //int d = --(*(++p));
    std::cout  << d << e << std::endl;
}