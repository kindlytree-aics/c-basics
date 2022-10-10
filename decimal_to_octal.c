#include <stdio.h>

#define MAXSIZE 100

#define OK 1

#define OVERFLOW -1

#define error 0

typedef struct{

int *base;

int *top;

int size;

}sqstack;



int initstack(sqstack* S,int* a){

S->base = a;
*(S->base) = 0;
if(!S->base)return OVERFLOW;
S->top = S->base;
*S->top = 0;
S->size=MAXSIZE;
return OK;
// S.base=a;//分配一个数组空间

// *S.base=0;

// if(!S.base)

// return (OVERFLOW);

// S.top=S.base+1;

// *S.top=0;

// S.size=MAXSIZE;

// return OK;

}

int Push(sqstack* s,int e){ //入

if(s->top-s->base==s->size){

return error;}

else{

*(s->top)=e;

s->top++;//将e元素压入栈

return OK;

}

}

int pop(sqstack* s,int e){ //删除栈顶元素

if(s->top==s->base)

return error;

e=*--s->top;// 栈顶指针减1，栈顶元素给e;

return OK;

}

void get(sqstack* s){

//取元素
while (s->top!=s->base) {

printf("%d",*--s->top);

}

//return *(s.top-1);//返回栈顶值，指针不变。

}



int main()

{

int E,e,m=1;

int a[MAXSIZE];

sqstack S;
//应该传地址

initstack(&S, a);

printf("输入十进制，转为八进制：");

scanf("%d",&E);

while(m!=0)

{

m=E/8;

e=E%8;

Push(&S, e);

E=m;

}

get(&S);

printf("\n");

return 0;

}