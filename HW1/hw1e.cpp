#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
  int n;
  uint64_t m=1;
  cout << "Please put in a number:\n";
  cin >> n ;
  for(int i=n; i>=1; --i)
    m = m * i;
  cout << m << '\n';
  return 0;

}
