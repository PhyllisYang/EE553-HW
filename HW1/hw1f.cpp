/*   
     Author: Fan Yang
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  float s1 = 0, s2=0, n, m, l;
  cout << "Please enter a number:\n";
  cin >> m;
  for ( n=1; n<=m; n++)
      s1 += 1/(n*n);
  cout << setprecision(7) <<s1 <<'\n';
  cout << "Please enter another number:\n";
  cin >> l;
  for (n=1; n<=l; n++)
    s2 += 1/(n*n);
  cout << setprecision(7) << s2 <<'\n';

  cout << setprecision(7) << sqrt(6*s1) << '\n';
  cout << setprecision(7) << sqrt(6*s2) << '\n';
  
  return 0;

}
/* iterations needed before the contribution of 1/n^2 is too small and no longer matters is 4090 */
