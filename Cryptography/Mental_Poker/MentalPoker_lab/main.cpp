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

	CardDeck cards; //исходная колода карт
	cards.genDeck();
	cout << "Исходная колода карт:\n";
	cards.showDeck();

	double p;
	p = gen_prime();
	cout << "\n\nАлиса и Боб договариваются о просто числе Р = " << p;

	Alice.genK(p);
	cout << "\nАлиса генерирует ключ А = "; Alice.showK();
	Bob.genK(p);
	cout << "\nБоб генерирует ключ B = "; Bob.showK();

	cout << "\n\n";
	cout << "Алиса шифрует каждую карту своим ключем А...";
	Alice.EncryptCards(cards, p);
	cout << "\nЗашифрованная Алисой коллода карт:\n";
	Alice.showEDC();	
	cout << "\n\nАлиса тасует карты...";
	Alice.MixEncryptCardDeck();
	cout << "\nКоллода перемешанных зашифрованных Алисой карт:\n";
	Alice.showMixCardDeck();

	cout << "\n\nБоб выбирает 5 карт из зашифрованной и перасованной колоды Алисой...";
	Bob.GetFiveCards(Bob, Alice);
	cout << "\nБоб выбрал следующие карты: \n";
	Bob.ShowFiveCards();
	
	
	cout << "\n\n";
	system("pause");
}