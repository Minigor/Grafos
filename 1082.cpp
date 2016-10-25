#include <iostream>
#include <stack>

using namespace std;

int main () {
    
    int n;
    
    scanf("%d", &n);
    
    int v, e;
    
    for (int i = 1; i <= n; ++i) {
        
        printf("Case #%d:", i);
        scanf("%d %d", &v, &e);    
        
        bool grafo[v][v];
        bool visitados[v];
        stack<int> pilha;
        int caminhante = 0;
        
        for (int j = 0; j < v; ++j){
            visitados[j] = false;
            for (int k = 0; k < v; ++k)
                grafo[j][k] = false;
                
        }
        
        while(true) {
            
            if (!visitados[caminhante]) {
                cout << "Estou em " << caminhante << endl;
                visitados[caminhante] = true;
                pilha.push(caminhante);
            }    
        
            bool achou = false;
    		int h;
    		//busca por um vizinho não visitado
    		for (h = 0; h < v; ++h) {
    			if (!grafo[caminhante][h]) {
    				achou = true;
    				break;
    			}
    		}
    		
    		int acabou = true;
    		
        	if (achou) {
    			v = h; // atualiza o "v"
    		} else {
    			// se todos os vizinhos estão vizitados ou não existem vizinhos
    			// remove da pilha
    			pilha.pop();
    
    			if(pilha.empty()) {
    		        for (int aux; aux < v ; ++i) {
    			        if (!visitados[aux]) {
    			              v = aux; 
    			              acabou = false;
    			        }
    			    }  
    			} 
    			
    			//se chegou aqui, é porque pode pegar elemento do topo
    			
    			if (acabou)
    			    break;
    			    
    			v = pilha.top();
    		}
    		
        } 
        
        
    
        
        
        
        
    }
    
}