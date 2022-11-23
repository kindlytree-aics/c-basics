//如何举例说明 C 语言中全局变量和静态全局变量的区别？
//静态全局变量可以被该文件内的所有函数访问，但不能被其它文件内的函数访问。
//全局变量前加static表示该全局变量只允许在本文件中使用，即使其他文件中用extern也不能使用这个变量。
#include<stdio.h>

int a = 10;
static int b = 5;
	
// int main()
// {
//     printf("%d,%d\n", a, b);
//     return 0;
// }