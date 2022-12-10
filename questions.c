#include <stdio.h>
#include <string.h>


//1.c 语言如何输出一个数平方后的各位数字？ https://www.zhihu.com/question/567679461
void convert(int a)
{
    int b = a*a;//b=10000
    char str[20]; 
    int i = 0;
    while(b !=0)
    {
        int c= b%10;
        b = b/10;
        str[i] = c+48;
        i +=1;
    }
    str[i]='\0';
    //00001,逆序,如果需要，可以reverse字符串
    printf("%s", str);
}


//2.问一下这是输出的分别是什么？
//https://www.zhihu.com/question/569218615

// int main()
// {
//     //int a = 100;
//     //convert(a);
//     char a[3] = "cb";
//     int i;
//     printf("%c\n", a);
//     printf("%d\n", a);
//     printf("%p\n", a);
// }


//3、这个程序哪里错了？应该怎么改呢？求求了?
//https://www.zhihu.com/question/568567744
//从小到大顺序排序
// int main()
// {
//     int a[10]={11,99,22,44,55,33,77,66,88,1}, *p,temp;
//     for(int i = 0; i < 9; i++)
//     {
//         p = &a[0];
//         for(int j =0; j < 9-i; j++)
//         {
//             if(*p > *(p+1))
//             {
//                 temp = *p;
//                 *p = *(p+1);
//                 *(p+1)=temp;
//             }
//             p++;
//         }
//     }
//     for(int t = 0; t < 10; t++)
//     {
//         printf("%5d", a[t]);
//     }
//     return 0;
// }

//4、如何用 c 语言输出 fibonacci 数列的前 20 项？
//https://www.zhihu.com/question/569280522
// int main()
// {
//     int fibonacci[20];
//     fibonacci[0] = 1;
//     fibonacci[1] = 1;
//     for(int i = 2; i < 20; i++)
//     {
//         fibonacci[i] = fibonacci[i-1]+fibonacci[i-2];
//     }
//     for(int i = 0; i < 20; i++)
//     {
//         printf("%d:%d, ", i+1, fibonacci[i]);
//     }
// }

//5、c 语言删除数组中的小写字母如何实现？https://www.zhihu.com/question/571569612

int main()
{
    char a[128] = "Hello World, I'm from China";
    int len = strlen(a);
    int cur_idx  = 0, i = 0;
    while(i < len)
    {
        if(a[i] >= 'a' && a[i] <= 'z')//如果碰到小写字母则往后继续找到下一个非小写字符
        {
            i++;
        }else{
            a[cur_idx] = a[i];//否则，将非小写字符的值赋给当前的数组的小标位置，对应的位置往后移动
            i++;
            cur_idx++;
        }
    }
    if(cur_idx < len)
    {
        a[cur_idx] = '\0';//字符串结束符需要人为的设为'\0',后面的字符为无效字符
    }
    printf("%s", a);
}