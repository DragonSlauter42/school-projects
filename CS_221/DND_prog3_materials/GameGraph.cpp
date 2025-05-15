//Hunter Tyler -- CS 221 -- Graph Implementation
//First Edit: 11/5/2024
//Last Edit: 11/30/2024 //Finished: 11/11/2024 Added comments and checked for the substr() parts.
//GameGraph.cpp

#include <iostream> //copied from the .h I removed stdlib.h
#include <fstream>
#include <string.h>
#include "GameGraph.h"


GameGraph::GameGraph() // Default Constructor
{
    for (int i = 0; i < NUMROOMS; i++)
    {
        for (int j = 0; j < NUMROOMS; j++)
        {
            m_cAdjMatrix[i][j] = '-';  // Initialize the whole matrix with '-'
        }
    }
}


GameGraph::~GameGraph() //Default Destructor
{

}

//Private Functions
void GameGraph::getNextLine(char *line, int lineLen) //Taken from Snippets.txt
{
    int done = false;

    while(!done)
    {
        m_InFile.getline(line, lineLen);  
        // Note: m_InFile is an ifstream object that is part of the GameGraph class

        if(m_InFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return;
        }
    } // end while
}

void GameGraph::setLink(int roomIdx, int linkIdx, char dCode) //0 is North, 1 is South, 2 is East, 3 is West, 4 is Up, 5 is Down
{

    char dir = dCode; //Earlier it gave me issues if I did not do this. was too lazy to remove once I finished.
    if(linkIdx == -1)
    {    
        if(dir == 'N')
            {
                m_Rms[roomIdx].m_cDirections[0] = 'Q';
                return;
            }else if(dir == 'S')
            {
                m_Rms[roomIdx].m_cDirections[1] = 'Q';
                return;
            }else if(dir == 'E')
            {
                m_Rms[roomIdx].m_cDirections[2] = 'Q';
                return;
            }else if(dir == 'W')
            {
                m_Rms[roomIdx].m_cDirections[3] = 'Q';
                return;
            }else if(dir == 'U')
            {
                m_Rms[roomIdx].m_cDirections[4] = 'Q';
                return;
            }else 
            {
                m_Rms[roomIdx].m_cDirections[5] = 'Q';
                return;
            }  
    }

    if(dir == 'N')
    {
        m_Rms[roomIdx].m_cDirections[0] = dCode;
    }else if(dir == 'S')
    {
        m_Rms[roomIdx].m_cDirections[1] = dCode;
    }else if(dir == 'E')
    {
        m_Rms[roomIdx].m_cDirections[2] = dCode;
    }else if(dir == 'W')
    {
        m_Rms[roomIdx].m_cDirections[3] = dCode;
    }else if(dir == 'U')
    {
        m_Rms[roomIdx].m_cDirections[4] = dCode;
    }else 
    {
        m_Rms[roomIdx].m_cDirections[5] = dCode;
    }
    m_cAdjMatrix[roomIdx][linkIdx] = dir;

}

void GameGraph::describeRoom(int roomIdx)
{
    cout << m_Rms[roomIdx].m_sRoomName << "\n";
    cout << m_Rms[roomIdx].m_sRoomDesc << "\n";
    cout <<"There is a " << m_Rms[roomIdx].m_sItemName << " in the room." << "\n";
    cout <<"There is a " << m_Rms[roomIdx].m_sCreatureName << " in the room." << "\n";
    if(m_Rms[roomIdx].m_cDirections[0] =='N')
    {
        cout << "There is a door on the North wall." << "\n";
    }//else
    // {
    //     cout << "The North wall is empty." << "\n";
    // }

    if(m_Rms[roomIdx].m_cDirections[1] == 'S')
    {
        cout << "There is a door on the South wall." << "\n";
    }//else
    // {
    //     cout << "The East wall is empty." << "\n";
    // }

    if(m_Rms[roomIdx].m_cDirections[2] == 'E')
    {
        cout << "There is a door on the East wall." << "\n";  
    }//else
    // {
    //     cout << "The South wall is empty." << "\n";
    // }
    
    if(m_Rms[roomIdx].m_cDirections[3] == 'W')
    {
        cout << "There is a door on the West wall." << "\n";
    }//else
    // {
    //     cout << "The West wall is empty." << "\n";
    // }

    if(m_Rms[roomIdx].m_cDirections[4] =='U')
    {
        cout << "There is a stairway going up." << "\n";
    }//else
    // {
    //     cout << "There is no stairway going up." << "\n";
    // }
    if(m_Rms[roomIdx].m_cDirections[5] == 'D')
    {
        cout << "There is a stairway going down." << "\n";
    }//else
    // {
    //     cout << "There is no stairway going down." << "\n";
    // }

    cout << "\n";

}



//Public Functions
bool GameGraph::LoadGame(char *fileName) //taken from Snippets.txt 
{
    char line[128]; //Up to 127 Characters
    int link;

    m_InFile.open(fileName, ifstream::in); 
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        return false;
    }

    for(int i = 0; i < NUMROOMS; i++)
    {
        // Read room name
        getNextLine(line, 128);
        /* --- Copy room name into data structure i --- */
        strcpy(m_Rms[i].m_sRoomName, line);

        // Read room description
        getNextLine(line, 128);
        /* --- Copy room description into data structure i --- */
        strcpy(m_Rms[i].m_sRoomDesc, line);

        // Read room item
        getNextLine(line, 128);
        /* --- Copy room item name into data structure i --- */
        strcpy(m_Rms[i].m_sItemName, line);

        // Read room creature
        getNextLine(line, 128);
        /* --- Copy room creature name into data structure i --- */
        strcpy(m_Rms[i].m_sCreatureName, line);

        // Read North door
        getNextLine(line, 128);
        link = atoi(line); // Convert to room index
        // Call function to set link in adjacency matrix
        setLink(i, link, 'N');


        // Read South door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
        setLink(i, link, 'S');


        // Read East door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
        setLink(i, link, 'E');


        // Read West door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
        setLink(i, link, 'W');


        // Read up stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
        setLink(i, link, 'U');


        // Read down stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        // Call function to set link in adjacency matrix
        setLink(i, link, 'D');
    }
    describeRoom(m_iLocation);
    //PrintAll(); //Testing only.
    return true;
}

