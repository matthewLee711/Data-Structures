#include <string>
#include <vector>

using namespace std;

class LaserTag
{
private:
	//Match variables
	//int tagger;
	//int target;
	//int matchTime;
	//int hitLocation;

	//Team variables
	string teamName;
	string teamName2;
	//int* id;
	//int* points;

	//number of players, will be used for counting
	int playerCounter;

	//line from match
	string matchLine;

	//string array to hold passed info from main -- will be used by token
	string matchLineTeam;
	string matchLineTeam2;

	//int array to hold id's of tagger players
	vector <int> tagger;

	//int array to hold it's of tagged players
	vector <int> tagged;

	//Player match data will be stored and passed to array through this
	int playerData;

	//use it to total information
	int total;

	//dynamically allocated array to hold match info
	int *match1Info = new int[100];

	//vector for match information
	vector <int> matchHolder;


	//create a multiset, so you can easily grab points and whos been tagged?

	//private inner working funtions

public:
	//constructor
	LaserTag();
	
	//team functions
	void teamNameStore(string team);

	void teamNameStore2(string team);

	//team data organizer -- complex info is passed to teamDataPrivate
	void teamDataOrganizer(string teamData);

	void teamDataOrganizer2(string teamData2);

	//Collect detailed number stats
	void matchInformation(string match);

	//Number of players 
	void playerCount(string numberOfPlayers);

	//write to file
	void writeToFile();

	//Debug Print
	void print();

};
