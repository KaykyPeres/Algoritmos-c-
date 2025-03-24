#include <iostream> // Entrada e sa?da
#include <climits> // INT_MAX

using namespace std;

int main()
{
	int custo[100][100]; // 100 -> numero maximo de cidades
	// custo[i][j] = custo de ir da cidade 'i' para a cidade 'j'
	int cidade_inicial; // Primeira e ultima cidade
	int n; // numero de cidades

	cout << "Entre com o numero de cidades" << endl;
	cin >> n;
	cout << "Entre com a cidade inicial" << endl;
	cin >> cidade_inicial;

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			cout << "Entre com o custo de ir da cidade " << i << " para a cidade " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}

	bool vis[100]; // marca se ja visitou ou nao uma cidade
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int cidade_atual; // cidade atual
	int proxima_cidade; // proxima cidade

	// inicializando vetor vis (nenhuma cidade foi visitada no inicio)
	for(int i = 0; i < n; i++)
	{
		vis[i] = false;
	}

	// guloso

	int caminho[n];
	caminho[0] = cidade_inicial;
	for(int i = 0; i < n; i++)
	{
		if(vis[i] == false)
		{
			if(custo_at < menor_custo)
			{
				menor_custo = custo_at;
			}
			else if(custo_at> menor_custo)
			{
				menor_custo = proxima_cidade;
			}
			custo_at += custo[caminho[i]][caminho[(i+1)%n]];
		}
	}

	cout << "Menor custo = " << menor_custo << endl;
	return 0;
}
