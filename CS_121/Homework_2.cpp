// #include <iostream> //something included in every C++ program
// #include <string> //allows strings to be utilized instead of only single characters
// using namespace std; //using this negates the need to place it everywhere.

// int main()//initializes the functions and also assigns an integer value to the program.
// {
//     int i = 1;//intiializes the variable. Can be done without initializing a number first, but will start at 0.
//     while (i < 11)//sets the condition for starting the while loop.
//     {
//         cout << i << endl;//outputs the number.
//         i++;//itierates the variable, increasing its value.
//     }
//     cout << "The End" << endl;//outputs text

//     int x = 5;
//     do//activates the loop.
//     {
//         cout << "X is less than 5!" << endl;
//         x++;
//     }
//     while (x < 5);//despite x starting off as equal to 5, it will print "X is less than 5!" atleast one time. If the condition is x > 5, it will be infinite.

//     return 0;//returns an integer value of 0. Should something go wrong in the program, the value will be different from 0 and will not complete.
// }


// #include <iostream> //something included in every C++ program
// using namespace std; //using this negates the need to place it everywhere.


// int introduction(){//establishes the functions data type and the name.
//     cout << "Hello there...\n";//outputs text
//     cout << "General Kenobi! \n";//outputs text

//     return 0;
// }

// int main()//main function
// {
//     introduction();//calls the functon previously established

//     return 0;//return value indicating succesdsful completion.
// } 


// #include <iostream>
// #include <string> 
// using namespace std;

// int main()
// {
//     string cars[] = {"Corvette", "Ford", "Mazda", "Lexus"};//establishes the array type(string values), names the array(cars), 
//                                                            //determines length of the array(unspecified) and finally details the array
//     cout << cars[2] << endl;
//     return 0;
// }






#include <iostream>
using namespace std;

enum day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main()
{
    day today;
    today = Friday;
    switch(today)
    {
        case Sunday: cout << "It is Sunday" << endl;
            break; 
        case Monday: cout << "It is Monday" << endl;
            break;
        case Tuesday: cout << "It is Tuesday" << endl;
            break;
        case Wednesday: cout << "It is Wednesday" << endl;
            break;
        case Thursday: cout << "It is Thursday" << endl;
            break;
        case Friday: cout << "TGI Fridays!" << endl;
            break;
        case Saturday: cout << "It is Saturday." << endl;
            break;
        default: cout << "That isn't a day!" << endl;
    }

    return 0;
}