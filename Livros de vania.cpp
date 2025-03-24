#include <iostream> // Entrada e sa?da
#include <climits> // INT_MAX
#include <bits/stdc++.h>
#include <windows.h>
#include <algorithm> // next_permutation

using namespace std;

int main()
{
	int custo[100][100]; // custo = peso e grau de interesse pelo livro
	int n; // numero de livros de vania
	int c; // capacidade da bolsa de vania

	cin >> n >> c;

	cout << "Entre com o peso do livro e o grau de interesse desse livro: " << endl;
	while(n != 0)
	{
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
			{
				cin >> custo[i][j];
				custo[j][i] = custo[i][j];
			}
	}

	time_t start, end;
	time(&start);
	ios_base::sync_with_stdio(false);

	int v[100];
	int p; // var. auxiliar
	int menor_custo; // melhor escolha de livros
	int custo_caminho; // custo do caminho

	// forca bruta
	menor_custo = INT_MAX; // inicializo o custo com infinito
	do
	{
		custo_caminho = custo[c][v[0]]; // custo da cidade inicial -> v[0]

		for(int i = 0; i < n - 2; i++) // somar custo de v[0]->v[1]->v[2]...v[n-3]->v[n-2]
			custo_caminho += custo[v[i]][v[i + 1]];

		custo_caminho += custo[v[n - 2]][c]; // custo v[n-2] -> cidade inicial

		menor_custo = min(menor_custo, custo_caminho);
	}
	while(next_permutation(v, v + (n - 1))); // n-1 = numero de cidades a serem permutadas

	cout << "Caso 1 = "<< menor_custo << endl;

	return 0;
}
