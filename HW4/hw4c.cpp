#include <iostream>
#include <iomanip>
using namespace std;

 class Bitmap {
 private:
 uint32_t* rgba;
 uint32_t rows,cols;
 public:
     Bitmap(uint32_t r, uint32_t c, uint32_t val=0x000000):rgba(new uint32_t[r*c]),rows(r),cols(c){
         for(int y=0;y<rows;y++)
             for(int x=0; x<cols;x++)
                 rgba[y*c+x]=val;
     }
     ~Bitmap(){
         delete [] rgba;
     }
     
     Bitmap& horizLine(uint32_t x1,uint32_t x2,uint32_t y1,uint32_t val){
         for(int i=x1;i<=x2;i++)
             rgba[y1*cols+i]=val;
         return *this;
     }
     Bitmap& vertLine(uint32_t y1,uint32_t y2,uint32_t x1,uint32_t val){
         for(int i=y1;i<=y2;i++)
             rgba[i*cols+x1]=val;
         return *this;
     }
     uint32_t& operator()(uint32_t y,uint32_t x)
     {
         return rgba[y*cols+x];
     }
     
     friend ostream& operator << (ostream& s,Bitmap& a){
         bitset<32> rgb;
         bitset<8> r, g, b;
         for (uint32_t i = 0; i < a.rows; i++) {
             for (uint32_t j = 0; j< a.cols; j++) {
                 rgb = a.rgba[i * a.cols + j];
                 for (size_t k = 0; k < 8; k++) {
                     b[k] = rgb[k];
                     g[k] = rgb[k + 8];
                     r[k] = rgb[k + 16];
                 }
                 if((j+1)%a.cols==0)
                     s<<b.to_ulong() << "," << g.to_ulong() << "," << r.to_ulong()<<'\n';
                 else
                     s << b.to_ulong() << "," << g.to_ulong() << "," << r.to_ulong()<<setw(4);
             }
         }
         return s;
     }
    
 };


 
int main() {
 Bitmap b1(3,5); // rows,cols or y,x (NOT x,y)
 cout << b1;
/*
 r,g,b   rgb = ((r*256 + g)*256 + b
 this is the same as:
 rgb = ((r << 8) + g) << 8) + b
 use setw(4) in iomanip
 0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
 0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
 0,0,0     0,0,0   255,0,255    0,0,0   255,0,0
 */
Bitmap b2(10,20);
 b2.horizLine(3, 15, 0, 0xFF00FF); // go from (3,0) to (15,0) writing color
    cout<<b2;

 b2.vertLine(0, 8, 0, 0x000100);// go from (0,0) to (0,8) writing color
    cout<<b2;
 }
