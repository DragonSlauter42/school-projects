//Hunter Tyler -- CS 221 -- Graph Implementation
//First Edit: 11/5/2024
//Last Edit: 11/5/2024 //Finished:
//GameGraph.h

#ifndef GAMEGRAPH_H
#define GAMEGRAPH_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define NUMROOMS 20

struct Room
{
		char	m_sRoomName[64]; //takes up to 63 characters, including spaces.
		char	m_sRoomDesc[128]; //takes up to 127 characters, including spaces.
		char	m_sItemName[32]; //takes up to 31 characters, including spaces.
		char	m_sCreatureName[64]; //takes up to 63 characters, including spaces.
		char 	m_cDirections[6]; //0 is North, 1 is East, 2 is South, 3 is West, 4 is Up, 5 is Down
};

class GameGraph
{
	private:
		ifstream	m_InFile;					// File to read from
		char        m_cAdjMatrix[NUMROOMS][NUMROOMS]; 
		Room		m_Rms[NUMROOMS];
		int			m_iLocation;	// Index of current room location

	private:
		void getNextLine(char *line, int lineLen);
		void setLink(int roomIdx, int linkIdx, char dCode);
		void describeRoom(int roomIdx);

	public:
		GameGraph();						// Class constructor
		~GameGraph();						// Class destructor
		bool LoadGame(char *fileName);	// Read game file, build scenario
		                                // and describe first room.
		bool doCommand(char *cmd);		// Execute a command
		void PrintAll();
};

#endif