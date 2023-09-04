#include<stdlib.h>
  long  int rev(long int x);
bool isPalindrome(long int x){
    if(x<0)
    return false;
    else
    {
        if(x==rev(x))
        return true;
        else
        return false;
        
    }

}
long int rev(long int x)
{
    long int num=0,r;
    while(x>0)
    {
    r=x%10;
    num=num*10+r;
    x=x/10;
    }
    return num;

}