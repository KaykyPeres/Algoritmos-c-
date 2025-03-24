#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, int x) //inserindo elementos na �rvore bin�ria
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;

	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);

	else // insere na subarvore direita
		tInsere(p->dir, x);

}

void mediaposOrdem (treenodeptr arvore, int &soma, int &n)//incrementando o n, para saber quantos elementos tem na �rvore e somando o elementos
{
	if (arvore != NULL)
	{
		mediaposOrdem(arvore->esq, soma, n);
		mediaposOrdem(arvore->dir, soma, n);
		soma += arvore->info;
		n++;
	}
}

float media(treenodeptr arvore)
{
	int soma = 0;
	int n = 0;
	double calculamedia;

	mediaposOrdem(arvore, soma, n); //recebendo o valor da soma e do n por refer�ncia
	calculamedia = (double)soma / n; //calculando a m�dia

	return calculamedia; //retornando a m�dia
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	treenodeptr arvore = NULL; //ponteiro para a arvore
	int x; //elementos a serem inseridos
	float auxmedia; //elemento para receber a fun��o media

	//Inserindo dados na �rvore
	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x); //inserindo na �rvore
		cin >> x; //entrando com os elementos
	}

	// saidas
	cout << fixed << setprecision(2); //colocando precis�o de 2 casas decimais
	auxmedia = media(arvore); //recebendo a fun��o
	cout << "Media: " << auxmedia; //mostrando a m�dia
	tDestruir(arvore);

	return 0;

}
