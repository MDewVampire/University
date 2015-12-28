#include <iostream>
#include <fstream>
using namespace std;

const int T0 = 13, B = 256;
const int A = 5, C = 51;
char chBuff;
ifstream inFile;
ofstream outFile, gamma;

int PSCh(int Gamma);
char Encrypt(char chBuff, int Gamma);
char Decrypt(char chBuff, int Gamma);

void main()
{
	setlocale(LC_ALL, "Russian");

	int Gamma = T0;	
	inFile.open("Сообщение.txt");
	outFile.open("Шифрограмма.txt");
	gamma.open("Гамма.txt");

	while(inFile.get(chBuff))
	{
		cout << chBuff;
		chBuff = Encrypt(chBuff, Gamma);
		gamma << Gamma << " ";
		Gamma = PSCh(Gamma);
		outFile << (char)chBuff;
	}
	outFile.close();
	inFile.close();
	
	cout << "\n\n";

	Gamma = T0;
	inFile.open("Шифрограмма.txt");
	outFile.open("Дешифрованный текст.txt");
	while (inFile.get(chBuff))
	{
		cout << chBuff;
		chBuff = Decrypt(chBuff, Gamma);
		cout << "(" << chBuff << ") ";
		Gamma = PSCh(Gamma);
		outFile << chBuff;
	}
	outFile.close();
	system("pause");
}

int PSCh(int Gamma)
{
	return (A*Gamma + C) % B;
}

char Encrypt(char chBuff, int Gamma)
{
	int symbol = ((int)chBuff + Gamma) % B;
	return (char)symbol;
}

char Decrypt(char chBuff, int Gamma)
{
	int symbol = ((int)chBuff - Gamma) % B;
	if (symbol < 0)
		symbol += B;
	return (char)symbol;
}
