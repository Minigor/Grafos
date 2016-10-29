#include <iostream>
#include <algorithm>
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

	int num = MAX;


	for (int i = 0; i < n; ++i) {
		//vector<int> m(grafo[i],grafo[i]+n);
		sort(grafo[i],grafo[i]+n);
		num = grafo[i][n-1] < num ? grafo[i][n-1] : num;
	}

	
	printf("%d\n", num);



}
