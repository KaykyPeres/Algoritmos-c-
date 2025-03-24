#include <iostream>

using namespace std;

struct treenode{
    int inf;
    treenode *esq;
    treenode *dir;
};
typedef treenode* treenodeptr;


void treeInsere(treenodeptr &p, int x){
    if(p==NULL){
        p = new treenode;
        p->inf = x;
        p->esq=NULL;
        p->dir=NULL;
    }
    else if(x<p->inf){
        treeInsere(p->esq,x);
    }else{
        treeInsere(p->dir,x);
    }
}

treenodeptr pMenor(treenodeptr arvore){
    if (arvore != NULL)
    {
        if(arvore->esq!=NULL){
            return pMenor(arvore->esq);
        }
        else{
            return arvore;
        }
    }
}
treenodeptr pMaior(treenodeptr arvore){
    if (arvore != NULL)
    {
        if(arvore->dir!=NULL){
            return pMaior(arvore->dir);
        }
        else{
            return arvore;
        }
    }
}

int main() {
    //ponteiro para raiz
    treenodeptr arvore= NULL;
    int valorAuxInsercao;
    treenodeptr auxMenor;
    treenodeptr auxMaior;

    while(true){
        cin>>valorAuxInsercao;
        if(valorAuxInsercao ==-1 ){
            break;
        }
        treeInsere(arvore,valorAuxInsercao);
    }

    auxMenor = pMenor(arvore);
    auxMaior = pMaior(arvore);

    cout<<auxMenor->inf<< " e "<<auxMaior->inf;




    return 0;

}