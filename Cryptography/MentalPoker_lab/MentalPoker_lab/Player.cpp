#include "my_rand.h"
#include "CardDeck.h"
#include <iostream>

using namespace std;

class Player
{
private:
	double K;
public:
	double EncryptDeckCard[52];
	double MixCardDeck[52];
	double checkedFiveCard[5];

	void genK(double p)
	{
		K = gen_prime_NOD(p-1);
	}
	void showK()
	{
		cout << K;
	}
	double getK()
	{
		return K;
	}

	void EncryptCards(CardDeck cards, double p)
	{
		double tmpK = getK();
		for (int i = 0; i < 52; i++)
		{
			EncryptDeckCard[i] = powmod(cards.getCards(i), tmpK, p);
		}
	}
	void showEDC()
	{
		for (int i = 0; i < 52; i++)
		{
			cout << EncryptDeckCard[i] << "  ";
			if (i % 13 == 0 && i != 0)
				cout << "\n";
		}
	}

	void MixEncryptCardDeck()
	{
		double memory[52]; 
		int RandCard;
		for (int i = 0; i < 52; i++)
		{
			memory[i] = 0;
		}
		for (int i = 0; i < 52; i++)
		{
			int check = 0;		
			while (true)
			{
				check = 0;				
				RandCard = rand() % 52 + 1;
				for (int j = 0; j < 51; j++)
					if (RandCard != memory[j])
						check++;
				if (check == 51)
					break;
			}
			memory[i] = RandCard;
			MixCardDeck[i] = EncryptDeckCard[RandCard - 1];
		}
	}
	void showMixCardDeck()
	{
		for (int i = 0; i < 52; i++)
		{
			cout << MixCardDeck[i] << "  ";
			if (i % 13 == 0 && i != 0)
				cout << "\n";
		}
	}

	void GetFiveCards(Player Bob, Player Alice)
	{
		double checkCard[5];
		int RandCard;
		for (int i = 0; i < 5; i++)
		{
			checkCard[i] = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			int check = 0;
			while (true)
			{
				RandCard = rand() % 53 + 1;
				for (int j = 0; j < 5; j++)
					if (RandCard != checkCard[j])
						check++;
				if (check == 5)
					break;
			}
			checkCard[i] = RandCard;
			Bob.checkedFiveCard[i] = Alice.MixCardDeck[RandCard];
		}
	}
	void ShowFiveCards()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << checkedFiveCard[i] << "   ";
		}
	}
};