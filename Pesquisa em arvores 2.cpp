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
	int n;
	int y;

	// criando a arvore
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		tInsere(arvore, x);
	}
	
	// pesquisa na arvore
	cin >> y;


	aux = tPesq(arvore, y);
	if(aux != NULL)
		cout << "Encontrado " << endl;
	else
		cout << "Nao encontrado " << endl;

	return 0;
}
