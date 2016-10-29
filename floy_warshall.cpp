#include <iostream>
#define INF 100000

using namespace std;

int main () {
    
    int v = 4;
    
    int grafo[v][v];

    for (int i = 0; i < v; i++) 
        for (int j = 0; j < v; j++) 
            grafo[i][j] = INF;
        
    
    grafo[1][0] = 3;
    grafo[0][1] = -1;
    grafo[0][2] = 5;
    grafo[2][1] = 6;
    grafo[2][3] = -5;
    grafo[0][3] = 1;
    //grafo[3][2] = 3;
        
        
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) { 
            for (int j = 0; j < v; j++) {
                if (grafo[i][j] > grafo[i][k] + grafo[k][j]) {
                    grafo[i][j] = grafo[i][k] + grafo[k][j];
                }     
            }
        }
    }
    
        
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) { 
            cout << grafo[i][j] << " ";
            
        }
        cout << endl;
    }
}