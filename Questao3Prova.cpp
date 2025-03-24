#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

typedef struct
{
	int x;
	int y;
} Ponto;

double area_triangulo(
	Ponto a,
	Ponto b,
	Ponto c
)
{
	return
		((a.x * b.y) - (a.y * b.x) +
		 (a.y * c.x) - (a.x * c.y) +
		 (b.x * c.y) - (b.y * c.x)) / 2.0;
}

double distancia(Ponto p1, Ponto p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
				(p1.y - p2.y) * (p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c)
{
	double area = area_triangulo(a, b, c);
	if(area > 0)
	{
		return 1;
	}
	else if(area < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int dist;// distancia do ponto 2 ate o ponto 3
	int dist2;// distancia do ponto 4 a 5

	Ponto p1;
	Ponto p2;
	Ponto p3;
	Ponto p4;
	Ponto p5;


	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;
	cin >> p4.x >> p4.y;
	cin >> p5.x >> p5.y;

	
	dist = distancia(p2, p3);
	dist2 = distancia(p4, p5);

	cout << fixed << setprecision(0);
	cout << "diametro do olho do peixe: " << distancia(p2, p3) << endl;
	cout << "distancia de uma ponta da cauda ate a outra: " << distancia(p4, p5) << endl;

	return 0;
}
