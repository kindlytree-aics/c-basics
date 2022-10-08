#include <stdio.h>

void func_call_demo2()
{
    return;
}

int func_call_demo(int a, int b, int c, int d)
{
    // 参数先从寄存器入栈
    // movl	%ecx, 16(%rbp)a,
	// movl	%edx, 24(%rbp)b,
	// movl	%r8d, 32(%rbp)c,
	// movl	%r9d, 40(%rbp)d,
	// movl	$1, -4(%rbp)e,
	// movl	$2, -8(%rbp)f,
	// movq	$3, -16(%rbp)g
    int e, f;
    long long g;
    e = 1;// movl	$1, -4(%rbp)
    f = 2;// movl	$2, -8(%rbp)
    g = 3;// movq	$3, -16(%rbp)
    func_call_demo2();
	// movl	16(%rbp), %edx
	// movl	24(%rbp), %eax
	// addl	%eax, %edx
	// movl	32(%rbp), %eax
	// addl	%eax, %edx
	// movl	40(%rbp), %eax
	// addl	%edx, %eax
	// movl	%eax, -4(%rbp)
	// movl	-4(%rbp), %eax
	// addq	$48, %rsp
	// popq	%rbp    
    e = a + b + c +d;
    return e;
}

int main()
{
    // movl	$0, -4(%rbp)
	// movl	$1, -8(%rbp)
	// movl	-8(%rbp), %eax
	// addl	$4, %eax 函数的处理顺序，从最后一个参数开始，先算出4+g
	// movl	%eax, %r9d 开始参数入寄存器
	// movl	$3, %r8d
	// movl	$2, %edx
	// movl	$1, %ecx
    int f = 0;//movl	$0, -4(%rbp)
    int g = 1;//movl	$1, -8(%rbp)
    //4+g addl $4, %eax
    f = func_call_demo(1,2,3,4+g);
    printf("value: %d\n", f);
    return 0;
}