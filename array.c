#include <stdio.h>

//数组及初始化
int main()
{
    int num[3] = {0, 1, 2};
    int num_others[] = {0,1,2,3,4};
    num[0] = 10;
    int k = num[0];
    printf("%d,%d,%d\n", num[0], num[1], num[2]);
    printf("%d,%d,%d,%d,%d\n", num_others[0], num_others[1], num_others[2], num_others[3], num_others[4]);
    
    char hello[]="hello\0world";
    printf("hello string value is %s\n", hello);

    int num_ndarray[][3] = {{0,1,2},{3,4,5},{6,7,8}};
    for (int i =0; i < 3; i++)
    {
        for(int k = 0; k < 3; k++)
        {
            printf("num_ndarray[%d][%d]=%d\n",i,k,num_ndarray[i][k]);
        }
    }
    return 0;
}
