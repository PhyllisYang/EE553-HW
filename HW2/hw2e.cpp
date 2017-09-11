/*
  Author: Fan Yang
 */
#include<iostream>
#include<cmath>
using namespace std;

unsigned long fact(int a)
{
    unsigned long fact=1;
    for(int i=1; i<=a ; i++)
        fact *= i;
    return fact;

}

unsigned long fact2(int b)
{
    if(b<=0)
        return 1;
    else
        return b*fact2(b-1);
}

int fibo(int c)
{
    int i=1,f1=1,f2=1,f=0;
    for (i=1; i<=c ; i++)
    {
        if(c==1)
            return f1;
        if(c==2)
            return f2;
        else if (i>2)
        {
            f=f1+f2;
            f1=f2;
            f2=f;
        }
    }
    return f;
}

int fibo2(int d)
{
   if (d<=1)
       return d;
    else
        return fibo2(d-1)+fibo2(d-2);

}

double choose(int e, int f)
{
    int h=e-f;
    double g,i,j;
    double k;
    g=fact2(e);
    i=fact2(f);
    j=fact2(h);
    k=g/(i*j);
    return k;
    

}

int main()
{
    cout << fact(5) << ' ' << fact2(5) << '\n';
    cout << fact(15) << ' ' << fact2(15) << '\n';
    cout << fibo(5) << ' ' << fibo2(5) << '\n';
    cout << fibo(13) << ' ' << fibo2(13) << '\n';
    cout << choose(52,6) << '\n';
}
