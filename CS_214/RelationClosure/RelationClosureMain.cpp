/*
    Class: CS 214-02 Relation Closure Programming Assignment
    File: RelationClosureMain.cpp
    Name: Hunter Tyler
    Description: Programming Assingment for set relations and their closure sets.
    Date Started: 4/27/2025 Date Finished: 4/27/2025

    I attest that this program is entirely my own work.
*/

#include <iostream>
#include "RelationInputParser.h"

using namespace std;
#define MAX_RELATIONS 4 // Range is 0 to MAX_RELATIONS

void warshallAlgorithm(bool** relationMatrix, int relationsize);

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

		// Dynamically allocate the relation matrix
        bool** relationMatrix = new bool*[relationsize];
        for (int i = 0; i < relationsize; i++) {
            relationMatrix[i] = new bool[relationsize]();  // Initialize to false
        }

        for (int i = 0; i < relationsize; i++)
        {
            for (int j = 0; j < relationsize; j++)
            {
                rvalue = lsdp->getRelationElement(i, j);
                relationMatrix[i][j] = rvalue;
                //printf(" %x ", rvalue);
            }
        }

		bool** originalMatrix = new bool*[relationsize]; //copy of  the original to check back at later
		for (int i = 0; i < relationsize; i++) 
		{
			originalMatrix[i] = new bool[relationsize];
			for (int j = 0; j < relationsize; j++) 
			{
				originalMatrix[i][j] = relationMatrix[i][j];
			}
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
		 * to just be the new variables.		 Lines 19-21 & 31-34
		 */

		
		bool isReflexive = true;
		bool isIrreflexive = true;
		bool isSymmetric = true;
		bool isAntisymmetric = true;
		bool isAsymmetric = true;

		//new code for the project
		bool isTransitive = true;
		bool isPartial0rder = false;
		bool isEquilvalence0rder = false;
		//arrays for closure
		string reflexiveClosure[relationsize] = {};
		int rTally = 0;

		string symmetricFirst[relationsize * relationsize] = {};
		string symmetricSecond[relationsize * relationsize] = {};
		int sTally = 0;
		//transitive stuff

		cout << endl;

		//Relxivity Code
		for(int i = 0; i < relationsize; i++)
		{
			rvalue = lsdp->getRelationElement(i,i);
			if(rvalue)
			{
				isIrreflexive = false;
			}else if(!rvalue)
			{
				isReflexive = false;
				reflexiveClosure[i] = lsdp->getElement(i);
				rTally += 1;
			}
		}


		//Symmetry Code
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
						symmetricFirst[sTally] = lsdp->getElement(j);
						symmetricSecond[sTally] = lsdp->getElement(i);
						sTally += 1;
					}
		
					if (i == j)
					{
						isAsymmetric = false;
					}
				}
			}
		}
		

		//transitive code //decided to a function.
        warshallAlgorithm(relationMatrix, relationsize);

		printf("\nThe properties of the Relation R is as follows: \n\n");
			if(isReflexive)
			{
				cout << "Reflexive: Yes \nIrreflexive: No" << endl; //Reflexive
			}else if(!isReflexive && !isIrreflexive)
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
				cout << "Symmetric: No" << endl;			
			}

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

			//Partiol Ordering:
			if(isReflexive && isAntisymmetric && isTransitive)
			{
				cout << "Partial Order: Yes" << endl;
			}else 
			{
				cout << "Partial Order: No" << endl;
			}

			//Equivalence Order
			if(isReflexive && isSymmetric && isTransitive)
			{
				cout << "Equivalence Relation: Yes" << endl;
			}else 
			{
				cout << "Equivalence Relation: No" << endl;
			}
			//Closures:
			for (int i = 0; i < relationsize; i++) 
			{
				for (int j = 0; j < relationsize; j++) 
				{
					if (lsdp->getRelationElement(i, j)) 
					{// (i,j)
						for (int k = 0; k < relationsize; k++) 
						{
							if (lsdp->getRelationElement(j, k)) 
							{// if (j k) then (i, k)
								if (!lsdp->getRelationElement(i, k)) 
								{ // if ((i, k) does not exist
									isTransitive = false; //(i, k) doesn't exist. It is not transitive.
								}
							}
						}
					}
				}
			}

			if (isTransitive)
			{
				cout << "Transitive: Yes" << endl;
			}else
			{
				cout << "Transitive: No" << endl;
			}
			//Reflexive
			if (rTally > 0)
			{
				cout << "\nThe reflexive closure set for R is: ";
				cout << "{ ";
				bool first = true;
				for (int i = 0; i < relationsize; i++)
				{
					if (reflexiveClosure[i] != "")
					{
						if (!first)
							cout << ", ";
						cout << "(" << reflexiveClosure[i] << ", " << reflexiveClosure[i] << ")";
						first = false;
					}
				}
				cout << " }";
			}
			else
			{
				cout << "\nThe reflexive closure of the relation R is: {  }";
			}
			
			//Symmetric
			if (sTally > 0)
			{
				cout << "\nThe symmetric closure set for R is: ";
				cout << "{ ";
				for (int i = 0; i < sTally; i++)
				{
					cout << "(" << symmetricFirst[i] << ", " << symmetricSecond[i] << ")";
					if (i != sTally - 1)
						cout << ", ";
				}
				cout << " }";
			}
			else
			{
				cout << "\nThe symmetric closure of the relation R is: {  }";
			}

			//Transitive
			printf("\nThe transitive closure of the relation R is: ");
			bool firstPair = true; //formatting issues/
			cout << "{ ";
			for (int i = 0; i < relationsize; i++) {
				for (int j = 0; j < relationsize; j++) {
					// Only print the pair if it was added by the transitive closure
					if (relationMatrix[i][j] && originalMatrix[i][j] == false) {
						if (!firstPair) {
							cout << ", ";  // Add a comma before each pair except the first
						}
						// Print the ordered pair
						cout << "(" << lsdp->getElement(i) << ", " << lsdp->getElement(j) << ")";
						firstPair = false;  // After the first pair, set firstPair to false
					}
				}
			}
			cout << " }" << endl;
	
			// Cleanup
			for (int i = 0; i < relationsize; i++) 
			{
				delete[] relationMatrix[i];
			}
			delete[] relationMatrix;

	} // end for k loop for the input data files.	

	
} // end main


void warshallAlgorithm(bool** relationMatrix, int relationsize) 
{
    for (int k = 0; k < relationsize; k++) 
	{
        for (int i = 0; i < relationsize; i++) 
		{
            for (int j = 0; j < relationsize; j++) 
			{
                relationMatrix[i][j] = relationMatrix[i][j] || (relationMatrix[i][k] && relationMatrix[k][j]);
            }
        }
    }
}