#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

int main()
{
	float area;
	int n; // quantidade de conjuntos de pontos
	int i;// contador
	ponto p1;
	ponto p2;
	ponto p3;

	cout << fixed << setprecision(2);

	// entrabdo com a quantidade de conjuntos
	cin >> n;
	//entrando com os conjuntos

	for(i = 0; i < n; i++)
	{
		cin >> p1.x >> p1.y;
		cin >> p2.x >> p2.y;
		cin >> p3.x >> p3.y;

		area = area_triangulo(p1, p2, p3);

		if(area_triangulo(p1, p2, p3) == 0)
		{
			cout << "Nao formam triangulo" << endl;

		}
		else
		{
			cout << area_triangulo(p1, p2, p3) << endl;
		}

	}


	return 0;
}
