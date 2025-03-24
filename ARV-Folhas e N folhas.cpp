#include <iostream>

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

void contaFolhasENaoFolhas(treenodeptr raiz, int &folhas, int &naoFolhas)
{
    if(raiz == NULL)
    {
        return;
    }
    
    if(raiz->esq == NULL && raiz->dir == NULL) // verifica se é folha
    {
        folhas++;
    }
    else
    {
        naoFolhas++;
    }
    
    contaFolhasENaoFolhas(raiz->esq, folhas, naoFolhas);
    contaFolhasENaoFolhas(raiz->dir, folhas, naoFolhas);
}

int main()
{
    treenodeptr raiz = NULL;
    int folhas = 0, naoFolhas = 0;
    int x;
    int qtdElementos;

    cin >> qtdElementos;
    for(int i =0;i<qtdElementos;i++){
		cout << "Digite o valor que deseja inserir: ";
        cin >> x;
        tInsere(raiz, x);
		
	}
    contaFolhasENaoFolhas(raiz, folhas, naoFolhas);

    cout << "Quantidade de folhas: " << folhas << endl;
    cout << "Quantidade de nós que não são folhas: " << naoFolhas << endl;

    return 0;
}
