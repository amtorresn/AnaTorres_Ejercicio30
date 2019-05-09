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
    float dx = 0.01;
    float dt = 0.01;
    float beta = 1.0;
    
    float u[m+1];
    float u0[m+1];
    float u1[m+1];
    
    
    float T_max = 2.0;
    
    float x = 0;
    float t = 0;
        
    for(int i = 0; i < 100; i++){
        u0[i] = 0.05*sin(i*dx*4*M_PI);
        //u[i] = u0[i];
        u1[i] = u0[i];
    }

    
    for (int i = 0; i < 101; i++){
            outfile << u0[i] << " "; 
    }
    outfile << endl;

    while (t < T_max){
        for(int i = 1; i < 100; i++){
            
            u1[i] = u0[i] - beta/4*(u0[i+1]*u0[i+1] - u0[i-1]*u0[i-1]) + (beta*beta/8)*( (u0[i+1] + u0[i])*(u0[i+1]*u0[i+1] - u0[i]*u0[i]) - (u0[i] + u0[i-1])*(u0[i]*u0[i] - u0[i-1]*u0[i-1]) );

            
        }
        for (int i = 0; i < 101; i++){
            outfile << u1[i] << " "; 
            u0[i] = u1[i];
        }
        t = t + dt;
        outfile << endl;
    }

    outfile.close();
    
}