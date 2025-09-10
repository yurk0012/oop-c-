#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ukrainian");

    int var = 1;
    double x = 0.48 * var;
    double y = 0.47 * var;
    double z = -1.32 * var;
    double b;
    double a;


    b = x * ((y + atan(pow(fabs(x * x + z), 0.1))) / (3.0 / x + pow(y + z, 3)) + y * exp(-(x + z) / (y + z)));

    a = (pow(sqrt(fabs(x * x - z)), 0.3) - cbrt(fabs(y + 2 * b))) / (1 + (x / 1.0) + (pow(y, 2) / 2.0) + (pow(z, 3) / 6.0));


  

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}