#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct motoboy
{
	int localidade;//local atual do entregador
	int nentregas;//numero de entregas que o entregador fez
	int distsup;//distancia do entregador ate o supermercado
	int distlocal[100];//distancia do entregador ate o local A
	int mochila;//peso de cada entregas
	int caminho[100];//caminhos que o entregador passou
	int tempo;//tempo total gasto pelo entregador
	int custo;//custo para comparacao
};

struct cidade
{
	int peso; //peso da entrega
	int distancia[100]; //distancia ate o local B
	bool entregue;//verificar se a compra ja foi entregue
};

int main()
{
	//chamando as funcoes
	cidade c[100];
	motoboy m[100];

	int n;// numero de cidades
	int motos; // numero de motoboys
	int melhorentregador;// var p decidir o melhor entregador
	int entregador; // definindo melhor entregador para primeira entrega
	int passou[100];//verificar se ja passou no local
	int menorcusto = 10000; // THE "Menor custo"
	int entregadorescolhido;// entregador selecionado para cada entrega
	int pesoatual; // peso que cada entregador leva
	int localatual;// por onde cada entregador passa
	int tempoatual; // tempo que cada entregador demora

	// entrando com o numero de cidades
	cout << "Entre com o numero de cidades" << endl;
	cin >> n;

	//for para as cidades
	for(int i = 0; i < (n - 1); i ++)
	{
		for(int j = (i + 1); j < n; j ++)
		{
			cout << "Entre com a distancia do local " << i << " ate o local " << j << ": ";
			cin >> c[i].distancia[j];
			c[j].distancia[i] = c[i].distancia[j];//caminho reverso
			cout << endl;
		}
	}

	// entrando com o numero de entregadores
	cout << "Numero de motoboys : ";
	cin >> motos;

	//for para entrar com os custos dos motoboys ate o supermercado
	for(int i = 0; i < motos; i++)
	{
		cout << "Entre com o custo de ir do motoboy " << i + 1 << " para o Supermercado " << endl;
		cin >> m[i].distsup;
		if(m[i].distsup < entregador)
		{
			entregador = m[i].distsup;
			melhorentregador = i;
		}
	}

	// for para entrar com o peso das entregas
	for(int i = 1; i < n; i++)
	{
		cout << "Peso entrega " << i << " : " << endl;
		cin >> c[i].peso;
	}

	//resetando visitas aos locais
	for(int i = 0; i < n; i ++)
	{
		passou[i] = false;
		c[i].entregue = false;
	}

	//somando tempo ao supermercado no custo total
	for(int i = 0; i < motos; i ++)
	{
		m[i].tempo = m[i].distsup;
		m[i].nentregas = 0;
		m[i].mochila = 0;
	}

	// for para definicao do melhor entregador com seu peso localizacao e tempo
	for(int i = 1; i < n; i ++)
	{
		for(int j = 0; j < motos; j ++)
		{
			m[j].custo += c[m[j].localidade].distancia[i];
			if((m[j].custo < menorcusto) && (m[j].mochila + c[i].peso < 18))
			{
				entregadorescolhido = j;
				pesoatual = c[i].peso;
				localatual = i;
				tempoatual = c[m[j].localidade].distancia[i];
			}
		}

		m[entregadorescolhido].localidade = localatual;
		m[entregadorescolhido].mochila += pesoatual;
		m[entregadorescolhido].tempo += tempoatual;
		m[entregadorescolhido].caminho[m[entregadorescolhido].nentregas] = localatual;
		m[entregadorescolhido].nentregas += 1;

		for(int z = 0; z < n; z ++)
		{
			m[entregadorescolhido].distlocal[z] = c[localatual].distancia[z];
		}

		//saida de quais compras ficaram com cada entregador
		cout << "Entregador " << entregadorescolhido + 1 << " entregou para o local " << localatual << endl;
		cout << "Tempo : " << m[entregadorescolhido].tempo << endl;
	}

	//saida do tempo percorrido por cada entregador
	for(int i = 0; i < motos; i ++)
	{
		cout << "Tempo gasto pelo entregador " << i + 1 << ": " << m[i].tempo;
		cout << endl;
		cout << "Caminho do entregador " << i + 1 << ": 0 ";

		//saida para recuperacao de caminho de cada entregador
		for(int j = 0; j < m[i].nentregas; j ++)
		{
			cout << m[i].caminho[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
