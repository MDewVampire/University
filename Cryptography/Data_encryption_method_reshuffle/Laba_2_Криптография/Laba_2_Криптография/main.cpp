#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

const int m = 15;
int key[m] = { 6, 9, 1, 5, 10, 3, 15, 4, 12, 2, 13, 7, 11, 8, 14 };
char buf[15];

string Encryption(string str);
string Decryption(string str);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	string mess;
	string encryptMess;
	string decryptMess;

	cout << "¬ведите сообщение, использу€ данный алфавит (\"a..z,а..€\"):\n";
	cin >> str;
	mess = str;
	
	if (str.length() % m != 0)
		str.append("ъъъъъъъъъъъъъъъ", m - (str.length() % m));
	cout << "\n»сходное сообщение:\n" << mess << "\n\n—корректированное сообщение: " << str;

	encryptMess = Encryption(str);
	str = encryptMess;
	decryptMess = Decryption(str);

	cout << "\nЎифрограмма:                 " << encryptMess;
	cout << "\nƒешифрованное сообщение:     " << decryptMess;

	cout << "\n\n";
	system("pause");
}

string Encryption(string str)
{
	string temp;
	int step = 0;
	for (int i = 0, j = 0; i < str.length(); i++)
	{
		if (i % m == 0 && i != 0)
			step += m;
		int index = key[i%m] - 1;
		temp += str[index + step];
	}
	return temp;
}

string Decryption(string str)
{
	string temp;
	int step = 0;
	for (int i = 0, j = 0; i <= str.length(); i++)
	{
		if (i % m == 0 && i != 0)
		{
			temp += buf;
			j = 0;
			step += m;
		}
		int index = key[j] - 1;
		buf[index] = str[i];
		j++;		
	}
	return temp;
}