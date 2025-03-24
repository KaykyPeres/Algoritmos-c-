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

void tInsere(treenodeptr &p, int x) //inserindo elementos na árvore binária
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

treenodeptr tPesq(treenodeptr p, int x){
	if (p == NULL){ // elemento não encontrado
		return NULL;
	} else {
		if (x == p->info){ // elemento encontrado na raiz
			return p;
		} else{ 
			if (x < p->info){ // procura na sub árvore esquerda
				return tPesq(p->esq,x);
			} else { // procura na sub árvore direita
				return tPesq(p->dir,x);
			}
		}
	}
}

void preOrdem (treenodeptr arvore){
	if (arvore != NULL){
		cout << arvore->info << " ";
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

void emOrdem (treenodeptr arvore){
	if (arvore != NULL){
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}

void posOrdem (treenodeptr arvore){
	if (arvore != NULL){
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << " ";
	}
}

void mediaposOrdem (treenodeptr arvore, int &soma, int &n)//incrementando o n, para saber quantos elementos tem na árvore e somando o elementos
{
	if (arvore != NULL)
	{
		mediaposOrdem(arvore->esq, soma, n);
		mediaposOrdem(arvore->dir, soma, n);
		soma += arvore->info;
		n++;
	}
}

void emNivel(treenodeptr t, float &med, int &cont)
{
	list<treenodeptr> q; // fila auxiliar
	treenodeptr n = t; // ponteiro para varrer a árvore
	if (t != NULL)
	{
		q.push_back(n);
		while (!q.empty())
		{
			n = q.front();
			q.pop_front();
			if (n->esq != NULL)
			{
				q.push_back(n->esq);
			}
			if (n->dir != NULL)
			{
				q.push_back(n->dir);
			}
			if(n->esq == NULL && n->dir == NULL)
			{
				med += n->info;
				cont++;
			}

		}
	}
}

void tDestruir( treenodeptr &arvore)
{
	if(arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

float calcMedia(treenodeptr arvore)
{
	float med = 0;
	int cont = 0;

	emNivel(arvore, med, cont);
	if(cont == 0 )
	{
		cont = 1;
	}
	return med / cont;
}

int main()
{
	treenodeptr arvore = NULL;
	treenodeptr p = NULL;
	float x;

	cin >> x;
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	x = calcMedia(arvore);

	// saidas
	cout << fixed << setprecision(2); //colocando precisão de 2 casas decimais
	cout << "Media= " << x; //mostrando a média

	return 0;

}
