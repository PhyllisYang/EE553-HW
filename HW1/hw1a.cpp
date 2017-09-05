#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Put in a number:\n";
  cin >> n;
  while(n!=1)
  {
    if(n!=0 && n%2==1)
      {
        n = 3 * n + 1;
	cout << n << " ";
      }
    else
      {
	n = n / 2;
	cout << n << " ";
      }
  }
  cout<<"\n";
  return 0;

}
