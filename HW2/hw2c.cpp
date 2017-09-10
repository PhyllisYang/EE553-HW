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

int countPrimes(unsigned long long a, unsigned long long b)
{
    unsigned i;
    int count;
    for (i=a; i<=b ; i++)
    {
        if(isPrime(i))
            count++;
    }
    cout << count << '\n';
    return 0;
}

int main()
{
    unsigned long long n,m;
    cout<<"Please enter two numbers:\n";
    cin>>n;
    cin>>m;
    countPrimes(n,m);
    return 0;
    
    
}


