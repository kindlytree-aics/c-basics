#include <stdio.h>


int main()
{
    // int height;
    // int gender;
    // printf("input specific height value");
    // scanf("%d",&height);
    // if(height > 180){
    //     printf("the person height is very high"); 
    // }else if(height > 170){
    //     printf("the person height is medium");
    // }else{
    //     printf("the person height is a little short");
    // }
    //switch case
    int a;
    printf("please input specific integer value < 10 and value >0 \n");
    scanf("%d", &a);
    switch(a){
        case 1:
        {
            printf("condition 1 is satisfied\n");
            break;
        }
        case 2:
        {
            printf("condition 2 is satisfied\n");
            break;
        }
        default:
        {
            printf("other conditions not 1 and 2 are satisfied\n");
            break;           
        }
    }
    return 0;
}