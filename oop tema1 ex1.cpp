#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ukrainian");

    double a, b;

 
    int var = 1;
    double x = 0.48 * var;
    double y = 0.47 * var;
    double z = -1.32 * var;

    b = x * ((y + atan(pow(fabs(x * x + z), 0.1))) /
        (3.0 / x + pow(y + z, 3)) +
        y * exp(-(x + z) / (y + z)));

    a = (pow(sqrt(fabs(x * x - z)), 0.3) -
        cbrt(fabs(y + 2 * b))) /
        (1 + (x / 1.0) + (pow(y, 2) / 2.0) + (pow(z, 3) / 6.0));

 
    cout << "Результати для одного значення:\n";
    cout << "x = " << x << "\n";
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n\n";

 
    y = 0.47;
    z = -1.32;
    double xp = -1.0;
    double xk = 1.0;
    double dx = 0.2;

    cout << "Результати табулювання:\n";

    for (double xt = xp; xt <= xk; xt += dx)
    {
        b = xt * ((y + atan(pow(fabs(xt * xt + z), 0.1))) /
            (3.0 / xt + pow(y + z, 3)) +
            y * exp(-(xt + z) / (y + z)));

        a = (pow(sqrt(fabs(xt * xt - z)), 0.3) -
            cbrt(fabs(y + 2 * b))) /
            (1 + xt + (pow(y, 2) / 2.0) + (pow(z, 3) / 6.0));

        cout << "x = " << xt << "   "
            << "a = " << a << "   "
            << "b = " << b << "\n";
    }

    return 0;
}
