#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <ostream>
#include <iterator>
#include <vector>

using namespace std;


//functions
void print(const std::string& item)
{
	string setHolder[2];
	//std::cout << item << std::endl;
	string store = item;
	//setHolder[0] = store.begin + 3;
	string::iterator it;
	//advance(it, 1);
	//it + 3;
	//std::distance(store.begin(), it);
	//it - store.begin();

	//setHolder[0] = item;
	//setHolder[1] = item;
	cout << setHolder[0]; //<< setHolder[1];
}

//Sort the points earned for each player
void sortThePoints(int* teamNumTags, int* sortedId, int* sortedTag, int numberPlayerTeam1, int numberPlayerTeam2)
{
	// SORTING TEAM 1 FIRST

	// Transfering all the data form teamNumTags to sortedTag
	for (int playerCount = 0; playerCount <= numberPlayerTeam1 + numberPlayerTeam2; playerCount++)
		sortedTag[playerCount] = teamNumTags[playerCount];

	// filling sortedID with 0 to number of players
	for (int playerCount = 0; playerCount <= numberPlayerTeam1 + numberPlayerTeam2; playerCount++)
		sortedId[playerCount] = playerCount;


	// Start of Bubble Sorting team 1
	int playerCount2 = 0;  // this is the start Location for sorting
	int swapVarible = 0;

	for (int playerCount = 1; playerCount <= numberPlayerTeam1 - 1; playerCount++)
	{
		playerCount2 = playerCount + 1;     // starting point for sweep comparison
		while (playerCount2 <= numberPlayerTeam1)
		{
			/*
			if (sortedTag[playerCount] == sortedTag[playerCount2])
			{
			if (sortedId[playerCount] > sortedId[playerCount2])
			{
			swapVarible = sortedTag[playerCount2];
			sortedTag[playerCount2] = sortedTag[playerCount];
			sortedTag[playerCount] = swapVarible;

			swapVarible = sortedId[playerCount2];
			sortedId[playerCount2] = sortedId[playerCount];
			sortedId[playerCount] = swapVarible;
			}
			}

			if (sortedTag[playerCount] == sortedTag[playerCount2])
			{
			if (sortedId[playerCount] > sortedId[playerCount2])
			{
			swapVarible = sortedTag[playerCount2];
			sortedTag[playerCount2] = sortedTag[playerCount];
			sortedTag[playerCount] = swapVarible;

			swapVarible = sortedId[playerCount2];
			sortedId[playerCount2] = sortedId[playerCount];
			sortedId[playerCount] = swapVarible;
			}
			}
			*/

			if (sortedTag[playerCount] < sortedTag[playerCount2]) // if it is greater swap varibles
			{
				swapVarible = sortedTag[playerCount2];
				sortedTag[playerCount2] = sortedTag[playerCount];
				sortedTag[playerCount] = swapVarible;

				swapVarible = sortedId[playerCount2];
				sortedId[playerCount2] = sortedId[playerCount];
				sortedId[playerCount] = swapVarible;

			}
			playerCount2++;     // increment playerCount2

		} //end of while loop

	} // end of for loop

	  // Start of bubble sorting for team 2

	  //		playerCount2 = numberPlayerTeam1+1;  // this is the start Location for sorting
	swapVarible = 0;

	for (int playerCount = numberPlayerTeam1 + 1; playerCount <= (numberPlayerTeam1 + numberPlayerTeam2 - 1); playerCount++)
	{
		playerCount2 = playerCount + 1;     // starting point for sweep comparison
		while (playerCount2 <= (numberPlayerTeam1 + numberPlayerTeam2))
		{
			if (sortedTag[playerCount] < sortedTag[playerCount2]) // if it is greater swap varibles
			{
				swapVarible = sortedTag[playerCount2];
				sortedTag[playerCount2] = sortedTag[playerCount];
				sortedTag[playerCount] = swapVarible;

				swapVarible = sortedId[playerCount2];
				sortedId[playerCount2] = sortedId[playerCount];
				sortedId[playerCount] = swapVarible;


			}
			playerCount2++;     // increment playerCount2
		}//End of While loop

	}//End of for loop
	cout << "sorted points" << sortedId[0] << sortedTag[0] << teamNumTags[0] << endl;
	cout << "sorted points" << sortedId[1] << sortedTag[1] << teamNumTags[1] << endl;
	cout << "sorted points" << sortedId[2] << sortedTag[2] << teamNumTags[2] << endl;
	cout << "sorted points" << sortedId[3] << sortedTag[3] << teamNumTags[3] << endl;
	cout << "sorted points" << sortedId[4] << sortedTag[4] << teamNumTags[4] << endl;
	cout << "sorted points" << sortedId[5] << sortedTag[5] << teamNumTags[5] << endl;
	cout << "sorted points" << sortedId[6] << sortedTag[6] << teamNumTags[6] << endl;
	return;
}

