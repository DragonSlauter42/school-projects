//Hunter_Tyler_Pointer_Practice
#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    char *pGrades = NULL;
    int size;

    cout << "Please input the numnber of grades.";
    cin >> size;

    pGrades = new char[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter letter grade for #" << i + 1 << ":";
        cin >> pGrades[i];
        while(isdigit(pGrades[i]))
        {
            cout << "Please input a letter grade";
            cin >> pGrades[i];
        }
    }
    for(int i = 0; i < size; i++)
    {
        cout << pGrades[i] << " ";
    }

    delete pGrades;

    return 0;
}