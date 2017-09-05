#include<iostream>
using namespace std;
int main()
{
  float n, sum = 0, sum2=0;
  double m, sum3=0, sum4=0;
  for(n=1;n<=100;n++)
    {
      sum += 1/n;
    }
  for(n=100;n>=1;--n)
    {
      sum2 +=1/n;
    }
  cout << sum << '\n';
  cout << sum2 << '\n';
  cout << sum - sum2 << '\n';

  for(m=1; m<=100; m++)
    {
      sum3 += 1/m;
    }
  for(m=100; m>=1; --m)
    {
      sum4 += 1/m;
    }
  cout << sum3 << '\n';
  cout << sum4 << '\n';
  cout << sum3-sum4 << '\n';
  
  return 0;

}
