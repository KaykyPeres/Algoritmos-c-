#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	
	int N;//numero de dias do circo na cidade
	int custoPorDia;
	int receita;//valor recebido no final de cada dia de circo
	int somatoria = 0;
	int lucro;
	int gastos;
	
	
	cout << "Insira quantos dias o circo vai passar na cidade: " << endl;
	cin >> N; 
	cout << "Insira o custo diario paravmanter o circo: " << endl;
	cin >> custoPorDia; 
	cout << "Insira o valor ganho pelo circo em cada dia" << endl;
	
	for(int i = 0; i < N; i++){
		cin >>receita;
		somatoria += receita;
	}
	
	gastos = (N*custoPorDia);
	lucro = (somatoria - gastos);
	
	
	cout << "O ganho total do dono do circo foi: ";
	cout << lucro << endl;
	cout << "---------------------"<< endl;
	

	return 0;
}
