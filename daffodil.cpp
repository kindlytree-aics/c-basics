#include<iostream>


int main()
{
    for(int num=100; num < 1000; num++)
    {
        int a, b, c;
        a = num %10;
        b= num /10 %10;
        c = num/100;
        if(a*a*a +b*b*b+c*c*c == num)
        {
            std::cout << num <<std::endl;
        }
    }
    return 0;
}