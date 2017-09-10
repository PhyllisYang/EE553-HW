/*
  Author: Fan Yang
*/

#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(unsigned long long p)
{
    if(p==1)
    return false;
    unsigned long long n, i;
    i=sqrt(p);
    for(n=2; n<=i ; n++)
    {
        if (p%n==0)
            return false;
    }
    if(n>i)
        return true;
    return 0;
}

int main()
{
    unsigned long long h;
    cout<<"Please enter a number:\n";
    cin>>h;
    if (isPrime(h))
        cout<<"The number is a Prime number.\n";
    else
        cout<<"The number isn't a Prime number.\n";
    return 0;    
}
