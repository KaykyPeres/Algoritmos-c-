#include <iostream>
#include<string>

using namespace std;

class pessoa {
    public:
    string nome;
    int idade;
    pessoa(string nome, int idade){
        this->nome = nome;
        this->idade = idade;
    }
    string nomear(){
        return " O nome e: " + nome;
    }

};

class professor: pessoa {
    public:
    string nome;
    int idade;
    professor(string nome, int idade) : pessoa(nome, idade){
        this->nome = nome;
        this->idade = idade;
    }

    void idadeProfessor(){
        cout << " A idade do professor "<< nome << " e de :"<< idade << endl;
    }

};

class aluno: pessoa {
    public:
    string nome;
    int idade;
    int getMatricula(){
        return matricula;
    }

    aluno(string nome, int idade) : pessoa(nome, idade){
        this->nome = nome;
        this->idade = idade;
    }

    void idadeAluno(){
        cout << " A idade do aluno "<< nome << " e de :" << idade << endl;
    }


    private:
    int matricula;

};

int main(){
    pessoa pessoa1("kayky",21);
    aluno aluno1("Frank",22);
    professor professor1("Marcelo",30);

    cout << pessoa1.nomear() << endl;
    aluno1.idadeAluno();
    professor1.idadeProfessor(); 

    return 0;

};