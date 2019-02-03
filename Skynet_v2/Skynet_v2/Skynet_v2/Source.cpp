#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

void main()
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand();
	int aiRandom = rand();
	int enemyLocation = (randomNumber % 64) + 1;
	int aiRPing = 1;
	int aiPing = 1;
	int playerPing = 1;
	int aiRSearchNum = (aiRandom % 64) + 1;
	int aiSearchNum = 1;
	int playerSearchNum;
	bool found = false;
	bool playerTurn = true;
	bool aiTurn = false;
	bool playerPlay = true;
	bool aiPlay = true;
	bool aiRPlay = true;
	string input = "";

	cout << "Generate Random enemy location on 8x8 grid with location numbers 1 - 64.....\nThe enemy location is set.....\nInitializing Skynet HK-Aerial Software....." << endl;
	while (found == false)
	{
		if (playerTurn == false && aiTurn == true && aiPlay == true)
		{
			if (aiSearchNum != enemyLocation)
			{
				cout << "----------------------------------------------------\nSkynet HK-Aerial Linear Radar sending out ping #" << aiPing << endl;
				aiPing++;
				cout << "The target location prediction of " << aiSearchNum << " was incorrect....." << endl;
				++aiSearchNum;
				if ((aiRPlay == true && playerPlay == true) || (aiRPlay == true && playerPlay == false))
				{
					aiTurn = false;
				}
				else if (aiRPlay == false && playerPlay == true)
				{
					aiTurn = false;
					playerTurn = true;
				}
				else if (aiRPlay == false && playerPlay == false)
				{
					playerTurn = false;
					aiTurn = true;
				}
			}
			else if (aiSearchNum == enemyLocation)
			{
				cout << "----------------------------------------------------\nTarget was found by Skynet HK-Aerial Linear Software \nSkynet HK-Aerial Software took " << aiPing << " predictions to find enemy" << endl;
				system("pause");
				aiPlay == false;
				if (aiRPlay == true && playerPlay == true)
				{
					aiTurn = false;
					playerTurn = false;
				}
			}
		}

		if (playerTurn == false && aiTurn == false && aiRPlay == true)
		{
			if (aiRSearchNum != enemyLocation)
			{
				cout << "----------------------------------------------------\nSkynet HK-Aerial Random Radar sending out ping #" << aiRPing << endl;
				aiRPing++;
				cout << "The target location prediction of " << aiRSearchNum << " was incorrect....." << endl;
				aiRandom = rand();
				aiRSearchNum = (aiRandom % 64) + 1;
				if ((aiPlay == true && playerPlay == true) || (aiPlay == false && playerPlay == true))
				{
					playerTurn = true;
				}
				else if (aiPlay == false && playerPlay == true)
				{
					aiTurn = false;
					playerTurn = true;
				}
				else if (aiPlay == false && playerPlay == false)
				{
					playerTurn = false;
					aiTurn = false;
				}
			}
			else if (aiRSearchNum == enemyLocation)
			{
				cout << "----------------------------------------------------\nTarget was found by Skynet HK-Aerial Random Software\nSkynet HK-Aerial Random Software took " << aiRPing << " predictions to find enemy" << endl;
				system("pause");
				aiRPlay == false;
				if (aiPlay == true && playerPlay == true)
				{
					aiTurn = false;
					playerTurn = true;
				}
			}
		}

		if (playerTurn == true && aiTurn == false && playerPlay == true)
		{
			cout << "----------------------------------------------------\nInput enemy location prediction: " << endl;
			cin >> playerSearchNum;
			if (playerSearchNum < enemyLocation)
			{
				cout << "----------------------------------------------------\nUser Radar ping #" << aiPing << endl;
				playerPing++;
				cout << "The target location prediction of " << playerSearchNum << " was lower than enemy position....." << endl;
				system("pause");
				if ((aiPlay == true && aiRPlay == true) || (aiPlay && aiRPlay == false)) {
					playerTurn = false;
					aiTurn = true;
				}
				else if (aiPlay == false && aiRPlay == true)
				{
					playerTurn = false;
				}
				else if (aiPlay == false && aiRPlay == false) {
					playerTurn = true;
					aiTurn = false;
				}
			}
			else if (playerSearchNum > enemyLocation)
			{
				cout << "----------------------------------------------------\nUser Radar ping #" << aiPing << endl;
				playerPing++;
				cout << "The target location prediction of " << playerSearchNum << " was higher than enemy position....." << endl;
				system("pause");
				if ((aiPlay == true && aiRPlay == true) || (aiPlay && aiRPlay == false)) {
					playerTurn = false;
					aiTurn = true;
				}
				else if (aiPlay == false && aiRPlay == true)
				{
					playerTurn = false;
				}
				else if (aiPlay == false && aiRPlay == false)
				{
					playerTurn = true;
					aiTurn = false;
				}
			}
			else if (playerSearchNum == enemyLocation)
			{
				cout << "----------------------------------------------------\nTarget was found by User at location #" << playerSearchNum << "\nUser took " << playerPing << " predictions to find enemy" << endl;
				system("pause");
				playerPlay = false;
				if (aiPlay == true && aiRPlay == true)
				{
					aiTurn = true;
					playerTurn = false;
				}
			}
		}
	}
}