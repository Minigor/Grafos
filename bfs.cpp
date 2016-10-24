// BFS com lista de adjacência

#include <iostream>
#include <list>
#include <algorithm> //função find
#include <queue>

using namespace std;

class Grafo {

	private:
		int V; // número de vértices
		list<int> *adj; // ponterio para um array contendo as listas de adjacências

	public:
		Grafo(int V); //Construtor
		void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
		void bfs(int v); // faz uma DFS a partir de um vértice

	

};

Grafo::Grafo(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::adicionarAresta (int v1, int v2) {
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v) {
	queue<int> fila;
	bool visitados[V];

	for (int i = 0; i < V; ++i)
		visitados[i] = false;
	
	fila.push(v);

	while (true) {
		if (!visitados[v]) {
			cout << "Vistando o vértice " << v << endl;  
			visitados[v] = true; // marca "v" como visitado
			//fila.push(adj[v]); // insere adjacentes de "v" na fila
		}
	
		list<int>::iterator it;

		for (it = adj[v].begin(); it != adj[v].end(); ++it) {
			fila.push(*it);
		}

		if (fila.empty())
			break;
	
		v = fila.front();

		fila.pop();
	}


}

int main () {

	int V = 8;

	//criação do grafo

	Grafo grafo(V);

	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(0);


	return EXIT_SUCCESS;
}