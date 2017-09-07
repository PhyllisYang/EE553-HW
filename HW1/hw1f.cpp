/*   
     Author: Fan Yang
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  float s1 = 0, s2=0, n, m, l;
  cout << "Please enter a number:\n";
  cin >> m;
  for ( n=1; n<=m; n++)
    {
      s1 += 1/(n*n);
    }
  cout << s1 <<'\n';
  cout << "Please enter another number:\n";
  cin >> l;
  for (n=1; n<=l; n++)
    s2 += 1/(n*n);
  cout << s2 <<'\n';

  cout << sqrt(6*s1) << '\n';
  cout << sqrt(6*s2) << '\n';
  
  return 0;

}
