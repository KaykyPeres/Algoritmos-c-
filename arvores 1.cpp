#include <iostream>
using namespace std;
struct treenode
{
	int info;
	treenode esq;
	treenodedir;
};
typedef treenode *treenodeptr;
void tInsere(treenodeptr &p, int x)
{
	if (p == NULL)  // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if
	(x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else             // insere na subarvore direita
		tInsere(p->dir, x);
}

void preOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout << arvore->info << endl;
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

void contaPreOrdem (treenodeptr arvore, int&N)
{
	if (arvore != NULL)
	{
		N++;
		contaPreOrdem(arvore->esq, N);
		contaPreOrdem(arvore->dir, N);
	}
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << endl;
		emOrdem(arvore->dir);
	}
}

void posOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << endl;
	}
}

int main()
{
	int x;
	int n;
	int y;
	treenodeptr arvore = NULL;
	treenodeptr aux;

	cin >> x;
	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	
	cout << "PreOrdem:" << endl;
	preOrdem(arvore);
	cout << "PosOrdem:" << endl;
	posOrdem(arvore);
	cout << "emOrdem:" << endl;
	emOrdem(arvore);


	return 0;
}
