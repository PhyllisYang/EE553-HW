/*
  Author: Fan Yang
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T[18]={40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40,-45};
    int W[12]={5,10,15,20,25,30,35,40,45,50,55,60};
    int m, n;
    int R[18][12];
    for (n=0 ; n < 12; n++)
    {
        for (m=0 ; m < 18; m++)
        {
            double v = pow (W[n],0.16);
            R[m][n]=35.74 + 0.6215*T[m] - 35.75*v + 0.4275*T[m]*v;
            cout<< R[m][n]<<" ";
            if (m==17)   // Make the table
                cout<<'\n';
        }

    }
    return 0;
    
}

