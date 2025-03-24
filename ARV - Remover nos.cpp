#include <iostream>

using namespace std;

struct treenode{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, int x){
    if(p == NULL){ //insere na raiz
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else{
        if(x<p->info){//insere na esquerda
            tInsere(p->esq,x);
        }
        else    //insere na direita
            tInsere(p->dir,x);
    }
}

treenodeptr tMenor(treenodeptr &raiz){
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

treenodeptr tPesq(treenodeptr p,int x){
    if(p==NULL)
        return NULL;
    else if(x == p->info)
        return p;
    else{
        if(x < p->info){
            return tPesq(p->esq,x);
        }
        else
            return tPesq(p->dir,x);
    }
}

int tRemove(treenodeptr &raiz, int x){
	treenodeptr p;
	if(raiz == NULL)
		return 1;
	if(x == raiz->info){
		p = raiz;
		if(raiz->esq == NULL)
			raiz = raiz->dir;
		else
		{
			if(raiz->dir == NULL)
				raiz = raiz->esq;
			else{
				p = tMenor(raiz->dir);
				raiz->info = p->info;
			}
		}
		delete p;
		return 0;
	}
	else{
		if(x < raiz->info)
			return tRemove(raiz->esq,x);
		else
			return tRemove(raiz->dir,x);
	}
}

void emOrdem(treenodeptr arvore){
    if(arvore != NULL){
        emOrdem(arvore->esq);
        cout << arvore->info <<" ";
        emOrdem(arvore->dir);
    }
}

int main()
{
    treenodeptr arvore = NULL;//ponteiro para a raiz
    int numeroDesejado; // numero de folhas desejado
    int numeroDeFolhas;//valor do numero de folhas
	
    //entrada dos nós
	cin >> numeroDeFolhas;
	while(numeroDeFolhas != 0){
		tInsere(arvore, numeroDeFolhas);
		cin >> numeroDeFolhas;
	}
	
    //entrandocom o valor x
    cin >> numeroDesejado;

	while (tRemove(arvore, numeroDesejado) == 0);
	emOrdem(arvore);
	
    return 0;
}
