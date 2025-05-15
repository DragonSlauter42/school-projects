//Hunter Tyler -- CS 221 -- Hashing Algorithims
//First Edit: 11/15/2024
//Last Edit: 11/22/2024 //Finished: 11/20/2024
//Tyler.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

struct hashStruct
{
    char key[5]; // Four-letter keys plus null terminator
    int data;
};

class hash_methods
{
private:
    static const int TABLESIZE = 100; // Table size remains static and constant
    static const int KEYSIZE = 4;
    const char emptyKey[5] = "----";

public:
    hash_methods();
    ~hash_methods();
    int hashInsert(const char key[], char data, int hashNum, int dHashNum);

    hashStruct hashTable[TABLESIZE];

    // Base Hash functions
    int hash_1(const char key[]);
    int hash_2(const char key[]);
    int hash_3(const char key[]);
    // Double Hash functions. Combination of the base function, plus another one.
    int probeDec_1(const char key[]);
    unsigned int probeDec_2(const char key[]);
    unsigned long probeDec_3(const char key[]);


};


hash_methods::hash_methods()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        strcpy(hashTable[i].key, emptyKey); // Initialize with emptyKey
        hashTable[i].data = 0;
    }
}

hash_methods::~hash_methods()
{
}

int hash_methods::hashInsert(const char key[], char data, int hashNum, int dHashNum)
{
    int testNum = (hashNum * 3) + dHashNum;
    int colCount = 0;
    int hashIndex, probeDec;

    switch (testNum)
    {
    case 0:
        hashIndex = hash_1(key);
        probeDec = probeDec_1(key);
        break;
    case 1:
        hashIndex = hash_1(key);
        probeDec = probeDec_2(key);
        break;
    case 2:
        hashIndex = hash_1(key);
        probeDec = probeDec_3(key);
        break;
    case 3:
        hashIndex = hash_2(key);
        probeDec = probeDec_1(key);
        break;
    case 4:
        hashIndex = hash_2(key);
        probeDec = probeDec_2(key);
        break;
    case 5:
        hashIndex = hash_2(key);
        probeDec = probeDec_3(key);
        break;
    case 6:
        hashIndex = hash_3(key);
        probeDec = probeDec_1(key);
        break;
    case 7:
        hashIndex = hash_3(key);
        probeDec = probeDec_2(key);
        break;
    case 8:
        hashIndex = hash_3(key);
        probeDec = probeDec_3(key);
        break;
    }

    while (strcmp(hashTable[hashIndex].key, emptyKey) != 0)
    {
        colCount++;
        hashIndex -= probeDec;
        if (hashIndex < 0)
            hashIndex = hashIndex + TABLESIZE;
    }

    strcpy(hashTable[hashIndex].key, key); // Store key in hash table
    hashTable[hashIndex].data = data;     // Store data
    return colCount;                      // Return number of collisions
}

int hash_methods::hash_1(const char key[]) //Base 26, but 57 instead...
{
    int index = 0;
    for (int i = 0; i < KEYSIZE; i++)
    {
        index += ((key[i] - 'A' + 1) * pow(57, 3 - i));
    }
    return index % TABLESIZE;
}


int hash_methods::hash_2(const char key[]) //Folding
{
   // cout << "hash_2" << endl;
    int index;
    index = ((key[0] - 'A' + 1) * (key[1] - 'A' + 1) + (key[2] - 'A' + 1) * (key[3] - 'A' + 1));
    return index % TABLESIZE;
}

int hash_methods::hash_3(const char key[]) //This one is bad, but is now different. //Middle squaring I think? I lost track.
{
    int index = 0;
    for(int i = 0; i < KEYSIZE; i++)
    {
        index += (pow(key[i], 2) + (key[1] - 'A' + 1) * (key[2] - 'A' + 1)) * 57;
    }

    return index % TABLESIZE;
}

int hash_methods::probeDec_1(const char key[])
{
    return 1;
}

unsigned int hash_methods::probeDec_2(const char key[])//Stack is a life saver.
{
    unsigned int a = 378551;
    unsigned int b = 63689;
    unsigned int index = 0;

    for(int i = 0; i < KEYSIZE; i++)
    {
        index = index * a + key[i];
        a = a * b;
    }

    return index % TABLESIZE + 1;
}

unsigned long hash_methods::probeDec_3(const char key[]) //djb2
{
    unsigned long index = 5381;
    int c;

    while (c = *key++)
        index = ((index << 5) + index) + c; /* hash * 33 + c */

    return index % TABLESIZE;
}


int main()
{
    int i, hashNum, dHashNum, count;

    const char *dataFile = "P4DATA.TXT";
    ifstream *inFile;
    hash_methods T;
    char line[64];
    char key[5];
    char data;

    for (hashNum = 0; hashNum < 3; hashNum++)
    {
        for (dHashNum = 0; dHashNum < 3; dHashNum++)
        {
            inFile = new ifstream();
            inFile->open(dataFile, ifstream::in);

            if (!inFile->is_open())
            {
                cout << "Unable to open file." << endl;
                return 0;
            }

            count = 0;

            for (int i = 0; i < 50; i++)
            {
                inFile->getline(line, 64, '\n');
                sscanf(line, "%s %c", key, &data); // Read key and data
                count += T.hashInsert(key, data, hashNum, dHashNum);
            }

            //===========================================================================
            // /* --- Snippet 3: This code shows how to create a diagram of the
            // results of a single test using one hash function and one double hash function. 
            // The resulting diagram looks similar to the sample below with '|' representing a 
            // slot where a key hashed or double hashed to and '-' representing an empty 
            // slot:
            // ||-||||---|||-|-||||||||-----||-|-||---||||--|-|||...etc. --- */

            cout << "Testing hash function " << hashNum + 1 
                << " using double hash " << dHashNum + 1 << ".\n";
            cout << "Total collisions = " << count + 1 << ".\n";

            // Show the form of the array
            for (int i = 0; i < 100; i++) 
            {
                if (strcmp(T.hashTable[i].key, "----")) { // strcmp gives a non-zero (true) result if Key is NOT the EMPTYKEY
                    cout << "|"; // Indicate an entry at this location
                } else {
                    cout << "-"; // Indicate no entry at this location
                }
            }
            for (int i = 0; i < 100; i++)
            {
                strcpy(T.hashTable[i].key, "----"); // Initialize with emptyKey
                T.hashTable[i].data = 0;
            }
            cout << "\n\n";


            inFile->close();
            delete inFile;
        }
    }

    return 0;
}
