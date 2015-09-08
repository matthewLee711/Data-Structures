#include <iostream>
#include <string>
#include <sstream>
#include "LaserTag.h"

//constructor
LaserTag::LaserTag()
{
	//input variable
	//make sure to set pointers to null
	//match1Info = 0;
}

//Take in team name from Team File
void LaserTag::teamNameStore(string team)
{
	//public to take in team name
	teamName = team;
}

//parses team txt file and removes delimiters
void LaserTag::teamDataOrganizer(string teamData)
{
	//string delimeter to get rid of spaces
	string delimiter = " ";

	//store data into this string which will later be parsed
	matchLineTeam = teamData;

	//This function is focused on deleting the spaces in the string and extract info
	//start at position zero in string
	size_t pos = 0;
	//token string stores info from matchLine
	std::string token2;
	//While loop focuses on finding the delimiter ' ' and removing it
	while ((pos = matchLineTeam.find(delimiter)) != std::string::npos) {
		token2 = matchLineTeam.substr(0, pos);
		std::cout << token2 << std::endl;
		matchLineTeam.erase(0, pos + delimiter.length());
	}

	//cout << "matchLine" << matchLine << endl;
	//cout << "TeamName" << teamName << endl;

}

//Organizes team data
//void LaserTag::TeamDataOrganizerPrivate() {}

//Gather Number of players
void LaserTag::playerCount(string numberOfPlayers)
{
	//count players, will help determine how much space for array
	LaserTag::playerCounter = stoi(numberOfPlayers);
}

//Take match and delete spaces
void LaserTag::matchInformation(string matchData)
{
	//string delimeter to get rid of spaces
	string delimiter = " ";

	//store data into this string which will later be parsed
	matchLine = matchData;

	//This function is focused on deleting the spaces in the string and extract info
	//start at position zero in string
	size_t pos = 0;
	//token string stores info from matchLine
	std::string token;
	//While loop focuses on finding the delimiter ' ' and removing it
	while ((pos = matchLine.find(delimiter)) != std::string::npos) {
		token = matchLine.substr(0, pos);
		std::cout << token << std::endl;//output each NUMBER
		matchLine.erase(0, pos + delimiter.length());
	}
	//print out info from each match
	//std::cout << LaserTag::matchLine << std::endl;

	//figure out how to get each specific piece of data.
	//IDEAS: extract data from each team, then collect data from matches based on teams
	//print();
	
	//convert string into int so can put into int array
	//LaserTag::playerData = stoi(matchData);
	//loop reads/adds exact information to array based on playerCounter 
	//for (int i = 0; i < 100; i++) match1Info[i] = playerData;
}

void LaserTag::print()
{
	cout << "Grab last number in match: " << matchLine << endl;
	//for (int i = 0; i < 20; i++) cout << match1Info[i] << endl;

	cout << "Team Name" << teamName << endl;
	cout << "Team data: " << playerData << endl;
}