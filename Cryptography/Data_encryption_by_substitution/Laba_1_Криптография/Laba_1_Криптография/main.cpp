#include <iostream>
#include <string>
using namespace std;

string V[32] = {
	"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111",
	"01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111",
	"10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111",
	"11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"
};
const int m = 5;
const int key = 5;
string Encryption(string str, int key);
string Decryption(string str, int key);

void main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	string mess;
	string encryptMess;
	string decryptMess;
	cout << "¬ведите исходный текст(длина кратна€ 5), использу€ алфавит(0,1): \n";
	cin >> str;
	if (str.length() % m != 0)
		printf("ƒлина сообщени€ не кратна %d!", m);	
	else
	{
		mess = str;
		encryptMess = Encryption(str, key);
		str = encryptMess;
		decryptMess = Decryption(str, key);
		
		cout << "\n»сходное сообщение:      " << mess;
		cout << "\nЎифрограмма:             " << encryptMess;
		cout << "\nƒешифрованное сообщение: " << decryptMess;
	}
	cout << "\n\n";
	system("pause");
}

string Encryption(string str, int key)
{
	for (int i = 0; i < str.length(); i+=m)
		for (int j = 0; j < 32; j++)
			if (str.compare(i, 5, V[j]) == 0)
			{
				str.replace(i, 5, V[(j + key) % 32]);
				break;
			}
	return str;
}

string Decryption(string str, int key)
{
	key = 32 - key;
	str = Encryption(str, key);
	return str;
}




