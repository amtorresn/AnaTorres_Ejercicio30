#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

using std::cout;
using std::endl;

void solve(string filename);

int main(){
    
    solve("datos.dat");
    return 0;
}

void solve(string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    int m = 100;
    float c = 1.0;
    float dx = 1/m;
    float beta = 0.8;
    
    float u[m+1];
    float u0[m+1];
    float uf[m+1];
    
    float dt = beta*dx/c;
    float T_max = 0.2;
    int n = T_max/dt;
    
    float x = 0;
        
    for(int i = 0; i < m; i++){
        x = i*dx;
        u0[i] = exp(-300*(x-0.12)*(x-0.12));
        uf[i] = exp(-300*(x-0.12-c*T_max)*(x-0.12-c*T_max));
    }
    
    for(int j = 0; j < n+1; j++){
        for(int i = 0; i < m-1; i++){
            u[i+1] = (1-beta*beta)*u0[i+1] - 0.5*beta*(1-beta)*u0[i+2] + (0.5*beta)*(1+beta)*u0[i];
            u[0] = 0;
            u[m-1] = 0;
            u0[i] = u[i];
        }
    }
    
    outfile << " " << endl;
     
  
    outfile.close();
    
}