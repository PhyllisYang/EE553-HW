/*
  Author: Fan Yang
  cite: Jiabin Li 
  I've got the method of using functions inside the class, and some logic in the class from her.
*/



#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <sstream>

using namespace std;

const char LIVE = '*'; //life cells
const char DEAD = ' '; //dead cells
const int ROWS = 10;
const int COLS = 10;

class GameOLife
{
private:
    int L[ROWS+2][COLS+2];
    int generation;
    int frequency;
    void read(string filename)
    {
        string line;
        ifstream myfile(filename);
        
        // first line contains generations and frequency
        getline(myfile,line);
        istringstream l1(line);
        l1 >> generation;
        l1 >> frequency;
        
        // initial the matrix
        for(size_t i=1; i<=ROWS; i++){
            getline(myfile, line);
            for(size_t j=1; j<=COLS; j++ ){
                if (line[j-1]==LIVE)
                    L[i][j] = 1;
                else
                    L[i][j] = 0;
            }
        }
        for(size_t i=0; i<= ROWS + 1 ; i++){
            L[0][i] = 0;
            L[i][0] = 0;
            L[ROWS + 1][i]=0;
            L[i][COLS + 1]=0;
        }
        myfile.close();
    }
    
public:
    GameOLife(string filename)
    {
        read(filename);
    }
    
    void controlPrint(){
        for(int g = 0; g <= generation; g++){
            if(g % frequency == 0){
                cout << "genetation = " << g << endl;
                print();
                cout << endl;
            }
            update();
        }
    }
  void updateNeighbour(size_t i, size_t j, int (&neighbour)[ROWS+2][COLS+2]){
        neighbour[i][j]=L[i-1][j-1]+L[i-1][j]+L[i-1][j+1]+L[i][j-1]+L[i][j+1]+L[i+1][j-1]+L[i+1][j]+L[i+1][j+1];
    }
    
    void update(){
        int neighbour[ROWS+2][COLS+2]={};
        for (size_t i = 1; i <= ROWS; i++) {
            for (size_t j = 1; j <= COLS; j++) {
                    updateNeighbour(i, j, neighbour);
            }
        }
        
        for (size_t i = 1; i <= ROWS; i++) {
            for (size_t j = 1; j <= COLS; j++) {
	      if ((L[i][j] == 1 && neighbour[i][j] == 2 )|| neighbour[i][j] == 3)
                    L[i][j] = 1;
                else
                    L[i][j] = 0;
            }
        }
    }
    void print() const {
        for (size_t i = 1; i <= ROWS; i++) {
            for (size_t j = 1; j <= COLS; j++) {
                if (L[i][j] == 1) {
                    cout << LIVE;
                } else {
                    cout << DEAD;
                }
            }
            cout << endl;
        }
    }
};
int main() {
    GameOLife gol("hw3b.dat");
    gol.controlPrint();
    return 0;
}