void  sortTheTags(int* teamNumTags, int* sortedId, int* sortedTag, int numberPlayerTeam1, int numberPlayerTeam2)
{
	// SORTING TEAM 1 FIRST

	// Transfering all the data form teamNumTags to sortedTag
	for (int playerCount = 0; playerCount <= numberPlayerTeam1 + numberPlayerTeam2; playerCount++)
		sortedTag[playerCount] = teamNumTags[playerCount];

	// filling sortedID with 0 to number of players
	for (int playerCount = 0; playerCount <= numberPlayerTeam1 + numberPlayerTeam2; playerCount++)
		sortedId[playerCount] = playerCount;


	// Start of Bubble Sorting team 1
	int playerCount2 = 0;  // this is the start Location for sorting
	int swapVarible = 0;

	for (int playerCount = 0; playerCount <= numberPlayerTeam1 - 2; playerCount++)
	{
		playerCount2 = playerCount + 1;     // starting point for sweep comparison
		while (playerCount2 <= numberPlayerTeam1 - 1)
		{
			/*
			if (sortedTag[playerCount] == sortedTag[playerCount2])
			{
			if (sortedId[playerCount] > sortedId[playerCount2])
			{
			swapVarible = sortedTag[playerCount2];
			sortedTag[playerCount2] = sortedTag[playerCount];
			sortedTag[playerCount] = swapVarible;

			swapVarible = sortedId[playerCount2];
			sortedId[playerCount2] = sortedId[playerCount];
			sortedId[playerCount] = swapVarible;
			}
			}

			if (sortedTag[playerCount] == sortedTag[playerCount2])
			{
			if (sortedId[playerCount] > sortedId[playerCount2])
			{
			swapVarible = sortedTag[playerCount2];
			sortedTag[playerCount2] = sortedTag[playerCount];
			sortedTag[playerCount] = swapVarible;

			swapVarible = sortedId[playerCount2];
			sortedId[playerCount2] = sortedId[playerCount];
			sortedId[playerCount] = swapVarible;
			}
			}
			*/

			if (sortedTag[playerCount] < sortedTag[playerCount2]) // if it is greater swap varibles
			{
				swapVarible = sortedTag[playerCount2];
				sortedTag[playerCount2] = sortedTag[playerCount];
				sortedTag[playerCount] = swapVarible;

				swapVarible = sortedId[playerCount2];
				sortedId[playerCount2] = sortedId[playerCount];
				sortedId[playerCount] = swapVarible;

			}
			playerCount2++;     // increment playerCount2

		} //end of while loop

	} // end of for loop

	  // Start of bubble sorting for team 2

	  //		playerCount2 = numberPlayerTeam1+1;  // this is the start Location for sorting
	swapVarible = 0;

	for (int playerCount = numberPlayerTeam1; playerCount <= (numberPlayerTeam1 + numberPlayerTeam2 - 2); playerCount++)
	{
		playerCount2 = playerCount + 1;     // starting point for sweep comparison
		while (playerCount2 <= (numberPlayerTeam1 + numberPlayerTeam2 - 1))
		{
			if (sortedTag[playerCount] < sortedTag[playerCount2]) // if it is greater swap varibles
			{
				swapVarible = sortedTag[playerCount2];
				sortedTag[playerCount2] = sortedTag[playerCount];
				sortedTag[playerCount] = swapVarible;

				swapVarible = sortedId[playerCount2];
				sortedId[playerCount2] = sortedId[playerCount];
				sortedId[playerCount] = swapVarible;


			}
			playerCount2++;     // increment playerCount2
		}//End of While loop

	}//End of for loop
	cout << "sorted tags" << sortedId[0] << sortedTag[0] << teamNumTags[0] << endl;
	cout << "sorted tags" << sortedId[1] << sortedTag[1] << teamNumTags[1] << endl;
	cout << "sorted tags" << sortedId[2] << sortedTag[2] << teamNumTags[2] << endl;
	cout << "sorted tags" << sortedId[3] << sortedTag[3] << teamNumTags[3] << endl;
	cout << "sorted tags" << sortedId[4] << sortedTag[4] << teamNumTags[4] << endl;
	cout << "sorted tags" << sortedId[5] << sortedTag[5] << teamNumTags[5] << endl;
	return;
}


