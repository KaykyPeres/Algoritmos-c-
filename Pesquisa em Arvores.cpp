#include <iostream>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr; // typedef cria um novo tipo de variável

void tInsere(treenodeptr &p, int x)
{
	if(p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;

	}
	else if(x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub´arvore esquerda
		return tPesq(p->esq, x);
	else // procura na sub´arvore direita
		return tPesq(p->dir, x);
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a raiz(deve apontar para NULL)
	treenodeptr aux;
	int x; // var aux p/ inserir dados

	tInsere(arvore, 14);
	tInsere(arvore, 4);
	tInsere(arvore, 18);
	tInsere(arvore, 20);
	tInsere(arvore, 8);
	tInsere(arvore, 13);
	tInsere(arvore, 2);
	tInsere(arvore, 16);

	cin>> x;
	//x = 13;
	
	aux = tPesq(arvore, x);
	if(aux != NULL)
		cout <<"Encontrado! : " << aux->info << endl;
	else
		cout << x << " Nao encontrado" << endl;

	return 0;
}