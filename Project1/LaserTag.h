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
	//int* id;
	//int* points;

	//number of players, will be used for counting
	int playerCounter;

	//line from match
	string matchLine;

	string matchLineTeam;

	//Player match data will be stored and passed to array through this
	int playerData;

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

	//team data organizer -- complex info is passed to teamDataPrivate
	void teamDataOrganizer(string teamData);

	//Collect detailed number stats
	void matchInformation(string match);

	//Number of players 
	void playerCount(string numberOfPlayers);

	//Debug Print
	void print();

};
