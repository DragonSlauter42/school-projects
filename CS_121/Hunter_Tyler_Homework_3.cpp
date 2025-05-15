//Hunter_Tyler_Homework_3

#include <iostream>
int sumOfNumbers(int num);
int fibonacci(int num);

int main()
{
    
    int totalDigits = 10;
    int maxSequence = 5;
    std::cout << "The first 10 digits of the Fibonacci Sequence: \n";
    for(int i = 0; i < totalDigits; i++)
    {
        std::cout << fibonacci(i) << "\n";
    }
    
    std::cout << "A sequential addtion for 5 digits: \n";
    for(int x =  1; x <= maxSequence; x++)
    {
        std::cout << sumOfNumbers(x) << "\n";
    }
    return 0;
}

int sumOfNumbers(int num) 
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return num + sumOfNumbers(num - 1);
    }
}

int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    else 
    {
        return fibonacci(num - 1) + fibonacci(num-2);
    }
    
}

