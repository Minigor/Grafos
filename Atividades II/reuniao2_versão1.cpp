#include <iostream>
#define MAX 100000

using namespace std;

int main () {

	int n, m, u, v, w;

	scanf("%d %d", &n, &m);

	int grafo[n][n];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	{
			if (i != j) 
				grafo[i][j] = MAX;
			else
				grafo[i][j] = 0;
		}	
	}

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		if (grafo[u][v] > w)
			grafo[u][v] = w; grafo[v][u] = w;  
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	{
			for (int k = 0; k < n; ++k) {
				if (grafo[j][k] > grafo[j][i] + grafo[i][k]) 
					grafo[j][k] = grafo[j][i] + grafo[i][k];
			}	
		}
	}

	int max_que_eu_quero = MAX, max_da_linha = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	{
			if (max_da_linha < grafo[i][j])
				max_da_linha = grafo[i][j];
		}
		if (max_da_linha < max_que_eu_quero) 
			max_que_eu_quero = max_da_linha;

		max_da_linha = 0;
	}

	printf("%d\n", max_que_eu_quero);



}

