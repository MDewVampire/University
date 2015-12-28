#include <iostream>
#include <ctime>
#include <conio.h>
#include "my_rand.h"
#include "Player.cpp"
#include "CardDeck.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	Player Alice, Bob;

	CardDeck cards; //�������� ������ ����
	cards.genDeck();
	cout << "�������� ������ ����:\n";
	cards.showDeck();

	double p;
	p = gen_prime();
	cout << "\n\n����� � ��� �������������� � ������ ����� � = " << p;

	Alice.genK(p);
	cout << "\n����� ���������� ���� � = "; Alice.showK();
	Bob.genK(p);
	cout << "\n��� ���������� ���� B = "; Bob.showK();

	cout << "\n\n";
	cout << "����� ������� ������ ����� ����� ������ �...";
	Alice.EncryptCards(cards, p);
	cout << "\n������������� ������ ������� ����:\n";
	Alice.showEDC();	
	cout << "\n\n����� ������ �����...";
	Alice.MixEncryptCardDeck();
	cout << "\n������� ������������ ������������� ������ ����:\n";
	Alice.showMixCardDeck();

	cout << "\n\n��� �������� 5 ���� �� ������������� � ������������ ������ ������...";
	Bob.GetFiveCards(Bob, Alice);
	cout << "\n��� ������ ��������� �����: \n";
	Bob.ShowFiveCards();
	
	
	cout << "\n\n";
	system("pause");
}