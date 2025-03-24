#include<iostream>

using namespace std;

int mdc(int f1, int f2)
{
	if(f1 % f2 == 0)
		return f2;
	else
		return mdc(f2, f1 % f2);
}

int main()
{
	int numCasos; // numero de casos
	int f1;// figurinhas de ricardo
	int f2;// figurinhas de vicente

	cin >> numCasos;
	for(int i = 0; i < numCasos; i++)
	{
		cin >> f1 >> f2;
		cout << mdc(f1, f2) << endl;
	}

	return 0;
}