// This function gets an integer from a string with a specfied column
// and returns the value in that column
int getIntFromString(string teamData, int selectColumn)
{
	int chooseColumn = selectColumn;
	int theAns = 0;
	int columnCount = 1;
	string delimiter = " ";
	string teamData2 = teamData;
	size_t pos = 0;
	string token;
	while ((pos = teamData2.find(delimiter)) != std::string::npos) {

		token = teamData2.substr(0, pos);
		if (columnCount == chooseColumn)
			theAns = stoi(token) - 1;
		teamData2.erase(0, pos + delimiter.length());
		//cout << "columnCount: " << columnCount << ", the ans:" << " " << theAns << ", token: " << token << endl;
		columnCount++;
	}
	if (chooseColumn == 4)
	{
		//teamData2.erase(0, pos + delimiter.length());
		token = teamData2.substr(0, pos);
		theAns = stoi(token);
		//cout << "ANs exiting: " << theAns << endl;
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
		else if (team1Counter > 1)
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

	//Team Name Sorter
	/*set <string> teamNameOrder; //= team1Name + ' ' + team2Name;
	teamNameOrder.insert(team1Name); teamNameOrder.insert(team2Name);
	for_each(teamNameOrder.begin(), teamNameOrder.end(), &print);*/

	//Team Name Sorter
	/*int result;
	char* teamNameStoreSort[30] = ;
	//Performs a run through number of strings
	for (int pass = 0; pass < size - 1; ++pass) {
	//Runs through each string for compare
	for (int j = 0; j < size - 1 - pass; ++j) {

	}*/



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
		//if match counter is zero, dynamically allocate memory for arrays
		if (matchCounter == 0)
		{
			matchSize = stoi(matchData);
			//dynamic memory allocation for arrays
			teamNumberOfTags = new int[teamSize];
			teamScore = new int[teamSize];

			for (int i = 0; i < teamSize; i++)
			{
				teamNumberOfTags[i] = 0;
				teamScore[i] = 0;
			}
		}
		//This counts how many times who tagged who and stores this into 2D array, 
		//This also counts points for each player and stores this into according arrays
		else
		{
			//cout << "MatchDataLine" << matchCounter << " " << matchData << endl;
			//1st column of 2D is used to keep track of how many times someone hit someone else
			//Everytime someone is hit, this goes to the 1st column and the id (row) is increased by one 
			cout << "MatchData passed: " << matchData << endl;
			int tagY = getIntFromString(matchData, 1);//y coordinate in 2D array
			cout << "tagY: " << tagY << endl;
			int tagX = getIntFromString(matchData, 2);//x coordinate in 2D array
			cout << "tagX: " << tagX << endl;
			//This goes to exact position in 2D array and tracks who hit who. Extra hits are added on top of existing number
			matchInformationStore[tagX + (tagY * teamSize)] = matchInformationStore[tagX + (tagY * teamSize)] + 1;
			//cout << "matchInforstore: " << matchInformationStore[tagX + (tagY * teamSize)] << endl;

			//cout << "MatchInformation Store being passed: " << matchInformationStore[tagX + (tagY * teamSize)] << endl;
			//matchInformationStore[tagX + (tagY * teamSize)]++;

			teamNumberOfTags[tagY]++;//Keeps track of number of tags each player got
									 //teamNumberOfTags[5] = 4;
									 //int test = stoi(matchData.substr(8).append(matchData.substr(0, 1)));
									 //int* test = (int*)5;
									 //int test = getIntFromString(matchData, 4);
			teamScore[tagY - 1] = teamScore[tagY - 1] + getIntFromString(matchData, 4);//Keeps score for each player


		}//End of else

		matchCounter++;
	}

	//MEDIUM VERBOSITY -- How many hits each person got
	for (int i = 0; i < teamSize; i++) cout << "TeamNumber of tags " << teamIndividualNames[i] << " hit: " << teamNumberOfTags[i] << endl;

	//Medium Verbosity -- How many points each person got
	for (int i = 0; i < teamSize; i++) cout << "TeamScore " << teamIndividualNames[i] << " got: " << teamScore[i] << endl;

	//debug output statement for matchInformationStore
	//int k = 0;
	for (int i = 0; i < teamSize; i++)
	{
		for (int j = 0; j < teamSize; j++)
		{
			cout << matchInformationStore[j + (6 * i)];
			//cout << teamIndividualNames[i];

		}
		cout << teamIndividualNames[i] << endl;
	}

	//Organize output of who hit who
	//Variable and array declaration for this
	//int* teamNumTags = new int[20];
	int* sortedId = new int[teamSize]; //Create Id tag array to be sorted based on sortedTag
	int* sortedTag = new int[teamSize]; //Create a tag array to be sorted
	int numberPlayerTeam1 = 0;
	int numberPlayerTeam2 = 0;

	//Function to output who hit who
	sortTheTags(teamNumberOfTags, sortedId, sortedTag, team1Size, team2Size);

	int* sortedIdPoints = new int[teamSize]; //Create Id tag array to be sorted based on sortedTag
											 //int* sortedTag = new int[teamSize]; //Create a tag array to be sorted

	sortThePoints(teamScore, sortedIdPoints, sortedTag, team1Size, team2Size);

	//Output sorted information
	for (int i = 0; i < 6; i++)
	{
		//cout << "Name: " << teamIndividualNames[sortedId[i]] << " got " << sortedTag[i] << endl;
	}
	for (int i = 0; i < 6; i++)
	{
		//cout << "Name: " << sortedId[i] << " got " << sortedTag[i] << endl;
	}

	//Choose Verbosity you want
	string enterVerbosityChoice;

	//While loop to let you choose verbosity output
	int teamOutputCounter = 0;
	bool stop = true;
	while (stop != false)
	{
		cout << "Choose the verbosity output you would like of the game: \n"
			<< "'vlow' is Low Verbosity and shows the total score and who won.\n"
			<< "'vmed' is Medium Verbosity and shows how many tags each player got and the individual best score of both teams. \n"
			<< "'vhigh' is High Verbosity and shows exactly who hit who and shows the winning team. \n";
		cout << "Please enter a choice: "; cin >> enterVerbosityChoice; cout << endl;


		//conditional to output choice
		if (enterVerbosityChoice == "vlow")
		{
			//lowVerbosity
			//can insert function and return
		}
		if (enterVerbosityChoice == "vmed")
		{
			//mediumverbosity
			//Display team name and number of tags each player in team1 made
			cout << team1Name << ": " << endl << endl;
			while (teamOutputCounter != team1Size)
			{
				//cout << "Name: " << teamIndividualNames[sortedId[teamOutputCounter]] << " got " << sortedTag[teamOutputCounter] << endl;
				teamOutputCounter++;
			}

			cout << endl;
			//Display team name and number of tags each player in team2 made
			cout << team2Name << ": " << endl << endl;
			//for (int i = team1Size; i < teamSize; i++) cout << "Name: " << teamIndividualNames[sortedId[i]] << " got " << sortedTag[i] << endl;

			cout << "Best score from " << team1Name << ": ";
			cout << "Best score from " << team2Name << ": ";
		}
		if (enterVerbosityChoice == "vhigh")
		{
			//highVerbosity

		}

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