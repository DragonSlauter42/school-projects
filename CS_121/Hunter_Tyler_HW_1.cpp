//Hunter Tyler
//Homework 1: Temperature Converter Program

#include <iostream>
using namespace std; 

int main()
{
    double Kelvin; //Initialized the variable, so it wouldn't be a 0.
    cout << "Please input the intial Kelvin Temperature."<< endl;
    cin >> Kelvin; //Has the user input the temperature.
    
    double Celsius = Kelvin - 273.15; //Had a problem with kelvin being set to 0 if I didn't put this line here.
    cout << "The Celsius temperature is: " << Celsius << endl;
    double Fahrenheit = 1.8*Celsius + 32;
    cout << "The Fahrenheit temperature is: " << Fahrenheit << endl;

    return 0;
}