#include <iostream>
#include <cmath>
using namespace std;

double nFactorial(double);

int main()
{
    cout << "The factorial of 5 is: " << nFactorial(5) << endl;


    return 0;
}

double nFactorial(double number)
{
    double factorial = 1;
        if(number <= 1)
        {
            return factorial = 1;
        }else
        {
            for(int i = 1; i <= number; ++i)
            {
                factorial *= i;
            }
        }
        return factorial;
}