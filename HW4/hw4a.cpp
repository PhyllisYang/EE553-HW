/*
  Author: Fan Yang
*/
/*
 friend functions outside look like:
 operator+ (a,b)
 operator -(a)
 */
#include <iostream>
using namespace std;

class Complex{
private:
    double real;
    double image;
public:
    Complex(double r=0, double i=0){
        real=r;
        image=i;
    }

    friend Complex operator +(const Complex& a,const Complex& b);
    friend Complex operator -(const Complex& c);
    friend ostream& operator << (ostream& s,const Complex& d);
};

Complex operator + (const Complex& a,const Complex& b){
    return Complex(a.real+b.real,a.image+b.image);
}

Complex operator -(const Complex&c){
    Complex d;
    d.real=d.real-c.real;
    d.image=d.image-c.image;
    return d;
}

ostream& operator << (ostream& s,const Complex& d){
    s<<d.real<<"+"<<d.image<<"i"<<endl;
    return s;
}

int main() {
    Complex c1(1.5,2.0);
    Complex c2(-1.3); // -1.3 + 0.0i
    Complex c5;  // 0+0i
    Complex c3 = c1 + c2;
    Complex c4 = -c1; // unary operator has only one parameter
    cout << c1 << c3 << c4 << '\n';
}
