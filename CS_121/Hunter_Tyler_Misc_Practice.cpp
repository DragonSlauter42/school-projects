//////////////////////////////Hunter_Tyler_Misc_Practice
// #include <iostream>

// template <typename T, typename U>
// auto max(T x, U y)
// {
//     return (x > y) ? x:y;
// }

// int main()
// {
//     std:: cout << max(,'B');

//     return 0;
// }

// #include <iostream>

// struct student
// {
//     std::string name;
//     int idNumber;
//     int gradeLevel;
//     bool enrolled;
//     double gpa;
// };

// int main()
// {
//     student student1;
//     student1.name = "Spongebob";
//     student1.gradeLevel = 2;
//     student1.enrolled = true;
//     student1.gpa = 3.5;

//     switch(student1.gradeLevel)
//     {
//         case 1:
//             std::cout << student1.name << " is a Freshman";
//             break;
//         case 2:
//             std::cout << student1.name << " is a Sophmore";
//             break;
//         case 3:
//             std::cout << student1.name << " is a Junior";
//             break;
//         case 4:
//             std::cout << student1.name << " is a Senior";
//             break;
//         default:
//             std::cout << "Wrong Input.";
//             break;
//     }
//     return 0;
// }

// #include <iostream>

// struct car 
// {
//     std::string model;
//     int year;
//     std::string color;
// };

// void printCar(car car);

// int main()
// {
//     car car1;
//     car car2;

//     std::cout << "Please input car model.\n";
//     std::getline(std::cin, car1.model);

//     std::cout << "Please input the year it was made.\n";
//     std::cin >> car1.year;

//     std::cout << "Please input the color of the car.\n";
//     std::cin >> car1.color;

//     printCar(car1);

//     return 0;
// }

// void printCar(car car)
// {
//     std::cout <<"The car is a " << car.color << " " << car.model <<" and it was made in " << car.year << ".\n";
// }
