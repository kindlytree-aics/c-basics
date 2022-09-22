#include <stdio.h>
#include <math.h>

//在屏幕中绘制一个圆形
int main()
{
    int radius = 15;
    for(int i = 0; i <= radius*2; i++)
    {
        int curpoint_idx = 0;
        int last_j = 0;
        for(int j = 0; j <= radius*2; j++)
        {
            float dist_center = sqrt((radius-i)*(radius-i)+(radius-j)*(radius-j));
            float delta = fabs(dist_center - radius);
            if( delta <= 1e-3)
            {
                if (curpoint_idx == 0)
                {
                    printf("\n");
                    curpoint_idx  = 1;
                    //last_j = j;
                }
                for(int n =0; n< (j-last_j)/2; n++)
                {
                    printf(" ");
                }
                printf("*");
                last_j = j;
            }
        }
    }
}


// int main(){
//     double y;
//     int x,m;
//     for(y = 10;y >= -10; y--){
//         //圆的半径为10
//         //计算y对应的列坐标m，2.03是屏幕纵横比调节系数
//         m = 2.03 * sqrt(100-y*y);   //因为屏幕的行距大于列距，不进行调节显示出来的将是椭圆
//         for(x = 1;x < 30-m; x++)
//             printf(" ");  //图形左侧空白控制
//         printf("*"); //左半圆
//         for( ;x < 30+m; x++)
//             printf(" ");//图形空心部分控制
//         printf("*\n");//圆的右侧
//     }
// }