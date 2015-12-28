#pragma once
#include <iostream>

using namespace std;

class CardDeck
{
private:
	double DeckCards[52];
public:
	void genDeck()
	{
		for (int i = 0; i < 52; i++)
		{
			DeckCards[i] = i + 2;
		}
	}
	void showDeck()
	{
		for (int i = 0; i < 52; i++)
		{
			cout << DeckCards[i] << "  ";
			if (i % 13 == 0 && i != 0)
				cout << "\n";
		}
	}
	double getCards(int i)
	{
		return DeckCards[i];
	}
};
