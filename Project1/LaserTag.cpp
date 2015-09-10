#include <iostream>
#include <string>
#include <fstream>
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

void LaserTag::teamNameStore2(string team)
{
	teamName2 = team;
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
	std::string token;
	//While loop focuses on finding the delimiter ' ' and removing it
	while ((pos = matchLineTeam.find(delimiter)) != std::string::npos) {
		token = matchLineTeam.substr(0, pos);
		//std::cout << token << std::endl;//output info from token
		matchLineTeam.erase(0, pos + delimiter.length());//delete and move up
	}

	//cout << "matchLine" << matchLine << endl;
	//cout << "TeamName: " << teamName << endl;
}

void LaserTag::teamDataOrganizer2(string teamData2)
{
	//string delimeter to get rid of spaces
	string delimiter = " ";

	//store data into this string which will later be parsed
	matchLineTeam2 = teamData2;

	//This function is focused on deleting the spaces in the string and extract info
	//start at position zero in string
	size_t pos = 0;
	//token string stores info from matchLine
	std::string token;
	//While loop focuses on finding the delimiter ' ' and removing it
	while ((pos = matchLineTeam2.find(delimiter)) != std::string::npos) {
		token = matchLineTeam2.substr(0, pos);
		//std::cout << token << std::endl;//output info from token
		matchLineTeam2.erase(0, pos + delimiter.length());//delete and move up
	}
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

	//total for calculating total score
	total = 0;

	int infoCounter = 0;

	//This function is focused on deleting the spaces in the string and extract info
	//start at position zero in string
	size_t pos = 0;
	//token string stores info from matchLine
	std::string token;
	//While loop focuses on finding the delimiter ' ' and removing it
	while ((pos = matchLine.find(delimiter)) != std::string::npos) {
		token = matchLine.substr(0, pos);
		//std::cout << token << std::endl;//output each NUMBER

		//Convert string into int
		LaserTag::playerData = stoi(token);

		//remove time
		if (playerData >= 100)
		{
			playerData = 0;//delete element by set to zero
			infoCounter++;
			//include statement to gather score! -- if number 3 = 3 = points
		}
		//if it is not time, player will be separated into groups
		else {
			//if statement to send people to tagger
			if(infoCounter == 0)
			{
				//send to tagger vector
				tagger.push_back(playerData);
				infoCounter++;
			}
			//if statement to send people to tagged
			else if (infoCounter == 1)
			{
				//send to tagged vector
				tagged.push_back(playerData);
				infoCounter++;
			}
			//total up information store in array
			total = total + playerData;
			cout << "total " << infoCounter <<": " << total << endl;
			//infoCounter++;
		}

		matchLine.erase(0, pos + delimiter.length());
	}
	//print out info from each match
	//std::cout << LaserTag::matchLine << std::endl;

	//figure out how to get each specific piece of data.
	//IDEAS: extract data from each team, then collect data from matches based on teams
	//print();
	
	//convert string into int so can put into int array
	//LaserTag::playerData = stoi(token);
	//loop reads/adds exact information to array based on playerCounter 
	//for (int i = 0; i < 100; i++) match1Info[i] = playerData;
}

void LaserTag::writeToFile()
{
	//low verbosity
	ofstream lowVerbosity;
	lowVerbosity.open("lowVerbosity.txt");
	lowVerbosity << teamName << " had " << total << endl
		<< teamName2 << " had " << total;//matchLine

}

void LaserTag::print()
{
	//print vector of tagger
	for (vector<int>::const_iterator i = tagger.begin(); i != tagger.end(); ++i)
	{
		cout << *i << ' ';
	}
	//print vector of tagged
	for (vector<int>::const_iterator i = tagged.begin(); i != tagger.end(); ++i)
	{
		cout << *i << ' ';
	}

	//cout << "Grab last number in match: " << matchLine << endl;
	//for (int i = 0; i < 20; i++) cout << match1Info[i] << endl;

	//cout << "Team Name" << teamName << endl;
	//cout << "Team data: " << playerData << endl;
}