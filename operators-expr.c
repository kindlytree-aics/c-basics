#include <stdio.h>

int main()
{
    int a = 1, b=2, c=3, d=4;

    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    a = b +c;
    b = d-c ;
    c = 2*7;
    d= 10/2;

    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    //%
    a = 10%2;
    b = 10%3;
    c = 10%4;
    d = 10%5;
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);


    // ++,--, ++i, i++, --i, i--, i += 1(i=i+1)
    int i = 10;
    int i_pp = i++;
    int pp_i = ++i;
    int ss_i = --i;
    int i_ss = i--;

    // > < >= <=, ==, !=
    if ( 3 > 2){
        printf(" 3 > 2 is True\n");
    }

    //&& || !  and or not
    if ((3 > 2) && (2 < 6)){
        printf("3 > 2 && 2 < 6 is True");
    }

    // if (false){
    // } True, False, true, false;
    if(!0){
        printf("!0 is True");
    }

    //int a, b;


    a = 3 > 2 ? 1+3 : 2+5;

    if (3 > 2){
        a = 1+3;
    }
    else{
        a = 2+5;
    }

    printf("a=%d\n", a);
    return 0;
}