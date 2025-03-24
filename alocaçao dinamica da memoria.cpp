#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct nota
{
	// variaveis para as 4 notas
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float media; // variavel para calcular a media

};

int main()
{
	// alocando memoria para o vetor
    nota *aluno = NULL;
    aluno = new nota;

	// entrando com as notas 
    cin >> aluno->nota1;
    cin >> aluno->nota2;
    cin >> aluno->nota3;
    cin >> aluno->nota4;

	// calculando a media
    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3 + aluno->nota4) / 4;

	// saindo com a media das notas
    cout << fixed << setprecision(2);
    cout << aluno->media << endl;

    return 0;
}