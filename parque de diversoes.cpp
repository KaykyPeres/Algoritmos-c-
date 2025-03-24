#include <iostream> 

using namespace std;

struct item
{
	int val; // valor do item
	int peso; // peso do item
};

int main()
{
	int pd[100][100];// valor maximo sendo:
	// olhando do item 'i'->final
	// olhando uma mochila de capacidade 'j'

	int caminho[100][100]; 	// utilizado para recuperar quais itens foram escolhidos
	int n; // quantidade de itens
	int capacidade; // capacidade total da mochila
	item v[100]; // vetor de itens

	//entradas
	cin >> capacidade;
	cin >> n;

	for(int i = 0; i < n; i++)
	{

		cin >> v[i].peso >> v[i].val ;
	}

	for(int j = 0; j <= capacidade; j++)
		pd[n][j] = 0;

	// olhando tendo uma mochila de capacidade 0, o val. maximo=0
	for(int i = 0; i <= n; i++)
		pd[i][0] = 0;


	// CASO GERAL
	for(int i = n - 1; i >= 0; i--)
		for(int j = 1; j <= capacidade; j++)
		{
			int pega, npega;
			npega = pd[i + 1][j];

			if(j >= v[i].peso)
				pega = pd[i + 1][j - v[i].peso] + v[i].val;

			else
				pega = 0; // se nao posso pegar, o valor eh 0

			if(pega > npega) // se valer a pena pegar
			{
				pd[i][j] = pega;
				caminho[i][j] = 1;
			}

			else // se valer a pena nao pegar
			{
				pd[i][j] = npega;
				caminho[i][j] = 0;
			}
		}

    //saida
	cout << pd[0][capacidade] << endl;

	return 0;
}
