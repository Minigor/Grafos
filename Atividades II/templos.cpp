#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

int main () {

	int t, cont = 0, n, m, x, y;

	scanf("%d", &t);

	while (cont < t) {

		scanf("%d %d", &n, &m);

		list<int> grafo[n];
		bool guardas[n];
		int total_guardas = 0;

		for (int i = 0; i < n; ++i)
			guardas[i] = false;
		
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			grafo[x-1].push_back(y-1);
		}
			
		int v = 0;

		while (true) {
		
			stack<int> pilha;

			if (!guardas[v]) {
				cout << "Vistando o vértice " << v << endl;  
				guardas[v] = true; //marca "v" como visitado
				pilha.push(v); // insere "v" na pilha
				
			}

			bool achou = false;
			list<int>::iterator it;

			//busca por um vizinho não visitado
			for (it = grafo[v].begin(); it != grafo[v].end(); ++it) {
				if (!guardas[*it]) {
					achou = true;
					++total_guardas;
					break;
				}
			}

			if (achou) {
				v = *it; // atualiza o "v"
			} else {
				// se todos os vizinhos estão vizitados ou não existem vizinhos
				// remove da pilha
				pilha.pop();

				if(pilha.empty()) {
					cout << "Estoy aqui" <<endl;
					break;		
				}
				//se chegou aqui, é porque pode pegar elemento do topo
				
				v = pilha.top();
			}

		}

		printf("%d\n", total_guardas);

		++cont;
	}


}