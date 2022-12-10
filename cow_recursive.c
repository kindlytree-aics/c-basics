/*
一头母牛第四年开始每年生一头母牛，用递归函数计算第n年有多少头牛
*/
int how_many_cows(int n)
{
    if(n <=3)
    {
        return 1;
    }
    else if(n == 4)
    {
       return 2;
    }
    else{
        //第n年的牛总数是去年的牛的数目加上今年新生的牛的数目
        //今年新生的牛的数目是4年前生下的牛的数目，因为4年前生下的牛都可以生崽了
        return how_many_cows(n-1) + how_many_cows(n-4);
    }
}

int main()
{
    int n = 20;
    int howmany = how_many_cows(n);
    return 0;
}