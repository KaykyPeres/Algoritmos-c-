#include <iostream>
#include <cmath>

using namespace std;

struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, int x)
{
    if(p == NULL)  //insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else
    {
        if(x < p->info) //insere na esquerda
        {
            tInsere(p->esq, x);
        }
        else    //insere na direita
            tInsere(p->dir, x);
    }
}

treenodeptr tMenor(treenodeptr &raiz)
{
	treenodeptr t;

	t = raiz;
	if(t->esq == NULL)
	{
		raiz = raiz->dir;
		return t;
	}
	else
		return tMenor(raiz->esq);
}

treenodeptr tPesq(treenodeptr p, int x)
{
	if(p == NULL)
		return NULL;
	else if(x == p->info)
		return p;
	else
	{
		if(x < p->info)
		{
			return tPesq(p->esq, x);
		}
		else
			return tPesq(p->dir, x);
	}
}

int tRemove(treenodeptr &raiz, int x)
{
	treenodeptr p;
	if(raiz == NULL)
		return 1;
	if(x == raiz->info)
	{
		p = raiz;
		if(raiz->esq == NULL)
			raiz = raiz->dir;
		else
		{
			if(raiz->dir == NULL)
				raiz = raiz->esq;
			else
			{
				p = tMenor(raiz->dir);
				raiz->info = p->info;
			}
		}
		delete p;
		return 0;
	}
	else
	{
		if(x < raiz->info)
			return tRemove(raiz->esq, x);
		else
			return tRemove(raiz->dir, x);
	}
}

treenodeptr tMenor(treenodeptr &raiz)
{
    treenodeptr t;

    t = raiz;
    if(t->esq == NULL)
    {
        raiz = raiz->dir;
        return t;
    }
    else
        return tMenor(raiz->esq);
}

bool ehPrimo(int x)
{
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

treenodeptr removePrimos(treenodeptr raiz)
{
    if (raiz == NULL) {
        return NULL;
    }

    raiz->esq = removePrimos(raiz->esq);
    raiz->dir = removePrimos(raiz->dir);

    if (ehPrimo(raiz->info)) {
        return tRemove(raiz, raiz->info);
    }

    return raiz;
}

void emOrdem(treenodeptr arvore)
{
    if(arvore != NULL)
    {
        emOrdem(arvore->esq);
        cout << arvore->info << " ";
        emOrdem(arvore->dir);
    }
}

int main()
{
    treenodeptr arvore = NULL; //ponteiro para a raiz
    int numeroDeFolhas; //valor do numero de folhas

    //entrada dos nós
    cin >> numeroDeFolhas;
    while(numeroDeFolhas != 0)
    {
        tInsere(arvore, numeroDeFolhas);
        cin >> numeroDeFolhas;
    }

    // removendo os números primos
    arvore = removePrimos(arvore);

    // mostrando os elementos da árvore do menor para o maior
    emOrdem(arvore);

    return 0;
}
