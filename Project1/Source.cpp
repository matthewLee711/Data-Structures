#include <iostream>
#include <fstream>
#include <string>
#include "LaserTag.h"

using namespace std;

int main()
{
	//create LaserTag Object
	LaserTag game;

	//Open Files
	ifstream team1;
	team1.open("sharks.txt");
	ifstream team2;
	team2.open("cowboys.txt");
	ifstream match1;
	match1.open("Text.txt");

	//Output Files
	//ofstream team1;
	
	//string to store data
	string match1Data;

	string team1Data;
	string team2Data;

	//While loop to send team data to appropriate places
	int teamCounter = 0;
	while (getline(team1, team1Data))
	{
		//cout << team1Data << endl;
		//send team name to organizer
		if(teamCounter == 0)
		{
			game.teamNameStore(team1Data);
		}
		else
		{
			game.teamDataOrganizer(team1Data);
		}
		//Counter to decide where information goes
		teamCounter++;
	}

	//While loop to send team data to appropriate places
	int teamCounter2 = 0;
	while (getline(team2, team2Data))
	{
		//cout << team2Data << endl;
		//send team name to organizer
		if (teamCounter2 == 0)
		{
			game.teamNameStore2(team2Data);
		}
		else
		{
			game.teamDataOrganizer2(team2Data);
		}
		//Counter to decide where information goes
		teamCounter2++;
	}

	//While loop to send match data to appropriate places
	int matchCounter = 0;
	while (getline(match1, match1Data))
	{
		game.matchInformation(match1Data);

		matchCounter++;
	}

	//Write information to file
	game.writeToFile();

	//output information
	game.print();

}