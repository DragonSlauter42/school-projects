/*
    Class: CS 214-02 5.5 Programming Assignment
    File: HTyler_5.5.cpp
    Name: Hunter Tyler
    Description: Programming Assingment 5.5 Part A
    Date Started: 4/2/2025 Date Finished: 4/4/2025

    I attest that this program is entirely my own work.
*/

#include <iostream> //cout, cin, etc...
#include <cmath> //math equations for free
#include <iomanip> //for outputting into table format.
using namespace std; //Cause I am lazy.

double logN(double time, double n); //Use one function for all 3; main() should just call the function 3 times, each with a different value.
double n(double time, double n);
double nLogN(double time, double n);                    //These are the functions to use for the project.
double nPower2(double time, double n);                  //These are the declarations
double nPower3(double time, double n);
double nFactorial(double time, double n);
double twoPowerN(double time, double n);

/////////////////////////////////////////////////////////////////////
int main()
{
    double d_CalculationTime; //time for each calculation; multiplied by whatever n becomes //0.0001 for testing
    double d_LowIteration; //Lowest value n // 10 for testing
    double d_MidIteration; //Middle value n // 50 for testing
    double d_HighIteration; //Highest value n //100 for testing
    double d_Table[7][3]; //stores each functions value for troducing the table alter on. 7 functions, each with 3 calculations.

    cout << "Please input the time in seconds for 1 calculation: ";                         //Just for the inputs. Sets up the remainder of the project.
    cin >> d_CalculationTime;
    cout << "Please input the number of iterations each calculation will undergo" << endl;
    cout << "Low Count: ";
    cin >> d_LowIteration;
    cout << "Mid Count: ";
    cin >> d_MidIteration;
    cout << "High Count: ";
    cin >> d_HighIteration;

    for(int i = 0; i < 7; i++)//Assigns each functions value //I figured out how to do a 2d array for loop traversal below. I just didn't fix this one.
    {
        if(i == 0)//logN
        {
            d_Table[0][0] = logN(d_CalculationTime, d_LowIteration);        //d_Table[x][y] chooses the element on that rug and calls the function below with the parameters given in.
            d_Table[0][1] = logN(d_CalculationTime, d_MidIteration);
            d_Table[0][2] = logN(d_CalculationTime, d_HighIteration);
            
        }else if(i == 1)//n
        {
            d_Table[1][0] = n(d_CalculationTime, d_LowIteration);
            d_Table[1][1] = n(d_CalculationTime, d_MidIteration);
            d_Table[1][2] = n(d_CalculationTime, d_HighIteration);

        }else if(i == 2)//nLogN
        {
            d_Table[2][0] = nLogN(d_CalculationTime, d_LowIteration);
            d_Table[2][1] = nLogN(d_CalculationTime, d_MidIteration);
            d_Table[2][2] = nLogN(d_CalculationTime, d_HighIteration);

        }else if(i == 3)//nPower2
        {
            d_Table[3][0] = nPower2(d_CalculationTime, d_LowIteration);
            d_Table[3][1] = nPower2(d_CalculationTime, d_MidIteration);
            d_Table[3][2] = nPower2(d_CalculationTime, d_HighIteration);
            
        }else if(i == 4)//nPower3
        {
            d_Table[4][0] = nPower3(d_CalculationTime, d_LowIteration);
            d_Table[4][1] = nPower3(d_CalculationTime, d_MidIteration);
            d_Table[4][2] = nPower3(d_CalculationTime, d_HighIteration);

        }else if(i == 5)//nFactorial
        {
                d_Table[5][0] = nFactorial(d_CalculationTime, d_LowIteration);
                d_Table[5][1] = nFactorial(d_CalculationTime, d_MidIteration);
                d_Table[5][2] = nFactorial(d_CalculationTime, d_HighIteration);

        }else//twoPowerN
        {
            d_Table[6][0] = twoPowerN(d_CalculationTime, d_LowIteration);
            d_Table[6][1] = twoPowerN(d_CalculationTime, d_MidIteration);
            d_Table[6][2] = twoPowerN(d_CalculationTime, d_HighIteration);

        }

    }

    cout << endl; //This is me printing the table. It was a lot prettier, but you wanted a table, so here we are.
    cout << endl;
    cout << setw(17) << left << "Function " << setw(15) << " Low Iterations " << setw(12) << " Medium Iterations " << setw(2) << " "<< setw(21) << " High Iterations " << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;;
    cout << right;
    for(int x = 0; x < 7;x++)
    {
        switch(x) //Determines which functions to print from.
        {
            case 0:
            cout << setw(12) << "Log2(n):  ";
            break;
            
            case 1:
            cout << setw(12) << "n:        ";
            break;

            case 2:
            cout << setw(12) << "nLog2(n): ";
            break;

            case 3:
            cout << setw(12) << "n^2:      ";
            break;

            case 4:
            cout << setw(12) << "n^3:      ";
            break;

            case 5:
            cout << setw(12) << "n!:       ";
            break;

            case 6:
            cout << setw(12) << "2^n:      ";
            break;
        }
        for(int y = 0; y < 3;y++) //60 minute, 3600hour, 86400 day, 31536000 a year, 3153600000 a century, 3153600000000 a 1,000 centuries
        {
            if(d_Table[x][y] >= 60 && d_Table[x][y] < 3600)
            {
                cout << setw(12) << d_Table[x][y] / 60 << " Minutes ";
            }else if(d_Table[x][y] >= 3600 && d_Table[x][y] < 86400)
            {
                cout << setw(14) << d_Table[x][y] / 3600 << " Hours ";
            }else if(d_Table[x][y] >= 86400 && d_Table[x][y] < 31536000)
            {
                cout << setw(15) << d_Table[x][y] / 86400 << " Days ";
            }else if(d_Table[x][y] >= 31536000 && d_Table[x][y] < 3153600000)
            {
                cout << setw(14) << d_Table[x][y] / 31536000 << " Years ";
            }else if(d_Table[x][y] >= 3153600000 && d_Table[x][y] < 3153600000000)
            {
                cout << setw(10) << d_Table[x][y] / 3153600000 << " Centuries ";
            }else if(d_Table[x][y] >= 3153600000000)
            {
                cout << setw(29) << "Greater than 1,000 Centuries";
            }else
            {
                cout << setw(12) << d_Table[x][y] << " Seconds ";
            }

            
        }
        cout << endl;
    }
    
    return 0;
}

/////////////////////////////////////////////////////////////////////Function/method definitons.
double logN(double time, double n)
{
    double logN = time*log2(n);
    return logN;
}

double n(double time, double n)                                //cmath is awesome. Everything except the facotiralk was already made.
{
    double constant = time*n;
    return constant;
}

double nLogN(double time, double n)
{
    double nLogN =  time*(n*log2(n));
    return nLogN;
}

double nPower2(double time, double n)
{
    double nPower2 = time*(pow(n, 2));
    return nPower2;
}

double nPower3(double time, double n)
{
    double nPower3 = time*(pow(n, 3));
    return nPower3;
}

double nFactorial(double time, double number)   //I would have done something more, but you said to assume the correct inputs.
{
    double factorial = 1;
        if(number <= 1)
        {
            factorial = 1;
            return time*factorial;
        }else
        {
            for(int i = 1; i <= number; ++i)
            {
                factorial *= i;
            }
        }
        return time*factorial;
}

double twoPowerN(double time, double n)
{
    double twoPowerN = time*(pow(2, n));
    return twoPowerN;
}