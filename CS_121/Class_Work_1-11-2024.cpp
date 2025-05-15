#include <iostream>
using namespace std;

// int main()
// {
//     double Length;
//     double Width;
//     double Perimeter;
//     double Area;

//     Length = 6.0;
//     Width  = 4.0;
//     Perimeter = (Length * 2)+(Width*2);
//     Area = Length*Width;

//     cout << "The perimeter is: " << Perimeter << endl << "The area is: " << Area ;

//     return 0;
// }


int main()
{
    double Radius = 5;
    double Pi = 3.14;
    double area_of_circle = Pi*(Radius * Radius);
    double cirumfrence = 2*Pi*Radius;
    cout << "The circumfrence is: " << cirumfrence<< endl;
    cout << area_of_circle;


    return 0;
}