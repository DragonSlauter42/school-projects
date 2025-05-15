//Hunter_Tyler_OOP_Practice

// #include <iostream>

// class human
// {
//     public:
//         std::string name;
//         std::string occupation;
//         int age;
        
//         void eat(std::string food)
//         {
//             std::cout << name <<" is eating " << food << " right now.\n";
//         }
//         void drink(std::string beverage)
//         {
//             std::cout << name <<" is drinking " << beverage << " right now.\n";
//         }
//         void sleep()
//         {
//             std::cout << name <<" is sleeping right now.\n";
//         }
// };

// int main()
// {
//     human human1;
//     human1.name = "Adam";
//     human1.occupation = "Farmer";
//     human1.age = 33;
//     human1.eat("pizza");

//     return 0;
// }


// #include <iostream>

// class car
// {
//     public:
//         std::string make;
//         std::string model;
//         std::string color;
//         int year;

//         car(std::string make, std::string model, std::string color, int year)
//         {
//             this->make = make;
//             this->model = model;
//             this->color = color;
//             this->year = year;
//         }

//         void printCar()
//         {
//             std::cout << "*************************\n";
//             std::cout << make << "\n";
//             std::cout << model << "\n";
//             std::cout << color << "\n";
//             std::cout << year << "\n";
//             std::cout << "*************************\n";
//         }
// };

// int main()
// {
//     car car1("Toyota", "Supra", "Blue", 2023);
//     car car2("Pontiac", "Firebird", "Black", 1976);

//     car1.printCar();
//     car2.printCar();
    

//     return 0;
// }

// #include <iostream>

// class dog
// {
//     public:
//         std::string name;
//         std::string breed;
//         bool goodboi = true;
//         int age;

//         dog(std::string name, std::string breed, int age)
//         {
//             this->name = name;
//             this->breed = breed;
//             this->age = age;
//         }

//         void printDog()
//         {
//             std::cout << "*************************\n";
//             std::cout << name << "\n";
//             std::cout << breed << "\n";
//             std::cout << "Whose a good boy!" << "\n";
//             std::cout << age << "\n";
//             std::cout << "*************************\n";
//         }
// };

// int main()
// {
//     dog dog1("Brutus", "Rotweiler", 4);
//     dog dog2("Scrappy", "Mixed", 2);

//     dog1.printDog();
//     dog2.printDog();
    

//     return 0;
// }


#include <iostream>
#include <fstream>

int main()
{
        // std::fstream testFile;
        // testFile.open("My_File.txt", std::ios::out);
        // testFile <<"This is a test. Please Work.";
        // for(int i = 1; i < 100; i++)
        // {
        //     testFile << "Hello There..." << i<< "\n";
        // }
for(int i =0; i < 10; i++)
{
    std::cout << i << "\n";
}

    return 0;
}

