// Mastermind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Master.h"
#include "string"
#include "iostream"
using namespace std;
consolewindow console;
int main()
{
	int players,guesses=0,rr,rw;
	bool multi;
	string code="",guess="",correct="";
	//Non important
	int numint;
	string consume = "";
	cout << "Welcome to MasterMind! How would you like to play?\n(1) Single Player\n(2) Multiplayer\n(3) Instructions\n>";
playerinput:
	console.safeInput(players);
	if (players == 2)
		multi = true;
	else if (players == 1)
		multi = false;
	else if (players == 3)
	{
		system("cls");
		cout << "This is a game called Mastermind. In this game, you will be given a code. This code\nis 5 digits long, with each digit resembling any number from 1 to 9. To guess this\ncode, enter your own 5 digit number. After you enter your number, you will be told\nhow many numbers are correct, and whether they are in the right positions. \n\nIf the code was 12345 and you guessed 56789, you would receive a result of\n0 in the correct spot with the correct number, and only one with the correct number\nin the wrong spot, which is the 5. In normal gameplay, you will not be told which\nnumbers were correct and which were wrong, so be sure to incorporate your own\nstrategy into cracking the code!\n\nGood luck!\n";
		system("pause");
		system("cls");
		cout << "Welcome to MasterMind! How would you like to play?\n(1) Single Player\n(2) Multiplayer\n(3) Instructions\n>";
		goto playerinput;
	}
	else
	{
		cout << "[SYSTEM] I'm sorry, I didn't get that, what did you say?: ";
		goto playerinput;
	}
	system("cls");
	if (multi)
	{
		cout << "[Coder] Please enter the code you wish to play with, in the form\n\t[number][number][number][number][number]\n\tex: 12345\n\tp.s. no zeros allowed\n>";
	inputcode:
		console.safeInput(numint);
		if (numint > 99999 || numint < 11111)
		{
			cout << "[SYSTEM] I'm sorry, could you try that again?\n";
			goto inputcode;
		}
		code = to_string(numint);

	}
	else
	{
		cout << "[Comp] I have selected a new code... Good Luck!\n";
		code = to_string(console.random(11111, 99999));
		system("pause");
	}
	system("cls");
	while (true)
	{
	inputguess:
		if (guesses == 10)
			goto fail;
		cout << "[Guesser] Please enter your guess: ";
		console.safeInput(numint);
		if (numint > 99999 || numint < 11111 )
		{
			cout << "[SYSTEM] I'm sorry, could you try that again?\n";
			goto inputguess;
		}
		guess = to_string(numint);
		guesses++;
		if (guess == code)
			goto win;
		correct = "";
		rr = 0;
		rw = 0;
		for (int i = 0; i < 5; i++)
		{
			if (code[i] == guess[i])
			{
				rr++;
				correct += guess[i];
			}
		}
		for (int i = 0; i < 5; i++)
		{
			if (code.find(guess[i]) != string::npos && correct.find(guess[i]) == string::npos)
			{
				rw++;
				correct += guess[i];
			}
		}
		cout << "\tYou have\n\t" << rr << " in the correct position with the correct number, and\n\t" << rw << " in the wrong position, but with the right number.\n";
	}
fail:
	system("cls");
	cout << "I'm sorry, but you took too long. The code was:\n\t\t" << code << endl;
	system("pause");
	return 0;
win:
	system("cls");
	cout << "You won!" << endl << "You got the answer in " << guesses << " tries!\n";
	system("pause");
    return 0;
}

