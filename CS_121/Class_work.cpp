//Hunter Tyler
// Classwork 2/15/2024
#include <iostream>
#include <string>
using namespace std;

int main()
{

    string sentence = "Hello There,";
    string sen = "General Kenobi";

    cout << sentence << endl; 
    sen.insert(13, 10, 'i');

    cout << sen << endl;

    return 0;
}