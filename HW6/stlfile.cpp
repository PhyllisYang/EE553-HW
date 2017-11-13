/*
   Author:Fan Yang
   cite: Jiabin Li
    Ask about the method to output a file, and how to construct the cylinder in stl.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
const double Pi = 3.14159265;
class Shape {
public:
    virtual ofstream& draw(ofstream& os) const =0;
};

class Cylinder : public Shape{
private:
    double r, h, x, y, z;
    int facets;
public:
    Cylinder(double x, double y, double z, double r, double h, int facets):x(x),y(y),z(z),r(r),h(h),facets(facets) {}
   virtual ofstream& draw(ofstream& cylinder) const {
       for (int i=0;i<facets;i++)
       {
           cylinder<<"facet normal 0 0 1"<<endl;
           cylinder<<"outer loop"<<endl;
           cylinder<<"vertex"<<" "<<x<<" "<<y<<" "<<z<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos(((2*Pi)/facets)*i)<<" "<<y<<" "<<z+r*sin(((2*Pi)/facets)*i)<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*(i+1))<<" "<<y<<" "<<z+r*sin(((2*Pi)/facets)*(i+1))<<endl;
           cylinder<<"endloop"<<endl;
           cylinder<<"endfacet"<<endl;
           
           cylinder<<"facet normal 0 0 -1"<<endl;
           cylinder<<"outer loop"<<endl;
           cylinder<<"vertex"<<" "<<x<<" "<<y+h<<" "<<z<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*i)<<" "<<y+h<<" "<<z+r*sin((2*Pi)/facets*i)<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*(i+1))<<" "<<y+h<<" "<<z+r*sin((2*Pi)/facets*(i+1))<<endl;
           cylinder<<"endloop"<<endl;
           cylinder<<"endfacet"<<endl;
           
           cylinder<<"facet normal 0 0 0"<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*i)<<" "<<y<<
           " "<<z+r*sin((2*Pi)/facets*i)<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*(i+1))<<" "<<y<<
           " "<<z+r*sin((2*Pi)/facets*(i+1))<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*i)<<" "<<y+h<<
           " "<<z+r*sin((2*Pi)/facets*i)<<endl;
           cylinder<<"endloop"<<endl;
           cylinder<<"endfacet"<<endl;
           
           cylinder<<"facet normal 0 0 0"<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*(i+1))<<" "<<y<<
           " "<<z+r*sin((2*Pi)/facets*(i+1))<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*i)<<" "<<y+h<<
           " "<<z+r*sin((2*Pi)/facets*i)<<endl;
           cylinder<<"vertex"<<" "<<x+r*cos((2*Pi)/facets*(i+1))<<" "<<y+h<<
           " "<<z+r*sin((2*Pi)/facets*(i+1))<<endl;
           cylinder<<"endloop"<<endl;
           cylinder<<"endfacet"<<endl;
       }
       return cylinder;
    }
};

class Cube: public Shape {
private:
    double size;
    double x,y,z;
public:
    Cube(double x, double y, double z, double size) : size(size) {}
    virtual ofstream& draw(ofstream& cube) const {
       // cube.open("/Users/test.txt", fstream::out);
        //cube<<"solid Cube\n";
        for(int i=1;i<=12;i++)
        {
            if(i==1)
            {
                cube<<"facet normal 0 1 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==2)
            {
                cube<<"facet normal 0 1 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==3)
            {
                cube<<"facet normal 0 0 1\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==4)
            {
                cube<<"facet normal 0 0 1\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==5)
            {
                cube<<"facet normal 1 0 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==6)
            {
                cube<<"facet normal 1 0 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==7)
            {
                cube<<"facet normal 0 0 -1\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==8)
            {
                cube<<"facet normal 0 0 -1\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==9)
            {
                cube<<"facet normal 0 -1 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==10)
            {
                cube<<"facet normal 0 -1 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z<<"\n";
                cube<<"vertex "<<x<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==11)
            {
                cube<<"facet normal -1 0 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z<<"\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
            if(i==12)
            {
                cube<<"facet normal -1 0 0\n";
                cube<<"outer loop\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z<<"\n";
                cube<<"vertex "<<x+size<<" "<<y<<" "<<z+size<<"\n";
                cube<<"vertex "<<x+size<<" "<<y+size<<" "<<z+size<<"\n";
                cube<<"endloop\n";
                cube<<"endfacet\n";
            }
        }
        //cube<<"endsolid Cube\n";
        //cube.close();
        return cube;
    }
};



class CAD {
private:
    vector<Shape*> shapes;
public:
    CAD(){};
    ~CAD(){
        for(auto s: shapes)
            delete s;
    }
    void add(Shape* s){
        shapes.push_back(s);
    }
    void write(const string& output)
    {
        ofstream os;
        os.open(output, ios::out);
        os << "solid Shapes" << endl;
        for(auto s: shapes)
        {
            s->draw(os);
        }
        os << "endsolid shape" << endl;
        os.close();
    }
    
};

//https://www.stratasysdirect.com/resources/how-to-prepare-stl-files/
//https://www.viewstl.com/
int main() {
    CAD c;
    c.add(new Cube(0,0,0,   5));
    c.add(new Cylinder(100,0,0,    3, 10, 10));
    c.write("test.stl");
}
