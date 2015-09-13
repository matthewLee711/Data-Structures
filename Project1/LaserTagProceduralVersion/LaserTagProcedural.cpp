#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//functions
void tagger(int tagger)
{
	
}

// This function gets an integer from a string with a specfied column
// and returns the value in that column
int getIntFromString(string teamData, int selectColumn)
{
	int theAns = 88888;
	int columnCount = 1;
	string delimiter = " ";
	string teamData2 = teamData;
	size_t pos = 0;
	string token;
	while ((pos = teamData2.find(delimiter)) != std::string::npos) {

		token = teamData2.substr(0, pos);
		if (columnCount == selectColumn) theAns = stoi(token);
		teamData2.erase(0, pos + delimiter.length());
		columnCount++;
	}
	return theAns;
}

//This function takes each element from match1 and sends data to according arrays
void matchDataOrganizer(string matchData)
{
	/*
	//string delimeter to get rid of spaces
	string delimiter = " ";

	//store data into this string which will later be parsed
	string matchDataSort = matchData;

	//variable will send id to array
	int playerData;

	//Counter for while loop to help determine which array to send information to
	int infoCounter = 1;

	//This function is focused on deleting the spaces in the string and extract info
	//start at position zero in string
	size_t pos = 0;
	//token string stores info from matchLine
	std::string token;
	//While loop focuses on finding the delimiter ' ', removing it, and send match data to specific arrays
	while ((pos = matchDataSort.find(delimiter)) != std::string::npos) {
		//stores each character or number
		token = matchDataSort.substr(0, pos);
		//std::cout << "token: " << token << std::endl;//output info from token

		//Convert (string) token to int Send token to function to count who's been hit
		playerData = stoi(token);

		//deletes the time
		if (playerData >= 100)
		{
			playerData = 0;//delete element by set to zero
			infoCounter++;
			//include statement to gather score! -- if number 3 = 3 = points
		}
		else
		{
			//send to tagged vector
			//pass back to main
			//main(playerData);
			

			infoCounter++;
		}

		//Medium Verbosity
		//mediumVerbosity(taggerId, matchDataSort);
		//make sure to put matchline team into string vector

		infoCounter++;
		cout << "output matchDataSort: " << matchDataSort << endl;
		matchDataSort.erase(0, pos + delimiter.length());//delete and move up
	}

	//cout << "matchLine" << matchLine << endl;
	//cout << "TeamName: " << teamName << endl;

	*/
}

