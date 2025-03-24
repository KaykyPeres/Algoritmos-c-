#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void rabin_karp(char T[], char P[], int tamT, int tamP, int d, int q)
{

	int h; // valor utilizado para calculo de hash
	int p = 0; // padrao convertido para inteiro
	int t = 0; // texto convertido para inteiro
	int soma = 0;
	int aux;

	for(int i = 0; i < tamP; i++)
	{
		p = (d * p + (P[i] - '0')) % q; // converte o padrao
		t = (d * t + (T[i] - '0')) % q; // converte o texto para o primeiro valor (t0)
	}

	h = (int)pow(d, tamP - 1) % q; // utilizado para calculo de hash

	for(int i = 0; i <= tamT - tamP; i++)
	{
		if(p == t) // Se encontrei um valor de hash valido
		{
			// Verifico se ha diferencas
			int j;
			for(j = 0; j < tamP; j++)
			{
				if(P[j] != T[i + j])
				{
					break;
				}
			}

			if(j == tamP)
			{
				aux = i;
				soma++;
			} 
		}

		if(i < tamT - tamP) // se ainda nao cheguei no final
		{
			t = (d * ( t - (T[i] - '0') * h ) + (T[i + tamP] - '0')) % q; // atualizo o ti para ti+1
			if(t < 0) t += q;
		}
	}
	cout << "Ultima ocorrencia: posicao " << aux << endl;
	cout <<soma<<" ocorrencia(s)" << endl;

}

int main()
{
	int N; // tamanho do texto
	int M; // padrao do texto
	char n[100];
	char m[100];
	int d = 10;
	int q = 3;
	
	// entradas
	cin >> N >> M;
	cin >> n;
	cin >> m;
	
	/*
	cin.ignore();
	cin.getline(n,100);
	cin.getline(m,100);
	*/
	
	// chamando a funçao
	rabin_karp(n,m,N,M,d,q);
	
	return 0;
}
