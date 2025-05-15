/*
    Class: CS 214-02 Relation Check Programming Assignment
    File: RelationInputMain.cpp
    Name: Hunter Tyler
    Description: Programming Assingment for set relations.
    Date Started: 4/18/2025 Date Finished: 4/19/2025

    I attest that this program is entirely my own work.
*/

#include <iostream>
#include "RelationInputParser.h"

using namespace std;
#define MAX_RELATIONS 4 // Range is 0 to MAX_RELATIONS

char  *inputfilename[MAX_RELATIONS]; // This is the array that contains all the input relation filenames. 
char   Relation01xml[] = "Relation01.xml";
char   Relation02xml[] = "Relation02.xml";
char   Relation03xml[] = "Relation03.xml";
char   Relation04xml[] = "Relation04.xml";

int    relationsize;    // The order of the set S i.e., |S|.
string relationelement; // The elements of the set S. Need to make them strings. 
bool   rvalue;          // The boolean value returned by accessing the matrix of the relation. 


int main()
{
	// Initialize the array with the files that contain all the relations to check. 
	inputfilename[0] = Relation01xml;
	inputfilename[1] = Relation02xml;
	inputfilename[2] = Relation03xml;
	inputfilename[3] = Relation04xml;

	// inputfilename[0] = "Relation01.xml";  //This was your original code. Just comment out line 18-21 and 31-34 if needed. Or leave these commented out.
	// inputfilename[1] = "Relation02.xml";
	// inputfilename[2] = "Relation03.xml";
	// inputfilename[3] = "Relation04.xml";
	

	// Loop through all the files. 

	for (int k = 0; k < MAX_RELATIONS; k++)
	{
		printf("\n*********************************************************\n");
		printf("*********************************************************\n");
		printf("\nThe input Relation File is: %s\n", inputfilename[k]);
		RelationInputParser *lsdp = RelationInputParser::getInstance();	// Get the singleton
		lsdp->initDataParser(inputfilename[k]);

		// Print size of the relation printSize()
		relationsize = lsdp->getRelationSize();
		printf("Set size is: %d\n \n", relationsize);


		// Print the relation elements. 
		printf("The set S contains: \n  {");

		for (int i = 0; i < relationsize - 1; i++)
		{
			relationelement = lsdp->getElement(i);
			printf("%s, ", relationelement.c_str());
		}
		relationelement = lsdp->getElement(relationsize - 1);
		printf("%s} \n\n", relationelement.c_str());

		// Print the Boolean matrix of the relation
		printf("\n The Boolean Matrix of the relation R is: \n\n");

		for (int i = 0; i < relationsize; i++)
		{
			for (int j = 0; j < relationsize; j++)
			{
				rvalue = lsdp->getRelationElement(i, j);
				printf(" %x ", rvalue);
			}
			printf("\n");
		}


		// Print the ordered pairs of the relation. Not a perfect printing (extra ,) but close enough. 
		printf("\nThe ordered pairs of the relation R: \n");
		printf("{ ");

		for (int i = 0; i < relationsize; i++)
		{
			for (int j = 0; j < relationsize; j++)
			{
				rvalue = lsdp->getRelationElement(i, j);
				if (rvalue)
				{
					relationelement = lsdp->getElement(i);
					printf("(%s, ", relationelement.c_str());

					relationelement = lsdp->getElement(j);
					printf("%s),  ", relationelement.c_str());
				}
			}
		}
		printf("} \n");

		//
		//Students should enter their code to check the relation after this point. 
		//Hunter Tyler, CS 214-02
		/**
		 * Please note that at the top of the .cpp file, I had to rename the inputs. The compiler was giving me ISO errors trying to covert the names to a char array.
		 * I fixed this by making char arrays as variables that were the exact names of the input files. Then, where it was putting in the names, I took away the quotation marks
		 * to just be the new variables.		 Lines 18-21 & 31-34
		 */

		int rTally = 0;
		bool isSymmetric = true;
		bool isAntisymmetric = true;
		bool isAsymmetric = true;

		cout << endl;

		//Relxivity Code
		for (int i = 0; i < relationsize; i++)
		{
			rvalue = lsdp->getRelationElement(i,i);
			if(rvalue)
			{
				// cout << "True" << endl; debug
				rTally += 1;
			}else
			{
				// cout << "False" << endl; debug
			}
		}

		/** Symmetry Code					Tried doing this using a tally like above. Was having some trouble. Instead,
		*									I just set each relation for the set to be true. Search until I found the one piece that didn't follow the rules.
		*									Might update the rest. Not sure, I'll find out when I turn it in I guess.
		*/
		for (int i = 0; i < relationsize; i++)
		{
			for (int j = 0; j < relationsize; j++)
			{
				if (lsdp->getRelationElement(i, j))
				{
					if (lsdp->getRelationElement(j, i))
					{
						if (i != j)
						{
							isAntisymmetric = false;
							isAsymmetric = false;
						}
					}else
					{
						isSymmetric = false;
					}
		
					if (i == j)
					{
						isAsymmetric = false;
					}
				}
			}
		}
		

		

		printf("\nThe properties of the Relation R is as follows: \n\n");
			//Check rTally for reflexive and irreflexive

			if(rTally == relationsize)
			{
				cout << "Reflexive: Yes \nIrreflexive: No" << endl; //Reflexive
			}else if(rTally > 0 && rTally != relationsize)
			{
				cout << "Reflexive: No \nIrreflexive: No" << endl; //Neither
			}else
			{
				cout << "Reflexive: No \nIrreflexive: Yes" << endl; //Irreflexive
			}

			if (isSymmetric)
			{
				cout << "Symmetric: Yes" << endl;
			}else
			{
				cout << "Symmetric: No" << endl;			}

			if (isAntisymmetric)
			{
				cout << "Antisymmetric: Yes" << endl;
			}else
			{
				cout << "Antisymmetric: No" << endl;
			}			

			if (isAsymmetric)
			{
				cout << "Asymmetric: Yes" << endl;
			}else
			{
				cout << "Asymmetric: No" << endl;
			}

			if(!isSymmetric && !isAntisymmetric && !isAsymmetric)
			{
				cout << "Symmetric: No \nAsymmetric: No \nAntisymmetric: No" << endl;
			}

	} // end for k loop for the input data files.	

	
} // end main
