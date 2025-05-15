//Array_Practice_3-22-2024
//Hunter Tyler

// #include <iostream>
// using namespace std;

// double averageGrades(double grades[], int size);

// int main()
// {
//     string cars[] = {"Ford", "BMW", "Volkswagon", "Toyota", "Lexis", "Audi", "Honda", "Cadiliac", "Ferrari", "Lamborgini", "Alfa Romero", "Dodge", "Bentley", "Tesla", "Mazda", "Maserati", "Subaru"};

//     for(int i = 0; i < sizeof(cars); i++) //This or the for loop below
//     {
//         cout << cars[i] << "\n";
//     }
//     for(string car : cars)
//     {
//         cout << car << "\n";
//     }


//     // double grades[] = {88.88, 98.72, 95.46, 91.34, 100};
//     // int size = (sizeof(grades)/sizeof(double));
//     // double average = averageGrades(grades, size);
    
//     return 0;
// }

// double averageGrades(double grades[], int size)
// {
//     double total;
//     double average;
//     for(int i = 0; i < size; i++)
//     {
//         total += grades[i];
//         average = total/size;
//     }
//     cout << average << "\n";
//     return average;
// }


////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// using namespace std;

// int searchArray(string array[], int size, string element);

// int main()
// {
//     string cars[] = {"Ford", "BMW", "Volkswagon", "Toyota", "Lexis", "Audi", "Honda", "Cadiliac", "Ferrari", "Lamborgini", "Alfa Romero", "Dodge", "Bentley", "Tesla", "Mazda", "Maserati", "Subaru"};
//     int arraySize = sizeof(cars)/sizeof(cars[0]);
//     int index;
//     string myCar;

//     cout << "Enter the car you would like to search for." << "\n";
//     getline(cin, myCar);

//     index = searchArray(cars, arraySize, myCar);

//     if(index != -1)
//     {
//         cout << "The car you were searching for is inside the array.\n";
//         cout << "It is is at index: " << index << ".\n";
//     }else
//         {
//             cout << "The number you were searching for is not inside the array. \n";
//         }
    
//     return 0;
// }

// int searchArray(string array[], int size, string element)
// {
//     for(int i = 0; i < size; i++)
//     {
//         if(array[i] == element)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

// #include <iostream>
// using namespace std;

// void bubblesort(int array[], int size);

// int main()
// {
//     int numberList[] = {10,1,9,2,8,3,7,4,6,5};
//     int arraySize = sizeof(numberList)/sizeof(numberList[0]);

//     bubblesort(numberList, arraySize);
//     for(int element:numberList)
//     {
//         cout << element << " ";
//     }


//     return 0;
// }

// void bubblesort(int array[], int size)
// {
//     int temp;
//     for(int i = 0; i < size-1; i++)
//         for(int j = 0; j < size-i-1; j++)
//         {
//             if(array[j] > array[j+1])
//             {
//                 temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
//         }
// }


////////////////////////////////////////////////////////////////////////////////////////////////