bool GameGraph::doCommand(char *cmd)
{ 
    string mycmd(cmd);
    if(mycmd == "QUIT")
    {
        cout << "Game is Closing" << endl;
        return true;
    }else if(mycmd == "GO NORTH")
    {
        if(m_Rms[m_iLocation].m_cDirections[0] == 'Q') //No exit means no exit.
        {
            cout << "You cannot move in that direction. Try another input." << "\n";
            return false;
        }
        for (int i = 0; i < NUMROOMS; i++) //Gotta find where the player is going right?
        {
            if (m_cAdjMatrix[m_iLocation][i] == 'N') 
            {
                m_iLocation = i;
                cout << "Going NORTH. New Room is:" << "\n";
                cout << "\n";
                describeRoom(m_iLocation);
                return false;
            }
        }
        
        return false;
    }else if(mycmd == "GO SOUTH")
    {
        if(m_Rms[m_iLocation].m_cDirections[1] != 'S') //No exit means no exit.
        {
            cout << "You cannot move in that direction. Try another input." << "\n";
            return false;
        }
        for (int i = 0; i < NUMROOMS; i++) //Repeating the aboce steps a gajillion times. Maybe I should do this recursively?
        {
            if (m_cAdjMatrix[m_iLocation][i] == 'S') 
            {
                m_iLocation = i;
                cout << "Going SOUTH. New Room is:" << "\n";
                cout << "\n";
                describeRoom(m_iLocation);
                return false;
            }
        }
        
        return false;
    }else if(mycmd == "GO EAST")
    {
        if(m_Rms[m_iLocation].m_cDirections[2] != 'E') //No exit means no exit.
        {
            cout << "You cannot move in that direction. Try another input." << "\n";
            return false;
        }
        for (int i = 0; i < NUMROOMS; i++) //Repeating the aboce steps a gajillion times. Maybe I should do this recursively?
        {
            if (m_cAdjMatrix[m_iLocation][i] == 'E') 
            {
                m_iLocation = i;
                cout << "Going EAST. New Room is:" << "\n";
                cout << "\n";
                describeRoom(m_iLocation);
                return false;
            }
        }

        return false;
    }else if(mycmd == "GO WEST")
    {
        if(m_Rms[m_iLocation].m_cDirections[3] != 'W') //No exit means no exit.
        {
            cout << "You cannot move in that direction. Try another input." << "\n";
            return false;
        }
        for (int i = 0; i < NUMROOMS; i++) //Door?
        {
            if (m_cAdjMatrix[m_iLocation][i] == 'W') 
            {
                m_iLocation = i;
                cout << "Going WEST. New Room is:" << "\n";
                cout << "\n";
                describeRoom(m_iLocation);
                return false;
            }
        }
        
        return false;
    }else if(mycmd == "GO UP")
    {
        if(m_Rms[m_iLocation].m_cDirections[4] != 'U') //No exit means no exit.
        {
            cout << "You cannot move in that direction. Try another input." << "\n";
            return false;
        }
        for (int i = 0; i < NUMROOMS; i++) //Beam me up Scotty.
        {
            if (m_cAdjMatrix[m_iLocation][i] == 'U') 
            {
                m_iLocation = i;
                cout << "Going UP. New Room is:" << "\n";
                cout << "\n";
                describeRoom(m_iLocation);
                return false;
            }
        }
        
        return false;
    }else if(mycmd == "GO DOWN") //We're all mad down here...
    {
        if(m_Rms[m_iLocation].m_cDirections[5] != 'D') //No exit means no exit.
        {
            cout << "You cannot move in that direction. Try another input." << "\n";
            return false;
        }
        for (int i = 0; i < NUMROOMS; i++) //No comment.
        {
            if (m_cAdjMatrix[m_iLocation][i] == 'D') 
            {
                m_iLocation = i;
                cout << "Going DOWN. New Room is:" << "\n";
                cout << "\n";
                describeRoom(m_iLocation);;
                return false;
            }
        }
        
        return false;
    }else if(mycmd.substr(0, 4) == "TAKE")
    {
        cout << "This is not yet implemented. Please try another input." << "\n";
        return false;
    }else if(mycmd.substr(0, 5) == "FIGHT")
    {
        cout << "This is not yet implemented. Please try another input." << "\n";
        return false;
    }else
    {
        cout << "Wrong Input. Please try again." << "\n";
        return false;
    }
    
}


void GameGraph::PrintAll()
{
    cout << "Adjancecy Matrix for the Rooms. " << endl;
    for (int i = 0; i < NUMROOMS; i++) 
    {
        for (int j = 0; j < NUMROOMS; j++) 
        {
            cout << m_cAdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    // cout << "All rooms and their descriptions:" << endl; //testing stuff
    // for (int i = 0; i < NUMROOMS; i++)
    // {
    //     describeRoom(i);
    // }
}
