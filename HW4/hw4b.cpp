/*
  Author: Fan Yang
*/

#include<iostream>
using namespace std;
class Matrix {
    double* m;
    uint32_t rows, cols;
public:
    /* what do we need here???
     // constructor, destructor, copy constructor, operator =
     0  1   2  3
     4  5   6  7
     8  9  10 11
     */
    Matrix(uint32_t r, uint32_t c, double val = 0) :m(new double[r*c]),rows(r),cols(c){
#if 0
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                m[i*c+j]=0;
#endif
        for(int i=0;i<r*c;i++)
            m[i]=val;
    }
    ~Matrix(){
        delete [] m;
    }
    double& operator()(uint32_t i,uint32_t j){
        return m[i*cols+j];
    }
    
    friend Matrix operator + ( Matrix& a,  Matrix& b){
        if (a.rows != b.rows || a.cols != b.cols)
            throw;
        Matrix sum(a.rows,a.cols);
        for(int i=0; i< sum.rows; i++)
        {
            for(int j=0; j< sum.cols; j++)
                sum(i,j)=a(i,j)+b(i,j);
        }
        return sum;
        
            }
    friend Matrix operator - ( Matrix& a,  Matrix& b){
        if (a.rows != b.rows || a.cols != b.cols)
            throw;
        Matrix dis(a.rows,a.cols);
        for(int i=0; i< dis.rows; i++)
        {
            for(int j=0; j< dis.cols; j++)
                dis(i,j)=a(i,j)-b(i,j);
        }
        return dis;
    }
    
    friend Matrix operator * (Matrix& a, Matrix& b){
        if(a.cols!=b.rows)
            throw;
        Matrix product(a.rows, b.cols);
        for (int i=0; i<a.rows;i++){
            for(int j=0; j< b.cols;j++){
                for(int k=0; k<a.cols; k++)
                    product(i,j)+=a(i,k)*b(k,j);
            }
        }
        return product;
    }

   friend ostream& operator << (ostream& s, Matrix& m){
        for(int i=0 ; i<m.rows; i++){
            for(int j=0; j<m.cols;j++){
                if((j+1)%m.cols==0)
                    s<<m(i,j)<<'\n';
                else
                    s<<m(i,j)<<" ";
            }
        }
       return s;
    }
};


int main() {
    Matrix a(3,4, 5.2); // create 3 rows of 4 columns containing 5.2
    Matrix b(3,4); // defaults to 0.0
    cout << a << '\n';
   
    /*
     5.2 5.2 5.2 5.2
     5.2 5.2 5.2 5.2
     5.2 5.2 5.2 5.2
     */
    
    Matrix c(3,4,1.2);
    cout << c(2,2);
    c(0,0) = -1.5;
    cout<<c;
    /*
     c=
     -1.5 1.2 1.2 1.2
     1.2 1.2 1.2 1.2
     1.2 1.2 1.2 1.2
     */
    
    Matrix d = a + c;
    /*
     3.7 6.4 6.4 6.4
     6.4 6.4 6.4 6.4
     6.4 6.4 6.4 6.4
     */
    cout << d;
    Matrix e = a - c;
    
    //optional
    Matrix f(4,3,1.5);
    Matrix g = f * b; // matrix multiplication
    cout << g;
    
}
