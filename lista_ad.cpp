//Grafos - Lista de adjacência

#include <iostream>
#include <list>
#include <algorithm> //função find

using namespace std;

class Grafo {

	private:
		int v; // número de vértices
		list<int> *adj; // ponterio para um array contendo as listas de adjacências

	public:
		Grafo(int v); //Construtor
		void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
		
		/* 	
		obtém o grau de saída de um dado vértice
		grau de saíde é o número de arcos que saem de "v"
		*/
		int obterGrauDeSaida(int v);		

		bool verificaVizinho(int v1, int v2); // verifica se v2 é vizinho de v1
};

Grafo::Grafo(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Grafo::adicionarAresta (int v1, int v2) {
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v) {
	return adj[v].size(); // basta retornar o tamanho da lista que é a quantidade de vizinhos	
}

bool Grafo::verificaVizinho(int v1, int v2) {
	if (find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) 
		return true;

	return false;
}

int main () {

	//Criando um grado de 4 vértices
	Grafo grafo(4);

	//Adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 3);
	grafo.adicionarAresta(1, 2);
	grafo.adicionarAresta(3, 1);
	grafo.adicionarAresta(3, 2);

	//mostrando os graus de saída
	cout << "Grau de saída do vertíce 0: " << grafo.obterGrauDeSaida(0) << endl;
	cout << "Grau de saída do vertíce 1: " << grafo.obterGrauDeSaida(1) << endl;
	cout << "Grau de saída do vertíce 2: " << grafo.obterGrauDeSaida(2) << endl;
	cout << "Grau de saída do vertíce 3: " << grafo.obterGrauDeSaida(3) << endl;

	//verifica se é vizinho
	if (grafo.verificaVizinho(0,2))
		cout << "\n\n0 é vizinho de 2" << endl;
	else 
		cout << "\n\n0 é não vizinho de 2" << endl;


	return EXIT_SUCCESS;
}