int main(int playerData)
{
	//Open Files
	ifstream team1;
	team1.open("cowboys.txt");
	ifstream team2;
	team2.open("sharks.txt");
	ifstream match1;
	match1.open("match.txt");

	//temporary teamdata storer
	string team1Data;
	string team2Data;
	string matchData;

	//Variables
	//Team total score
	int team1TotalScore = 0;
	int team2TotalScore = 0;
	//Team Number of players
	int team1NumberOfPlayers = 0;
	int team2NumberOfPlayers = 0;
	//Team Name
	string team1Name;
	string team2Name;
	//team and match array size
	int team1Size;
	int team2Size;
	int matchSize;


	//Finds size of # of players and dynamically allocated array for that
	/*int team1SizeCounter = 0;
	while (getline(team1, team1Data))
	{
		
		if (team1SizeCounter == 1)
		{
			team1Size = stoi(team1Data);
		}
		cout << "teamData" << team1Data << endl;
		team1SizeCounter++;
	}
	int team2SizeCounter = 0;
	while (getline(team2, team2Data))
	{
		if (team2SizeCounter == 1)
		{
			team2Size = stoi(team2Data);
		}
		team2SizeCounter++;
	}
	int teamSize;
	teamSize = team1Size + team2Size;
	cout << "Team size: " << teamSize << endl;*/

	//string array to store team names
	string* team1IndividualNames;
	string* team2IndividualNames;

	//int team2indexPlacement = 0;
	//This while loop will send team1's data to according arrays
	int team1Counter = 0;
	int team1IndexPlacement = 0;//this counter is extremely important
	while (getline(team1, team1Data))
	{
		//cout << "This is team counter: " << team1Counter << endl;
		//cout << "teamData" << teamCounter << team1Data << endl;
		//if team counter is zero, store team name
		if (team1Counter == 0)
		{
			team1Name = team1Data;
		}
		else if (team1Counter == 1)
		{
			team1Size = stoi(team1Data);
			team1IndividualNames = new string[team1Size];
		}
		//delete id number in front of name and put name into "team1IndividualNames" string array
		else if(team1Counter > 1)
		{ 
			team1IndividualNames[team1IndexPlacement] = team1Data.substr(2).append(team1Data.substr(0, 0));
			//cout << "team1IndividualNames: " << team1IndividualNames[1] << endl;
			team1IndexPlacement++;
		}
		//cout << "This is team COunter";
		team1Counter++;
		//cout << "teamcounter: " << teamCounter << endl;
	}
	//cout << "what?" << endl;

	//This while loop will send team2's data to according arrays
	int team2Counter = 0;
	int team2IndexPlacement = 0;
	while (getline(team2, team2Data))
	{
		//cout << team2Data << endl;
		//if team counter is zero, store team name
		if (team2Counter == 0)
		{
			team2Name = team2Data;
		}
		else if (team2Counter == 1)
		{
			team2Size = stoi(team2Data);
			team2IndividualNames = new string[team2Size];
		}
		//delete id number in front of name and put name into "team2IndividualNames" string array
		else if (team2Counter > 1)
		{
			team2IndividualNames[team2IndexPlacement] = team2Data.substr(2).append(team2Data.substr(0, 0));
			//cout << "teamindividualnames: " << teamIndividualNames[teamIndexPlacement] << endl;
			//store all names into
			team2IndexPlacement++;
		}

		team2Counter++;
	}
	
	//debug output of team1/2 Individual arrays
	//for (int i = 0; i < team1Size; i++) cout << "teamindividualnames: "<< team1IndividualNames[i] << endl;
	//for (int i = 0; i < team2Size; i++) cout << "teamindividualnames: " << team2IndividualNames[i] << endl;

	//Combine both arrays into one
	int teamSize = team1Size + team2Size;
	string* teamIndividualNames = new string[teamSize];
	//cout << "Team size is: " << teamSize << endl;

	//while loop to concatenate both team individual arrays into one
	team2IndexPlacement = 0;
	int teamIndexPlacement = 0;
	//for (int i = 0; i < team1Size; i++) cout << "teamindividualnames: "<< team1IndividualNames[i] << endl;
	//initially place team1IndividualNames into teamIndividualNames
	int teamCounter = 0;
	while (teamCounter != team1Size)
	{
		//team1 names stored first based on team index
		teamIndividualNames[teamIndexPlacement] = team1IndividualNames[teamIndexPlacement];
		//teamIndividualNames[teamIndexPlacement] = team2IndividualNames[team2IndexPlacement];

		//cout << "team!!individualnames " << teamIndexPlacement << ": " << teamIndividualNames[teamIndexPlacement] << endl;
		//cout << "team counter: " << teamCounter << endl;
		//cout << "team2indexPlacement " << teamIndexPlacement << endl;
		teamIndexPlacement++;
		teamCounter++;
	}
	//cout << "First while loop works" << endl;
	//cout << "teamIndexplacement after loop " << teamIndexPlacement << endl;
	//Lastly, concatenate and place team2IndividualNames into teamIndividualNames
	teamCounter = 0;
	while (teamCounter != team2Size)
	{
		//team1 names stored first based on team index
		teamIndividualNames[teamIndexPlacement] = team2IndividualNames[team2IndexPlacement];
		//teamIndividualNames[teamIndexPlacement] = team2IndividualNames[team2IndexPlacement];

		//cout << "team!!individualnames " << teamIndexPlacement << ": " << teamIndividualNames[teamIndexPlacement] << endl;
		//cout << "team counter: " << teamCounter << endl;
		//cout << "team2indexPlacement " << teamIndexPlacement << endl;
		team2IndexPlacement++;
		teamIndexPlacement++;
		teamCounter++;//counter to end for loop
	}

	for (int i = 0; i < teamSize; i++) cout << "teamindividualnames: " << teamIndividualNames[i] << endl;

	//TRICK DYNAMICALLY ALLOCATED (2D) INT ARRAY TO HOLD WHO HIT WHO AND HOLD POINTS
	int * matchInformationStore = new int[teamSize * teamSize];

	//Magic equation to find any element in 2D array
	//column + (NumColumn * row)
	// x + (xMax * y);
	
	//int** matchInformationStore2 = new int*[teamSize][test];
	//set all elements in matchInformationStore to '0'
	for (int i = 0; i < teamSize*teamSize; i++)
	{
		matchInformationStore[i] = 0;
	}

	//debug output statement for matchInformationStore
	for (int i = 0; i < teamSize; i++)
	{
		for (int j = 0; j < teamSize; j++)
		{
			cout << matchInformationStore[i];

		}
		cout << endl;
	}

	//string teamData6 = "22 33 44 55";
	//int selectColumn6 = 2;
	//cout << getIntFromString(teamData6, selectColumn6) << endl;

	//Team Number of Tags (individuals)
	int* teamNumberOfTags;
	//Team Number of points (individuals)
	int* teamScore;

	//This while loop will send match data to according arrays
	int matchCounter = 0;
	while (getline(match1, matchData))
	{
		cout << matchData << endl;
		//if match counter is zero, dynamically allocate memory for arrays
		if (matchCounter == 0)
		{
			matchSize = stoi(matchData);
			//dynamic memory allocation for arrays
			teamNumberOfTags = new int[teamSize];
			teamScore = new int[teamSize];
		}
		//This counts how many times who tagged who and stores this into 2D array, 
		//This also counts points for each player and stores this into according arrays
		else
		{
			//cout << "MatchDataLine" << matchCounter << " " << matchData << endl;
			//1st column of 2D is used to keep track of how many times someone hit someone else
			//Everytime someone is hit, this goes to the 1st column and the id (row) is increased by one 

			int tagY = getIntFromString(matchData, 1);//y coordinate in 2D array
			int tagX = getIntFromString(matchData, 2);//x coordinate in 2D array
			
			//This goes to exact position in 2D array and tracks who hit who. Extra hits are added on top of existing number
			matchInformationStore[tagX +  (tagY * teamSize)]++;
			//matchInformationStore[tagX + (tagY * teamSize)]++;

			teamNumberOfTags[tagY]++;//Keeps track of number of tags each player got
			teamScore[tagY] = teamScore[tagY] + getIntFromString(matchData, 4);//Keeps score for each player

		}//End of else

		matchCounter++;
	}

	//debug output statement for matchInformationStore
	for (int i = 0; i < teamSize; i++)
	{
		for (int j = 0; j < teamSize; j++)
		{
			cout << matchInformationStore[i];

		}
		cout << endl;
	}
	
	//Player Name Arrays
	//string team1PlayerNames;
	//string team2PlayerNames;
	//Each Player Score Arrays
	//int* team1Score = new int[matchSize];
	//int* team2Score = new int[matchSize];
	//Match Point Array make sure it is 2D 
	int* team1Match = new int[matchSize];
	int* team2Match = new int[matchSize];
	//Number of Tags each person gets Array
	//int* team1NumberOfTags = new int[matchSize];
	//int* team2NumberOfTags = new int[matchSize];
	

	int dataCounter = 0;

	//While loop to place information in each array
	/*while (dataCounter != 100)
	{
		dataCounter++;
	}*/

	

}