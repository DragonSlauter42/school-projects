//Hunter Tyler_Rock_Paper_Scissors
//C++ Rock Paper Scissors Prohect following Bro Code's Example

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void decideVictor(char player, char computer);

int main()
{
    char player;
    char computer;

    player = getUserChoice();
    showChoice(player);

    computer = getComputerChoice();

    decideVictor(player, computer);

    return 0;
}

char getUserChoice()
{
    char playerChoice;
    cout << "Rock Paper Scissors Game\n";
    cout << "**********\n";
    do{
        cout << "Please choose r for Rock, p for Paper and S for Scissors.\n";
        cin >> playerChoice;
    }while( playerChoice != 'r' && playerChoice != 'p' && playerChoice != 's');

    return playerChoice;
}

char getComputerChoice()
{
    srand(time(0));
    int cChoice;
    cChoice = rand()%3;
    switch(cChoice)
    {
        case 0:
            cout << "The computer's choice is Rock.\n";
            cChoice = 'r';
            break;

        case 1:
            cout << "The computer's choice is Paper.\n";
            cChoice = 'p';
            break;

        case 2:
            cout << "The computer's choice is Scissors.\n";
            cChoice = 's';
            break;
    }


    return cChoice;
}

void showChoice(char choice)
{
    switch(choice)
    {
        case 'r':
            cout << "You have chosen Rock.\n";
            break;

        case 'p':
            cout << "You have chosen Paper.\n";
            break;

        case 's':
            cout << "You have chosen Scissors.\n";
            break;

    }

}

void decideVictor(char player, char computer)
{
    switch(player)
    {
        case 'r':
            if(computer == 'r')
            {
                cout << "It's a Draw.\n";
                break;
            }
            if(computer == 'p')
            {
                cout << "You lose.\n";
                break;
            }
            if(computer == 's')
            {
                cout << "You win!\n";
                break;
            }
            break;

        case 'p':
            if(computer == 'p')
            {
                cout << "It's a Draw.\n";
                break;
            }
            if(computer == 's')
            {
                cout << "You lose.\n";
                break;
            }
            if(computer == 'r')
            {
                cout << "You win!\n";
                break;
            }
            break;
        
        case 's':
            if(computer == 's')
            {
                cout << "It's a Draw.\n";
                break;
            }
            if(computer == 'r')
            {
                cout << "You lose.\n";
                break;
            }
            if(computer == 'p')
            {
                cout << "You win!\n";
                break;
            }
            break;

    }
}