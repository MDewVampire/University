#include <iostream>
#include "chapi.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� ������������� �����: ";
	int size;
	cin >> size;
	cout << "\n";

	CAPI Rand(0, size);
	Rand.Generate();	
	Rand.Out();

	cout << "\n\n";
	system("Pause");
}
