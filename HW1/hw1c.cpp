#include <iostream>
using namespace std;
int main()
{
  int sum1=0, sum2=0;
  int m=100;
  sum1 = m * ( m + 1 ) / 2;
  for(int n=1; n<=100; n++)
    sum2+=n;
  cout << sum1 << '\n';
  cout << sum2 << '\n';
  return 0;
}
