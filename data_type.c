#include <stdio.h>
//#include "sample.h"

//int test();
//基本数据类型
//数组
int main()
{
    //test();
    int a = 1;//整形
    //int A = 2;
    char b = 'a';//字符型
    //char d[] = "ab"; 
    float c = 0.1;//浮点型
    printf("a:%d, b:%d, c:%f\n", a, b, c);

    int d[5] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++)
    {
        printf("%d", d[i]);
    }
    //double d;
    return 0;
}
